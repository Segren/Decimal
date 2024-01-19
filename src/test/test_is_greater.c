#include "test_runner.h"

// dec1 > dec2
START_TEST(test_is_greater_1) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_2) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_3) {
  // -79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_4) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal dec2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(
    test_is_greater_5) {  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // 7922816251426433759354395033
  s21_decimal dec1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_6) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_7) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 4490566.8091721474095862353
  s21_decimal dec2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);  //?????????????????????
}
END_TEST
START_TEST(test_is_greater_8) {
  // -1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_9) {
  // -1.2297829382473034409
  s21_decimal dec1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x80130000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_10) {
  // not correct
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x11111111}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_11) {
  // 4.3885962378068783573709698727 - ??????????????????
  s21_decimal dec1 = {{0x11111112, 0x11111011, 0x11111011, 0x1B0000}};
  // 5.281877500950955839569596690
  s21_decimal dec2 = {{0x11111012, 0x11111011, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_12) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal dec2 = {{0x1, 0x0, 0x0, 0x801C0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_13) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 0
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x0}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_14) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal dec2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_15) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal dec2 = {{0xA, 0x0, 0x0, 0x10000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_16) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x800E0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST
START_TEST(test_is_greater_17) {
  // 79228162514264337593543950335
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // not correct
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0xFFFFFFFF}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, FALSE);
}
END_TEST
START_TEST(test_is_greater_18) {
  // 5.281877500950955839569596690
  s21_decimal dec1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 4.388596269498143363076704910
  s21_decimal dec2 = {{0x11111112, 0x11111011, 0x11111111, 0x1B0000}};

  uint8_t res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, TRUE);
}
END_TEST

Suite *s21_is_greater_cases(void) {
  Suite *c = suite_create("s21_is_greater_cases");
  TCase *tc = tcase_create("s21_is_greater_tc");

  tcase_add_test(tc, test_is_greater_1);
  tcase_add_test(tc, test_is_greater_2);
  tcase_add_test(tc, test_is_greater_3);
  tcase_add_test(tc, test_is_greater_4);
  tcase_add_test(tc, test_is_greater_5);
  tcase_add_test(tc, test_is_greater_6);
  tcase_add_test(tc, test_is_greater_7);
  tcase_add_test(tc, test_is_greater_8);
  tcase_add_test(tc, test_is_greater_9);
  tcase_add_test(tc, test_is_greater_10);
  tcase_add_test(tc, test_is_greater_11);
  tcase_add_test(tc, test_is_greater_12);
  tcase_add_test(tc, test_is_greater_13);
  tcase_add_test(tc, test_is_greater_14);
  tcase_add_test(tc, test_is_greater_15);
  tcase_add_test(tc, test_is_greater_16);
  tcase_add_test(tc, test_is_greater_17);
  tcase_add_test(tc, test_is_greater_18);

  suite_add_tcase(c, tc);
  return c;
}
