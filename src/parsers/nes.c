#include "nes.h"

#include "../util.h"
#include <string.h>

// TODO: minimum size of a ROM

mg_info* mg_nes_parse(const char* data, size_t size) {
  if (strncmp("NES\x1a", data, 4)) return NULL;

  char* title = NULL;

  if (size % 8192 != 16) {
    title = malloc(129);
    strncpy(title, data + size - 128, 128);
    title[128] = '\0';
  }

  mg_info* info = mg_info_alloc();
  info->title = title;
  info->platform = strdup("NES");
  
  return info;
}
