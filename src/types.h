#ifndef _METAGAME_TYPES_H_
#define _METAGAME_TYPES_H_

typedef struct {
  char* title;
  char* platform;
  char* region;
  char* digest;
} mg_info;

mg_info* mg_info_alloc(void);
void mg_info_free(mg_info* info);

#endif /* _METAGAME_TYPES_H_ */
