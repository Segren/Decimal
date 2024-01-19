#include "test_runner.h"

START_TEST(null_value) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  int return_value = s21_div(decimal1, decimal2, NULL);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_1) {
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_2) {
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_3) {
  s21_decimal decimal1 = {{0, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_4) {
  s21_decimal decimal1 = {{0, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_5) {
  s21_decimal decimal1 = {{0, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_6) {
  s21_decimal decimal1 = {{0, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_7) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_1) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_2) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_3) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x1C0001}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_4) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x1C8000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_5) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x11C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_6) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x401C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_7) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(zero_div_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, DIV_BY_ZERO);
}
END_TEST

START_TEST(zero_div_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, DIV_BY_ZERO);
}
END_TEST

START_TEST(overflow_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_3) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_4) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_6) {
  // 79228162514264337593543950320
  s21_decimal decimal1 = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_7) {
  // -79228162514264337593543950320
  s21_decimal decimal1 = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(div_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_25) {
  // 1.9999999999999999999999999999
  s21_decimal decimal1 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 0.0002363985717743887678528201
  s21_decimal decimal_check = {{0x576D5AC9, 0xEC2BEAF0, 0x1F497, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_26) {
  // 1.9999999999999999999999999999
  s21_decimal decimal1 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -0.0002363985717743887678528201
  s21_decimal decimal_check = {{0x576D5AC9, 0xEC2BEAF0, 0x1F497, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_33) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -0.0000000000000000000000000007
  s21_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_34) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 0.0000000000000000000000000007
  s21_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_35) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 0.0000000002735025519964266099
  s21_decimal decimal_check = {{0x39191E73, 0x25F4C338, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_36) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -0.0000000002735025519964266099
  s21_decimal decimal_check = {{0x39191E73, 0x25F4C338, 0x0, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_37) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -0.0000001181992858871943839264
  s21_decimal decimal_check = {{0x6EA2BE20, 0x137232AD, 0x40, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_38) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 0.0000001181992858871943839264
  s21_decimal decimal_check = {{0x6EA2BE20, 0x137232AD, 0x40, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_39) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -0.000125
  s21_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_40) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 0.000125
  s21_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_41) {
  // -39614081266355.540835774234624
  s21_decimal decimal1 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -10000000002328.306437080797375
  s21_decimal decimal_check = {
      {0x6E74D0BF, 0x5E74D0BF, 0x204FCE5E, 0x800F0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_42) {
  // -39614081266355.540835774234624
  s21_decimal decimal1 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 10000000002328.306437080797375
  s21_decimal decimal_check = {{0x6E74D0BF, 0x5E74D0BF, 0x204FCE5E, 0xF0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_45) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 0.000001969814300537109375
  s21_decimal decimal_check = {{0x78FFBB7F, 0x1B562FAB, 0x0, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_46) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -0.000001969814300537109375
  s21_decimal decimal_check = {{0x78FFBB7F, 0x1B562FAB, 0x0, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_47) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 0.0000009849071503832129703815
  s21_decimal decimal_check = {{0x386F8F87, 0xEB530E1E, 0x215, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_48) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -0.0000009849071503832129703815
  s21_decimal decimal_check = {{0x386F8F87, 0xEB530E1E, 0x215, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_49) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_50) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 4230.144
  s21_decimal decimal_check = {{0x408C00, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_51) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -4230.144
  s21_decimal decimal_check = {{0x408C00, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_52) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 1067.8384720176741640293091584
  s21_decimal decimal_check = {{0xDF08900, 0x9CD22B64, 0x2280F3EB, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_53) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -1067.8384720176741640293091584
  s21_decimal decimal_check = {{0xDF08900, 0x9CD22B64, 0x2280F3EB, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_54) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 16920.576
  s21_decimal decimal_check = {{0x1023000, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(div_55) {
  // 8460.288
  s21_decimal decimal1 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -16920.576
  s21_decimal decimal_check = {{0x1023000, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

Suite *s21_div_cases(void) {
  Suite *suite = suite_create("s21_div_cases");
  TCase *tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, null_value);
  tcase_add_test(tc, invalid_dec1_1);
  tcase_add_test(tc, invalid_dec1_2);
  tcase_add_test(tc, invalid_dec1_3);
  tcase_add_test(tc, invalid_dec1_4);
  tcase_add_test(tc, invalid_dec1_5);
  tcase_add_test(tc, invalid_dec1_6);
  tcase_add_test(tc, invalid_dec1_7);
  tcase_add_test(tc, invalid_dec2_1);
  tcase_add_test(tc, invalid_dec2_2);
  tcase_add_test(tc, invalid_dec2_3);
  tcase_add_test(tc, invalid_dec2_4);
  tcase_add_test(tc, invalid_dec2_5);
  tcase_add_test(tc, invalid_dec2_6);
  tcase_add_test(tc, invalid_dec2_7);
  tcase_add_test(tc, zero_div_1);
  tcase_add_test(tc, zero_div_2);
  tcase_add_test(tc, overflow_1);
  tcase_add_test(tc, overflow_2);
  tcase_add_test(tc, overflow_3);
  tcase_add_test(tc, overflow_4);
  tcase_add_test(tc, overflow_6);
  tcase_add_test(tc, overflow_7);
  tcase_add_test(tc, overflow_8);
  tcase_add_test(tc, overflow_9);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);
  tcase_add_test(tc, div_16);
  tcase_add_test(tc, div_17);
  tcase_add_test(tc, div_18);
  tcase_add_test(tc, div_19);
  tcase_add_test(tc, div_20);
  tcase_add_test(tc, div_21);
  tcase_add_test(tc, div_22);
  tcase_add_test(tc, div_25);
  tcase_add_test(tc, div_26);
  tcase_add_test(tc, div_33);
  tcase_add_test(tc, div_34);
  tcase_add_test(tc, div_35);
  tcase_add_test(tc, div_36);
  tcase_add_test(tc, div_37);
  tcase_add_test(tc, div_38);
  tcase_add_test(tc, div_39);
  tcase_add_test(tc, div_40);
  tcase_add_test(tc, div_41);
  tcase_add_test(tc, div_42);
  tcase_add_test(tc, div_45);
  tcase_add_test(tc, div_46);
  tcase_add_test(tc, div_47);
  tcase_add_test(tc, div_48);
  tcase_add_test(tc, div_49);
  tcase_add_test(tc, div_50);
  tcase_add_test(tc, div_51);
  tcase_add_test(tc, div_52);
  tcase_add_test(tc, div_53);
  tcase_add_test(tc, div_54);
  tcase_add_test(tc, div_55);

  suite_add_tcase(suite, tc);
  return suite;
}