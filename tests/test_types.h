#ifndef _METAGAME_TESTS_TEST_TYPES_H_
#define _METAGAME_TESTS_TEST_TYPES_H_

#include "../src/types.h"
#include <check.h>

START_TEST (test_mg_info_alloc)
{

  mg_info* info = mg_info_alloc();
  fail_if(info->title != NULL);
  fail_if(info->platform != NULL);
  fail_if(info->region != NULL);
  fail_if(info->digest != NULL);

  mg_info_free(info);

}
END_TEST

TCase* test_types(void) {
  TCase* tc = tcase_create("test_types");
  tcase_add_test(tc, test_mg_info_alloc);
  
  return tc;
}


#endif /* _METAGAME_TESTS_TEST_TYPES_H_ */
