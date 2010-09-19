#ifndef _METAGAME_PARSERS_GENESIS_H_
#define _METAGAME_PARSERS_GENESIS_H_

#include "../types.h"
#include <stddef.h>

mg_info* mg_genesis_parse(const char* data, size_t size);

#endif /* _METAGAME_PARSERS_GENESIS_H_ */
