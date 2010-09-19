#include "genesis.h"

#include "../util.h"
#include <stdlib.h>
#include <string.h>

// TODO: minimum size of a ROM

int mg_genesis_contains_valid_header(const char* header);
void mg_genesis_deinterleave(char* bytes, size_t len);

mg_info* mg_genesis_parse(const char* data, size_t size) {
  char * copy = NULL;

  if (!mg_genesis_contains_valid_header(data)) {

    if (size % 16384 != 0) {
      copy = malloc(size - 512);
      memcpy(copy, data + 512, size - 512);
      mg_genesis_deinterleave(copy, 16384);
    } else {
      copy = malloc(size);
      memcpy(copy, data, size);
      mg_genesis_deinterleave(copy, size);
    }

    if (!mg_genesis_contains_valid_header(copy)) {
      free(copy);
      return NULL;
    } else {
      data = copy;
    }
  }

  char *title = malloc(49);
  strncpy(title, data + 0x150, 48);
  if (copy) free(copy);
  title[48] = '\0';
  mg_util_rtrim(mg_util_monospace(title));

  mg_info* info = mg_info_alloc();
  info->title = title;
  info->platform = strdup("Genesis/Mega Drive");
  
  return info;
}

int mg_genesis_contains_valid_header(const char* header) {
  return strncmp("SEGA MEGA DRIVE", header + 0x100, 16) == 0 ||
    strncmp("SEGA GENESIS    ", header + 0x100, 16) == 0;
}

void mg_genesis_deinterleave(char* bytes, size_t len) {
  char* deinterleaved = malloc(len);
  size_t middle = len/2;
  
  size_t i;
  for (i = 0; i < middle; i++) {
    deinterleaved[i*2+1] = bytes[i];
  }

  for (; i < len; i++) {
    deinterleaved[(i-middle)*2] = bytes[i];
  }

  memcpy(bytes, deinterleaved, len);
  free(deinterleaved);
}
