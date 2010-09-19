#ifndef _METAGAME_UTIL_H_
#define _METAGAME_UTIL_H_

#include <stdio.h>
#include <stdint.h>

char* mg_util_ltrim(char* s);
char* mg_util_rtrim(char* s);
char* mg_util_trim(char* s);
char* mg_util_monospace(char* s);
long mg_util_fsize(FILE* file);
uint16_t mg_util_to_uint16(const char* buf);
uint32_t mg_util_to_uint32(const char* buf);
char* mg_util_hexdigest(int algo, const char* bytes, size_t len);
char* mg_util_to_hex(const char* bytes, size_t len);

#endif /* _METAGAME_UTIL_H_ */
