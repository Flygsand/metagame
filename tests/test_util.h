#ifndef _METAGAME_TESTS_TEST_UTIL_H_
#define _METAGAME_TESTS_TEST_UTIL_H_

#include "../src/util.h"
#include <check.h>
#include <string.h>
#include <stdio.h>
#include <gcrypt.h>

START_TEST (test_mg_util_ltrim)
{

  fail_if(strcmp("Foo bar  ", mg_util_ltrim("   Foo bar  ")) != 0);

}
END_TEST

START_TEST (test_mg_util_rtrim)
{

  char* str = strdup("   Foo bar  ");
  fail_if(strcmp("   Foo bar", mg_util_rtrim(str)) != 0);

}
END_TEST

START_TEST (test_mg_util_trim)
{

  char* str = strdup("   Foo bar  ");
  fail_if(strcmp("Foo bar", mg_util_trim(str)) != 0);

}
END_TEST

START_TEST (test_mg_util_monospace)
{

  char* str = strdup("  Foo   bar baz ");
  fail_if(strcmp(" Foo bar baz ", mg_util_monospace(str)) != 0);

}
END_TEST

START_TEST (test_mg_util_to_uint16)
{

  char bytes[] = {0x30, 0xe5};
  fail_if(0x30e5 != mg_util_to_uint16(bytes));

}
END_TEST

START_TEST (test_mg_util_to_uint32)
{

  char bytes[] = {0x42, 0xfa, 0x00, 0x60};
  fail_if(0x42fa0060 != mg_util_to_uint32(bytes));

}
END_TEST

START_TEST (test_mg_util_hexdigest)
{

  char bytes[] = {84, 167, 126, 216, 153, 134, 131, 108, 100, 115, 244, 50, 103, 176, 149, 236, 125, 73, 170, 38, 59, 95, 194, 75, 56};
  fail_if(strcmp("60e85dc83ecb630ccc3aeebe62167f0a27eb183d", mg_util_hexdigest(GCRY_MD_SHA1, bytes, 25)) != 0);

}
END_TEST

START_TEST (test_mg_util_to_hex)
{

  char bytes[] = {0x2a, 0x00, 0x80, 0xff};
  fail_if(strcmp("2a0080ff", mg_util_to_hex(bytes, 4)) != 0);

}
END_TEST

TCase* test_util(void) {
  TCase* tc = tcase_create("test_util");
  tcase_add_test(tc, test_mg_util_ltrim);
  tcase_add_test(tc, test_mg_util_rtrim);
  tcase_add_test(tc, test_mg_util_trim);
  tcase_add_test(tc, test_mg_util_hexdigest);
  tcase_add_test(tc, test_mg_util_to_hex);
  tcase_add_test(tc, test_mg_util_to_uint16);
  tcase_add_test(tc, test_mg_util_to_uint32);
  tcase_add_test(tc, test_mg_util_monospace);
  
  return tc;
}

#endif /* _METAGAME_TESTS_TEST_MG_UTIL_H_ */
