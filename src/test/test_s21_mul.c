#include "test_runner.h"

START_TEST(null_value) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  int return_value = s21_mul(decimal1, decimal2, NULL);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_1) {
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_2) {
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_3) {
  s21_decimal decimal1 = {{0, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_4) {
  s21_decimal decimal1 = {{0, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_5) {
  s21_decimal decimal1 = {{0, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_6) {
  s21_decimal decimal1 = {{0, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec1_7) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_1) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_2) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_3) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x1C0001}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_4) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x1C8000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_5) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x11C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_6) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0x401C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(invalid_dec2_7) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(return_value, OK);
}
END_TEST

START_TEST(overflow_1) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_2) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_3) {
  // 792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // -782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x800E0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_4) {
  // 792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_5) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_6) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_7) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_8) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(overflow_9) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_LARGE_OR_POS_INF);
}
END_TEST

START_TEST(overflow_10) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, TOO_SMALL_OR_NEG_INF);
}
END_TEST

START_TEST(mul_1) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7.8228162514264337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x1C0000}};
  // 61.978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x1B0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_2) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.8228162514264337593543950335
  s21_decimal decimal2 = {{0x4F63FFFF, 0xBB0D25CF, 0x1A962D2F, 0x801C0000}};
  // -6.5190219687391279469416894926
  s21_decimal check = {{0x23B23CAE, 0xEC60363A, 0xD2A415FA, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_3) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.00000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800E0000}};
  // 0.0000000000003500000000000012
  s21_decimal check = {{0x40B6C00C, 0xC6F3B, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_4) {
  // -7922816251426.4337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // 78228162514264.337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xF0000}};
  // -619787357287241642624224547.27
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_5) {
  // -79228162514264.337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // 782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
  // -61978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_6) {
  // 79228162514265.1
  s21_decimal decimal1 = {{0x70D4257B, 0x2D093, 0x0, 0x10000}};
  // 78228162514264.5
  s21_decimal decimal2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
  // 6197873572872488935063484519.0
  s21_decimal check = {{0xA1CDB406, 0x3FDA3F58, 0xC8439BCC, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_7) {
  // 5.0
  s21_decimal decimal1 = {{0x32, 0x0, 0x0, 0x10000}};
  // 4.5
  s21_decimal decimal2 = {{0x2D, 0x0, 0x0, 0x10000}};
  // 22.50
  s21_decimal check = {{0x8CA, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_8) {
  // 79228162.5
  s21_decimal decimal1 = {{0x2F394219, 0x0, 0x0, 0x10000}};
  // 78228162.5555555555555
  s21_decimal decimal2 = {{0xB20798E3, 0x6856A1BC, 0x2A, 0xD0000}};
  // 6197873575027970.8333289317688
  s21_decimal check = {{0x34C52538, 0x6AFC5902, 0xC8439BCD, 0xD0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_9) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -2.00000000000005
  s21_decimal decimal2 = {{0x20F48005, 0xB5E6, 0x0, 0x800E0000}};
  // 14.000000000000400000000000001
  s21_decimal check = {{0xF1E90001, 0xBD686F20, 0x2D3C8750, 0x1B0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_10) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800F0000}};
  // 0.0000000000000350000000000001
  s21_decimal check = {{0xB9ABE001, 0x13E52, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_11) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.00000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x50000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_12) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 6148914691236517205
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_13) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -6148914691236517205
  s21_decimal check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_14) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 49191317529892137640
  s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_15) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -49191317529892137640
  s21_decimal check = {{0xAAAAAAA8, 0xAAAAAAAA, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_16) {
  // 0.0000000000000025
  s21_decimal decimal1 = {{0x19, 0x0, 0x0, 0x100000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 0.0000000000000025000000000000
  s21_decimal check = {{0xC41E9000, 0x16BC, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_17) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 48716721244363430604.148555673
  s21_decimal check = {{0xD4B7BF99, 0x79B8EBC2, 0x9D6986FE, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_18) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -48716721244363430604.148555673
  s21_decimal check = {{0xD4B7BF99, 0x79B8EBC2, 0x9D6986FE, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_19) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 15372.2867280912930125
  s21_decimal check = {{0x5555554D, 0x55555555, 0x8, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_20) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -15372.2867280912930125
  s21_decimal check = {{0x5555554D, 0x55555555, 0x8, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_21) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_22) {
  // 6148914691236517205
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_23) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 0.3961408125713216879677197517
  s21_decimal check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_24) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -0.3961408125713216879677197517
  s21_decimal check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_25) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 0.00000000000000125
  s21_decimal check = {{0x7D, 0x0, 0x0, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_26) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -0.00000000000000125
  s21_decimal check = {{0x7D, 0x0, 0x0, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_27) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -4.0000000000000000000000000008
  s21_decimal check = {{0x40000008, 0xF8940984, 0x813F3978, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_28) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 4.0000000000000000000000000008
  s21_decimal check = {{0x40000008, 0xF8940984, 0x813F3978, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_29) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168796771975175
  s21_decimal check = {{0x7, 0x0, 0x80000000, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_30) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168796771975175
  s21_decimal check = {{0x7, 0x0, 0x80000000, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_31) {
  // -7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -62.771017353866807638357894230
  s21_decimal check = {{0x96EE456, 0x359A3B3E, 0xCAD2F7F5, 0x801B0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_32) {
  // -7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 62.771017353866807638357894230
  s21_decimal check = {{0x96EE456, 0x359A3B3E, 0xCAD2F7F5, 0x1B0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_33) {
  // -7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // -6.2771017353866807638357894234
  s21_decimal check = {{0x96EE45A, 0x359A3B3E, 0xCAD2F7F5, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_34) {
  // -7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // 6.2771017353866807638357894234
  s21_decimal check = {{0x96EE45A, 0x359A3B3E, 0xCAD2F7F5, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_35) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -20923672446417263756150.562906
  s21_decimal check = {{0x8A37E05A, 0x2397C118, 0x439BA7FC, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_36) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 20923672446417263756150.562906
  s21_decimal check = {{0x8A37E05A, 0x2397C118, 0x439BA7FC, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_37) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -20923672051380999118065.508859
  s21_decimal check = {{0x3BF421FB, 0xB95D0366, 0x439BA7E6, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_38) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 20923672051380999118065.508859
  s21_decimal check = {{0x3BF421FB, 0xB95D0366, 0x439BA7E6, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_39) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -1584563250285286.7518708789275
  s21_decimal check = {{0x3333301B, 0x33333333, 0x33333333, 0x800D0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_40) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 1584563250285286.7518708789275
  s21_decimal check = {{0x3333301B, 0x33333333, 0x33333333, 0xD0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_41) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -6277101735386680.7638357894230
  s21_decimal check = {{0x96EE456, 0x359A3B3E, 0xCAD2F7F5, 0x800D0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_42) {
  // -792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 6277101735386680.7638357894230
  s21_decimal check = {{0x96EE456, 0x359A3B3E, 0xCAD2F7F5, 0xD0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_43) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_44) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_45) {
  // -0.0000000000000000000000000010
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.0000000000000000000000070558
  s21_decimal check = {{0x1139E, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_46) {
  // -0.0000000000000000000000000010
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -7055.820576069728775806815669
  s21_decimal decimal2 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x80180000}};
  // 0.0000000000000000000000070558
  s21_decimal check = {{0x1139E, 0x0, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_47) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_48) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -0.5
  s21_decimal check = {{0x5, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_49) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 1.9999999999999999999999999000
  s21_decimal check = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_50) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -1.9999999999999999999999999000
  s21_decimal check = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_51) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 26409387.498605864508043122005
  s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_52) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -26409387.498605864508043122005
  s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_53) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // -10575248622445743161168.257945
  s21_decimal check = {{0x2D766399, 0x8D2F2559, 0x222BA400, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_54) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // 10575248622445743161168.257945
  s21_decimal check = {{0x2D766399, 0x8D2F2559, 0x222BA400, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_55) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -0.0000000000000000000264093870
  s21_decimal check = {{0xFBDC0AE, 0x0, 0x0, 0x801C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_56) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 0.0000000000000000000264093870
  s21_decimal check = {{0xFBDC0AE, 0x0, 0x0, 0x1C0000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_57) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // -10575248622445743161168.257945
  s21_decimal check = {{0x2D766399, 0x8D2F2559, 0x222BA400, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_58) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // 10575248622445743161168.257945
  s21_decimal check = {{0x2D766399, 0x8D2F2559, 0x222BA400, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_59) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x90000}};
  // -1517920198732713195385438703.6
  s21_decimal check = {{0xB557935C, 0x9014D982, 0x310BF10C, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_60) {
  // -26409387
  s21_decimal decimal1 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -57476540395758265626.742442133
  s21_decimal decimal2 = {{0xD42B4895, 0x339BF28D, 0xB9B77ADA, 0x80090000}};
  // 1517920198732713195385438703.6
  s21_decimal check = {{0xB557935C, 0x9014D982, 0x310BF10C, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_61) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 52818775009509558395695964249
  s21_decimal check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(mul_62) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -52818775009509558395695964249
  s21_decimal check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}
END_TEST

Suite *s21_mul_cases(void) {
  Suite *suite = suite_create("s21_mul_cases");
  TCase *tc = tcase_create("s21_mul_tc");

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
  tcase_add_test(tc, overflow_1);
  tcase_add_test(tc, overflow_2);
  tcase_add_test(tc, overflow_3);
  tcase_add_test(tc, overflow_4);
  tcase_add_test(tc, overflow_5);
  tcase_add_test(tc, overflow_6);
  tcase_add_test(tc, overflow_7);
  tcase_add_test(tc, overflow_8);
  tcase_add_test(tc, overflow_9);
  tcase_add_test(tc, overflow_10);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, mul_13);
  tcase_add_test(tc, mul_14);
  tcase_add_test(tc, mul_15);
  tcase_add_test(tc, mul_16);
  tcase_add_test(tc, mul_17);
  tcase_add_test(tc, mul_18);
  tcase_add_test(tc, mul_19);
  tcase_add_test(tc, mul_20);
  tcase_add_test(tc, mul_21);
  tcase_add_test(tc, mul_22);
  tcase_add_test(tc, mul_23);
  tcase_add_test(tc, mul_24);
  tcase_add_test(tc, mul_25);
  tcase_add_test(tc, mul_26);
  tcase_add_test(tc, mul_27);
  tcase_add_test(tc, mul_28);
  tcase_add_test(tc, mul_29);
  tcase_add_test(tc, mul_30);
  tcase_add_test(tc, mul_31);
  tcase_add_test(tc, mul_32);
  tcase_add_test(tc, mul_33);
  tcase_add_test(tc, mul_34);
  tcase_add_test(tc, mul_35);
  tcase_add_test(tc, mul_36);
  tcase_add_test(tc, mul_37);
  tcase_add_test(tc, mul_38);
  tcase_add_test(tc, mul_39);
  tcase_add_test(tc, mul_40);
  tcase_add_test(tc, mul_41);
  tcase_add_test(tc, mul_42);
  tcase_add_test(tc, mul_43);
  tcase_add_test(tc, mul_44);
  tcase_add_test(tc, mul_45);
  tcase_add_test(tc, mul_46);
  tcase_add_test(tc, mul_47);
  tcase_add_test(tc, mul_48);
  tcase_add_test(tc, mul_49);
  tcase_add_test(tc, mul_50);
  tcase_add_test(tc, mul_51);
  tcase_add_test(tc, mul_52);
  tcase_add_test(tc, mul_53);
  tcase_add_test(tc, mul_54);
  tcase_add_test(tc, mul_55);
  tcase_add_test(tc, mul_56);
  tcase_add_test(tc, mul_57);
  tcase_add_test(tc, mul_58);
  tcase_add_test(tc, mul_59);
  tcase_add_test(tc, mul_60);
  tcase_add_test(tc, mul_61);
  tcase_add_test(tc, mul_62);

  suite_add_tcase(suite, tc);
  return suite;
}