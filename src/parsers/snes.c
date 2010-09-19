#include "snes.h"

#include "../util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

// TODO: minimum size of a ROM

const char* mg_snes_header(const char* data, size_t size);
int mg_snes_contains_valid_checksum(const char* header);
int mg_snes_contains_lorom_makeup(const char* header);

mg_info* mg_snes_parse(const char* data, size_t size) {
  const char* header = mg_snes_header(data, size);
  if (header == NULL) return NULL;

  char *title = malloc(22);
  strncpy(title, header, 21);
  title[21] = '\0';
  mg_util_rtrim(title);

  mg_info* info = mg_info_alloc();
  info->title = title;
  info->platform = strdup("SNES");

  return info;
}

const char* mg_snes_header(const char* data, size_t size) {
  const int offset = size % 32768 != 0 ? 512 : 0;

  const char* header = data + 0x7fc0 + offset;
  if (size - (header - data) >= 64 && 
      mg_snes_contains_valid_checksum(header)) {
    return header; // either LoROM or interleaved HiROM
  }

  header = data + 0xffc0 + offset;
  if (size - (header - data) >= 64 && 
      mg_snes_contains_valid_checksum(header) &&
      !mg_snes_contains_lorom_makeup(header)) {
    return header; // HiROM
  }

  header = data + (size / 65536) + offset; // middle 32K block
  if (size - (header - data) >= 64 && 
      mg_snes_contains_valid_checksum(header) &&
      mg_snes_contains_lorom_makeup(header)) {
    return header; // interleaved LoROM
  }
      
  return NULL;
}

int mg_snes_contains_valid_checksum(const char* header) {
  return (mg_util_to_uint16(header+0x1c) ^ mg_util_to_uint16(header+0x1e)) == 0xffff;
}

int mg_snes_contains_lorom_makeup(const char* header) {
  return header[0x15] & 0xf % 2 == 0;
}
