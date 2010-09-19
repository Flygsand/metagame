#include "util.h"

#include <ctype.h>
#include <string.h>
#include <gcrypt.h>
#include <stdio.h>

char* mg_util_ltrim(char* s) {
  while(isspace(*s)) s++;
  return s;
}

char* mg_util_rtrim(char* s) {
  char* back = s + strlen(s);
  while(isspace(*--back));
  *(back+1) = '\0';
  return s;
}

char* mg_util_trim(char* s) {
  return mg_util_rtrim(mg_util_ltrim(s)); 
}

char* mg_util_monospace(char* s) {
  char c;
  char* ptr = s;
  char* out = ptr;
  while ((c = *s) != '\0') {
    if (isspace(c)) {
      while (*(++s) == c) { }
    } else {
      ++s;
    }

    *(ptr++) = c;
  }

  *ptr = '\0';

  return out;
}

long mg_util_fsize(FILE* file) {
  long oldpos = ftell(file);
  fseek(file, 0L, SEEK_END);
  long size = ftell(file);
  fseek(file, oldpos, SEEK_SET);

  return size;
}

uint16_t mg_util_to_uint16(const char* buf) {
  return ((buf[0] & 0xFF) << 8) + (buf[1] & 0xFF);
}

uint32_t mg_util_to_uint32(const char* buf) {
  return ((buf[0] & 0xFF) << 24) + ((buf[1] & 0xFF) << 16) +
    ((buf[2] & 0xFF) << 8) + (buf[3] & 0xFF);
}

char* mg_util_hexdigest(int algo, const char* bytes, size_t len) {
  size_t digest_len = gcry_md_get_algo_dlen(algo);
  char digest[digest_len];
  gcry_md_hash_buffer(algo, digest, bytes, len);

  return mg_util_to_hex(digest, digest_len);
}

char* mg_util_to_hex(const char* bytes, size_t len) {
  static const char digits[] = "0123456789abcdef";

  size_t hex_len = len*2 + 1;
  char* hex = malloc(hex_len);
  
  int i;
  for (i = 0; i < len; i++) {
    hex[i*2] = digits[(bytes[i] >> 4) & 0xF];
    hex[i*2+1] = digits[bytes[i] & 0x0F];
  }

  hex[hex_len - 1] = '\0';

  return hex;
}
