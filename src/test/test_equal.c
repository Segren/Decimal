#include "test_runner.h"

#define TRUE 1
#define FALSE 0

START_TEST(test_equal_1) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_equal_2) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_3) {
  // -79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_4) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal dec2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(
    test_equal_5) {  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // 7922816251426433759354395033
  s21_decimal dec1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_6) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_equal_7) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 1.2297829382473034409
  s21_decimal dec2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_8) {
  // -1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_9) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_equal_10) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x11111111}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_11) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B00700}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_12) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal dec2 = {{0x1, 0x0, 0x0, 0x801C0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_13) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 0
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x0}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_14) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal dec2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_15) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal dec2 = {{0xA, 0x0, 0x0, 0x10000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_16) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x800E0000}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_equal_17) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0xFFFFFFFF}};

  uint8_t res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST

Suite *s21_equal_cases(void) {
  Suite *c = suite_create("s21_equal_cases");
  TCase *tc = tcase_create("s21_equal_tc");

  tcase_add_test(tc, test_equal_1);
  tcase_add_test(tc, test_equal_2);
  tcase_add_test(tc, test_equal_3);
  tcase_add_test(tc, test_equal_4);
  tcase_add_test(tc, test_equal_5);
  tcase_add_test(tc, test_equal_6);
  tcase_add_test(tc, test_equal_7);
  tcase_add_test(tc, test_equal_8);
  tcase_add_test(tc, test_equal_9);
  tcase_add_test(tc, test_equal_10);
  tcase_add_test(tc, test_equal_11);
  tcase_add_test(tc, test_equal_12);
  tcase_add_test(tc, test_equal_13);
  tcase_add_test(tc, test_equal_14);
  tcase_add_test(tc, test_equal_15);
  tcase_add_test(tc, test_equal_16);
  tcase_add_test(tc, test_equal_17);

  suite_add_tcase(c, tc);
  return c;
}
