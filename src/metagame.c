#include "metagame.h"
#include "parsers/nes.h"
#include "parsers/snes.h"
#include "parsers/genesis.h"
#include "util.h"

#include <stdlib.h>
#include <gcrypt.h>

typedef mg_info* (*parser_func_ptr)(const char*, size_t);

static const parser_func_ptr parsers[] = {
  &mg_nes_parse,
  &mg_genesis_parse,
  &mg_snes_parse,
  NULL
};

mg_info* mg_read_path(const char* path) {
  FILE* file = fopen(path, "rb");
  if (file == NULL) return NULL;

  mg_info* info = mg_read_file(file);
  fclose(file);

  return info;
}

mg_info* mg_read_file(FILE* file) {
  long size = mg_util_fsize(file);

  if (size < 0) return NULL;
  
  char* data = malloc((size_t) size);
  size_t bytes_read;

  if ((bytes_read = fread(data, 1, size, file)) <= 0) { 
    free(data); 
    return NULL;
  }

  mg_info* info;

  int i = 0; 
  parser_func_ptr parse;
  while ((parse = parsers[i])  != NULL) {
    if ((info = (*parse)(data, bytes_read)) != NULL) {
      info->digest = mg_util_hexdigest(GCRY_MD_SHA1, data, bytes_read);
      free(data);
      return info;
    }

    ++i;
  }

  free(data);
  return NULL;
}
