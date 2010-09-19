#ifndef _METAGAME_TESTS_TEST_METAGAME_H_
#define _METAGAME_TESTS_TEST_METAGAME_H_

#include "../src/metagame.h"
#include <check.h>

START_TEST (test_read_nes_with_header)
{

  mg_info* info = mg_read_path("resources/smb");
  fail_if(strcmp("Super Mario Bros  (Vimm's Lair - http://vimm.net)", info->title) != 0);
  fail_if(strcmp("NES", info->platform) != 0);
  fail_if(strcmp("77fb3f0c2d217962699ca080c2171e65a556e98c", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST

START_TEST (test_read_nes_without_header)
{

  mg_info* info = mg_read_path("resources/mm2.nes");
  fail_if(NULL != info->title);
  fail_if(strcmp("NES", info->platform) != 0);
  fail_if(strcmp("a9daff94a800625a5d10345c3a3c8952fb57cf87", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST

START_TEST (test_read_snes_lorom)
{

  mg_info* info = mg_read_path("resources/sc4.smc");
  fail_if(strcmp("SUPER CASTLEVANIA 4", info->title) != 0);
  fail_if(strcmp("SNES", info->platform) != 0);
  fail_if(strcmp("554e22380e25a5e4d55f8ddf5730bba9af9a4c39", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST

START_TEST (test_read_snes_hirom)
{

  mg_info* info = mg_read_path("resources/smk.SMC");
  fail_if(strcmp("SUPER MARIO KART", info->title) != 0);
  fail_if(strcmp("SNES", info->platform) != 0);
  fail_if(strcmp("47e103d8398cf5b7cbb42b95df3a3c270691163b", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST


START_TEST (test_read_genesis_raw)
{

  mg_info* info = mg_read_path("resources/sonic3.bin");
  fail_if(strcmp("SONIC THE HEDGEHOG 3", info->title) != 0);
  fail_if(strcmp("Genesis/Mega Drive", info->platform) != 0);
  fail_if(strcmp("7b98b21b7274233e962132bc22a7ccdf548c0ddb", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST

START_TEST (test_read_genesis_smd)
{

  mg_info* info = mg_read_path("resources/sonic3.smd");
  fail_if(strcmp("SONIC THE HEDGEHOG 3", info->title) != 0);
  fail_if(strcmp("Genesis/Mega Drive", info->platform) != 0);
  fail_if(strcmp("f6d76027eab012ab8d546caf23dc496ffd7ce7a6", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST

START_TEST (test_read_genesis_md)
{

  mg_info* info = mg_read_path("resources/sonic3.md");
  fail_if(strcmp("SONIC THE HEDGEHOG 3", info->title) != 0);
  fail_if(strcmp("Genesis/Mega Drive", info->platform) != 0);
  fail_if(strcmp("42c1d364b50dd78d24438305c3cbd8a409786848", info->digest) != 0);
  
  mg_info_free(info);

}
END_TEST

START_TEST (test_read_random_crap)
{

  mg_info* info = mg_read_path("resources/random_crap");
  fail_if(info != NULL);

}
END_TEST

TCase* test_metagame(void) {
  TCase* tc = tcase_create("test_metagame");
  tcase_add_test(tc, test_read_nes_with_header);
  tcase_add_test(tc, test_read_nes_without_header);
  tcase_add_test(tc, test_read_snes_lorom);
  tcase_add_test(tc, test_read_snes_hirom);
  tcase_add_test(tc, test_read_genesis_raw);
  tcase_add_test(tc, test_read_genesis_smd);
  tcase_add_test(tc, test_read_genesis_md);
  tcase_add_test(tc, test_read_random_crap);
  
  return tc;
}

#endif /* _METAGAME_TESTS_TEST_METAGAME_H_ */
