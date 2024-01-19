#include "test_runner.h"

START_TEST(test_round_1) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_2) {
  // -79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_3) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x001B0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000005, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_4) {
  // -5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000005, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_5) {
  // -1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_6) {
  // 1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_7) {
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x11111111}};
  s21_decimal result;
  init_with_zero_decimal(&result);

  uint8_t flag = s21_round(dec1, &result);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_round_8) {
  //  -0.0000000000000000000000000001
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000000, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_9) {
  //  -0
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_10) {
  //  0
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x00000000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_11) {
  //  -0.00000000000000
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_12) {
  //  1.0
  s21_decimal dec1 = {{0xA, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_13) {
  //  -1.0
  s21_decimal dec1 = {{0xA, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_14) {
  //  -15.674
  s21_decimal dec1 = {{0x00003D3A, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000010, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_15) {
  //  -1.5674
  s21_decimal dec1 = {{0x00003D3A, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000002, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_16) {
  //  -14.574
  s21_decimal dec1 = {{0x000038EE, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0000000F, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_17) {
  //  -14.5
  s21_decimal dec1 = {{0x00000091, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0000000F, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_round_18) {
  //  -15.5
  s21_decimal dec1 = {{0x0000009B, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000010, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_round(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

Suite *s21_round_cases(void) {
  Suite *c = suite_create("s21_round_cases");
  TCase *tc = tcase_create("s21_round_tc");

  tcase_add_test(tc, test_round_1);
  tcase_add_test(tc, test_round_2);
  tcase_add_test(tc, test_round_3);
  tcase_add_test(tc, test_round_4);
  tcase_add_test(tc, test_round_5);
  tcase_add_test(tc, test_round_6);
  tcase_add_test(tc, test_round_7);
  tcase_add_test(tc, test_round_8);
  tcase_add_test(tc, test_round_9);
  tcase_add_test(tc, test_round_10);
  tcase_add_test(tc, test_round_11);
  tcase_add_test(tc, test_round_12);
  tcase_add_test(tc, test_round_13);
  tcase_add_test(tc, test_round_14);
  tcase_add_test(tc, test_round_15);
  tcase_add_test(tc, test_round_16);
  tcase_add_test(tc, test_round_17);
  tcase_add_test(tc, test_round_18);

  suite_add_tcase(c, tc);
  return c;
}
