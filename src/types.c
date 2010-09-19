#include "types.h"

#include <stdlib.h>

mg_info* mg_info_alloc(void) {
  return calloc(1, sizeof(mg_info));
}

void mg_info_free(mg_info* info) {
  if (info == NULL) return;

  if (info->title) free(info->title);
  if (info->platform) free(info->platform);
  if (info->region) free(info->region);
  if (info->digest) free(info->digest);

  free(info);
}
