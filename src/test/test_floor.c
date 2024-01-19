#include "test_runner.h"

#define TRUE 1
#define FALSE 0

START_TEST(test_floor_1) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_2) {
  // -79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_3) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x001B0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000005, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_4) {
  // -5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000006, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_5) {
  // -1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000002, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_6) {
  // 1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_7) {
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x11111111}};
  s21_decimal result;
  init_with_zero_decimal(&result);

  uint8_t flag = s21_floor(dec1, &result);
  ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_floor_8) {
  //  -0.0000000000000000000000000001
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_9) {
  //  -0
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_10) {
  //  0
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x00000000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_11) {
  //  -0.00000000000000
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_12) {
  //  1.0
  s21_decimal dec1 = {{0xA, 0x0, 0x0, 0x00010000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000001, 0x0, 0x0, 0x00000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

START_TEST(test_floor_13) {
  //  -1.0
  s21_decimal dec1 = {{0xA, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  init_with_zero_decimal(&result);
  s21_decimal dec2 = {{0x00000002, 0x0, 0x0, 0x80000000}};

  uint8_t flag = s21_floor(dec1, &result);
  uint8_t res = s21_is_equal(result, dec2);
  ck_assert_int_eq(flag, 0);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

Suite *s21_floor_cases(void) {
  Suite *c = suite_create("s21_floor_cases");
  TCase *tc = tcase_create("s21_floor_tc");

  tcase_add_test(tc, test_floor_1);
  tcase_add_test(tc, test_floor_2);
  tcase_add_test(tc, test_floor_3);
  tcase_add_test(tc, test_floor_4);
  tcase_add_test(tc, test_floor_5);
  tcase_add_test(tc, test_floor_6);
  tcase_add_test(tc, test_floor_7);
  tcase_add_test(tc, test_floor_8);
  tcase_add_test(tc, test_floor_9);
  tcase_add_test(tc, test_floor_10);
  tcase_add_test(tc, test_floor_11);
  tcase_add_test(tc, test_floor_12);
  tcase_add_test(tc, test_floor_13);

  suite_add_tcase(c, tc);
  return c;
}
