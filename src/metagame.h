#ifndef _METAGAME_METAGAME_H_
#define _METAGAME_METAGAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include <stdio.h>

mg_info* mg_read_path(const char* path);
mg_info* mg_read_file(FILE* file);

#ifdef __cplusplus
}
#endif

#endif /* _METAGAME_METAGAME_H_ */
