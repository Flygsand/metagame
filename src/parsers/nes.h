#ifndef _METAGAME_PARSERS_NES_H_
#define _METAGAME_PARSERS_NES_H_

#include "../types.h"
#include <stdlib.h>

mg_info* mg_nes_parse(const char* data, size_t size);

#endif /* _METAGAME_PARSERS_NES_H_ */
