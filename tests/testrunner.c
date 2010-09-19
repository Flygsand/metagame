#include <stdlib.h>
#include <check.h>

/* Tests */
#include "test_util.h"
#include "test_types.h"
#include "test_metagame.h"

Suite* all_tests(void) {
  Suite* s = suite_create("all_tests");
  suite_add_tcase(s, test_util());
  suite_add_tcase(s, test_types());
  suite_add_tcase(s, test_metagame());

  return s;
}

int main(void)
{
  int number_failed;
   SRunner *sr;
   sr = srunner_create(all_tests());
   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);

   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
