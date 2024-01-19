#include "test_runner.h"

START_TEST(test_add_fail_1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_add(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, OK);
}

START_TEST(test_add_fail_2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_6) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_fail_7) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_add_8) {
  // 7.922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 11.884224377139650639031592551
  s21_decimal decimal_check = {{0x66666667, 0x66666666, 0x26666666, 0x1B0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int decimal_check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, decimal_check);
}

START_TEST(test_add_10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_add_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 79228162514264337593543950331
  s21_decimal decimal_check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_14) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_15) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_add_16) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -79228162514264337593543950331
  s21_decimal decimal_check = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_17) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_add_18) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_19) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -7922816251426433759354395037
  s21_decimal decimal_check = {
      {0x9999999D, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_20) {
  // 7922816251426433759354395035
  s21_decimal decimal1 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_add_21) {
  // 7922816251426433759354395035
  s21_decimal decimal1 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -71305346262837903834189555299
  s21_decimal decimal_check = {
      {0x66666663, 0x66666666, 0xE6666666, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_22) {
  // -7922816251426433759354395035
  s21_decimal decimal1 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // -7922816251426433809058396457
  s21_decimal decimal_check = {
      {0x2C307929, 0x999999A5, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_23) {
  // -7922816251426433759354395035
  s21_decimal decimal1 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -7922816251426433709650393612.6
  s21_decimal decimal_check = {
      {0x461B447E, 0xFFFFFF8C, 0xFFFFFFFF, 0x80010000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_24) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // -26409387.204754779197847983445
  s21_decimal decimal_check = {
      {0x2C255555, 0x11FF3ACD, 0x55555545, 0x80150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_25) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 26409387.998605864508043122005
  s21_decimal decimal_check = {{0x44A55555, 0x1AE4D6E3, 0x55555570, 0x150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_26) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -1431655757.0771837485735662406
  s21_decimal decimal_check = {{0x1C62D346, 0x987FA4A, 0x2E4260FD, 0x80130000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_27) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -1431655772.9228162514264337594
  s21_decimal decimal_check = {
      {0x87AD2CBA, 0xA08DEE5D, 0x2E426105, 0x80130000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_28) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 649244002.20841517182548587502
  s21_decimal decimal_check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_29) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_30) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_31) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_32) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_33) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395033.0
  s21_decimal decimal_check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_34) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395033.0
  s21_decimal decimal_check = {
      {0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_35) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_36) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_37) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_38) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal_check = {
      {0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_39) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 0.5000000000000000000000000000
  s21_decimal decimal_check = {{0x88000000, 0x1F128130, 0x1027E72F, 0x1C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_40) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.4999999999999999999999999998
  s21_decimal decimal_check = {
      {0x87FFFFFE, 0x1F128130, 0x1027E72F, 0x801C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_41) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 0.5000000000000000000000000002
  s21_decimal decimal_check = {{0x88000002, 0x1F128130, 0x1027E72F, 0x1C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_42) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.5000000000000000000000000000
  s21_decimal decimal_check = {
      {0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_43) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 1.9999999999999999999999999001
  s21_decimal decimal_check = {{0x1FFFFC19, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_44) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -1.9999999999999999999999998999
  s21_decimal decimal_check = {
      {0x1FFFFC17, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_45) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 1.0000000000000000000000000002
  s21_decimal decimal_check = {{0x10000002, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_46) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -1.0000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_47) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_48) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_49) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(decimal_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(decimal_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(decimal_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(decimal_check.bits[3], result.bits[3]);
}

START_TEST(test_add_50) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864508043122005
  s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_51) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 6148914691236517205.0000000000
  s21_decimal check = {{0x8EA6B400, 0x55555554, 0xC6AEA155, 0xA0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_52) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -6148914691236517205.0000000000
  s21_decimal check = {{0x8EA6B400, 0x55555554, 0xC6AEA155, 0x800A0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_53) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 6148914689804861440.0000000000
  s21_decimal check = {{0x0, 0x8EA6B400, 0xC6AEA154, 0xA0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_54) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -6148914689804861440.0000000000
  s21_decimal check = {{0x0, 0x8EA6B400, 0xC6AEA154, 0x800A0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_55) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 1431655765.0000000000000000000
  s21_decimal check = {{0xD2080000, 0x550AF453, 0x2E426101, 0x130000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_56) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -1431655765.0000000000000000000
  s21_decimal check = {{0xD2080000, 0x550AF453, 0x2E426101, 0x80130000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_57) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // 26409387.704754779197847983445
  s21_decimal check = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_58) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // -26409387.704754779197847983445
  s21_decimal check = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_59) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 26409387.498605864508043122005
  s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_60) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -26409387.498605864508043122005
  s21_decimal check = {{0x55555555, 0x0, 0x55555555, 0x80150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_61) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 26409387.000000000000000000000
  s21_decimal check = {{0x54E00000, 0xF8741FF5, 0x55555539, 0x150000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_62) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 49704001422.391670881925172831
  s21_decimal check = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_63) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 49704001422.391670881925172831
  s21_decimal check = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_64) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 49704001422.391670881925172831
  s21_decimal check = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_65) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -56124981125159617575501.618960
  s21_decimal check = {{0x6AA2DF10, 0x548E80BA, 0xB5597F0B, 0x80060000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_66) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // 56124981125259025578346.402302
  s21_decimal check = {{0xB407D1FE, 0x55EFABC7, 0xB5597F0B, 0x60000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_67) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 0.000000000000000000
  s21_decimal check = {{0x0, 0x0, 0x0, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_68) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 99408002844.78334176385034566
  s21_decimal check = {{0xE64BE946, 0x3BDA16BA, 0x201ED657, 0x110000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_69) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 49054757420.183255710099686956
  s21_decimal check = {{0x3CBDC62C, 0x491D6CBB, 0x9E8124F0, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_70) {
  // 49704001422.391670881925172831
  s21_decimal decimal1 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 50353245424.600086053750658706
  s21_decimal check = {{0xC2395692, 0xD677691, 0xA2B33A78, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_71) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337592894706333
  s21_decimal check = {{0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_72) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_add_73) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337592894706332
  s21_decimal check = {{0xD94D529C, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_74) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_add_75) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433758705151030.8
  s21_decimal check = {{0x7D053A24, 0xFFFFFFFE, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_76) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433760003639036
  s21_decimal check = {{0xC04C46FC, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_77) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 7922816251426433758705151032.8
  s21_decimal check = {{0x7D053A38, 0xFFFFFFFE, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_78) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433760003639037
  s21_decimal check = {{0xC04C46FD, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_79) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -649244001.20841517182548587502
  s21_decimal check = {{0xAF1233EE, 0xEAAE8DB8, 0xD1C8347E, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_80) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -649244003.20841517182548587502
  s21_decimal check = {{0x753233EE, 0xC23D4A13, 0xD1C83489, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_81) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -649244001.70841517182548587502
  s21_decimal check = {{0x609A33EE, 0xA0923CCF, 0xD1C83481, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_82) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -649244002.70841517182548587502
  s21_decimal check = {{0xC3AA33EE, 0xC599AFC, 0xD1C83487, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_83) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -649244001.70841517182548587502
  s21_decimal check = {{0x609A33EE, 0xA0923CCF, 0xD1C83481, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_84) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -649244002.70841517182548587502
  s21_decimal check = {{0xC3AA33EE, 0xC599AFC, 0xD1C83487, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_85) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -649244001.70841517182548587502
  s21_decimal check = {{0x609A33EE, 0xA0923CCF, 0xD1C83481, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_86) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -649244002.70841517182548587502
  s21_decimal check = {{0xC3AA33EE, 0xC599AFC, 0xD1C83487, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_87) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -649244000.20841517182548587502
  s21_decimal check = {{0x4C0233EE, 0x7EE72F8B, 0xD1C83479, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_88) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -649244004.20841517182548587502
  s21_decimal check = {{0xD84233EE, 0x2E04A840, 0xD1C8348F, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_89) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -649244001.20841517182548587502
  s21_decimal check = {{0xAF1233EE, 0xEAAE8DB8, 0xD1C8347E, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_90) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -649244003.20841517182548587502
  s21_decimal check = {{0x753233EE, 0xC23D4A13, 0xD1C83489, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_91) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197198739443
  s21_decimal check = {{0x2EA2A7F3, 0x55555555, 0x55555555, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_92) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779198497227447
  s21_decimal check = {{0x7C0802B7, 0x55555555, 0x55555555, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_93) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387498605864507393878003
  s21_decimal check = {{0x2EA2A7F3, 0x0, 0x55555555, 0x0}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_94) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864508692366007
  s21_decimal check = {{0x7C0802B7, 0x0, 0x55555555, 0x80000000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_95) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 6148914690587273202.7915848282
  s21_decimal check = {{0x54CBCA5A, 0xFB3B8D87, 0xC6AEA154, 0xA0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_96) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -6148914691885761207.2084151718
  s21_decimal check = {{0xC8819DA6, 0xAF6F1D21, 0xC6AEA155, 0x800A0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_97) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 6148914689155617437.7915848282
  s21_decimal check = {{0xC625165A, 0x348CEC32, 0xC6AEA154, 0xA0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_98) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -6148914690454105442.2084151718
  s21_decimal check = {{0x39DAE9A6, 0xE8C07BCD, 0xC6AEA154, 0x800A0000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_99) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 782411762.79158482817451412498
  s21_decimal check = {{0x222DCC12, 0xFBF79F60, 0xFCCF9588, 0x140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_100) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -2080899767.2084151718254858750
  s21_decimal check = {{0x6D71D1FE, 0x2A7D2584, 0x433CCCA8, 0x80130000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_101) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // -622834614.50366039262763789158
  s21_decimal check = {{0x75C9AB66, 0xB85F1D54, 0xC93FABFA, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_102) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // -675653389.91316995102333385846
  s21_decimal check = {{0xAE7ABC76, 0xF48CBA77, 0xDA50BD0D, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_103) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -622834614.70980930731744275302
  s21_decimal check = {{0x999AB66, 0xD675EBE6, 0xC93FABFB, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_104) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -675653389.70702103633352899702
  s21_decimal check = {{0x1AAABC76, 0xD675EBE6, 0xDA50BD0C, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_105) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -622834615.20841517182548587502
  s21_decimal check = {{0x567233EE, 0x8A6A4F1A, 0xC93FABFE, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_106) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -675653389.20841517182548587502
  s21_decimal check = {{0xCDD233EE, 0x228188B1, 0xDA50BD0A, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_107) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -649243994.28559892039905211567
  s21_decimal check = {{0xF9AE74AF, 0x63582784, 0xD1C83459, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_108) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -649244010.13123142325191963437
  s21_decimal check = {{0x2A95F32D, 0x4993B047, 0xD1C834AF, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_109) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -649243994.20841517182548587502
  s21_decimal check = {{0xF9A233EE, 0xF83AFA7A, 0xD1C83458, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_110) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -649244010.20841517182548587502
  s21_decimal check = {{0x2AA233EE, 0xB4B0DD51, 0xD1C834AF, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_111) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -649243998.57474914350533227502
  s21_decimal check = {{0x5F68B3EE, 0xA3BC6BD2, 0xD1C83470, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_112) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -649244005.84208120014563947502
  s21_decimal check = {{0xC4DBB3EE, 0x92F6BF9, 0xD1C83498, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_113) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_114) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_115) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_116) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_117) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_118) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_119) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_120) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_121) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -56124981125209970820926.219046
  s21_decimal check = {{0xF5752326, 0x554164BC, 0xB5597F0B, 0x80060000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_122) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // 56124981125208672332921.802216
  s21_decimal check = {{0x29358DE8, 0x553CC7C5, 0xB5597F0B, 0x60000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_123) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // -50353245424.600086053750658706
  s21_decimal check = {{0xC2395692, 0xD677691, 0xA2B33A78, 0x80120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_add_124) {
  // -649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 49054757420.183255710099686956
  s21_decimal check = {{0x3CBDC62C, 0x491D6CBB, 0x9E8124F0, 0x120000}};

  s21_decimal result;
  int return_value = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

Suite *s21_add_cases(void) {
  Suite *suite = suite_create("s21_add_cases");
  TCase *tc = tcase_create("s21_add_tc");

  tcase_add_test(tc, test_add_fail_1);
  tcase_add_test(tc, test_add_fail_2);
  tcase_add_test(tc, test_add_fail_3);
  tcase_add_test(tc, test_add_fail_4);
  tcase_add_test(tc, test_add_fail_5);
  tcase_add_test(tc, test_add_fail_6);
  tcase_add_test(tc, test_add_fail_7);
  tcase_add_test(tc, test_add_8);
  tcase_add_test(tc, test_add_9);
  tcase_add_test(tc, test_add_10);
  tcase_add_test(tc, test_add_11);
  tcase_add_test(tc, test_add_12);
  tcase_add_test(tc, test_add_13);
  tcase_add_test(tc, test_add_14);
  tcase_add_test(tc, test_add_15);
  tcase_add_test(tc, test_add_16);
  tcase_add_test(tc, test_add_17);
  tcase_add_test(tc, test_add_18);
  tcase_add_test(tc, test_add_19);
  tcase_add_test(tc, test_add_20);
  tcase_add_test(tc, test_add_21);
  tcase_add_test(tc, test_add_22);
  tcase_add_test(tc, test_add_23);
  tcase_add_test(tc, test_add_24);
  tcase_add_test(tc, test_add_25);
  tcase_add_test(tc, test_add_26);
  tcase_add_test(tc, test_add_27);
  tcase_add_test(tc, test_add_28);
  tcase_add_test(tc, test_add_29);
  tcase_add_test(tc, test_add_30);
  tcase_add_test(tc, test_add_31);
  tcase_add_test(tc, test_add_32);
  tcase_add_test(tc, test_add_33);
  tcase_add_test(tc, test_add_34);
  tcase_add_test(tc, test_add_35);
  tcase_add_test(tc, test_add_36);
  tcase_add_test(tc, test_add_37);
  tcase_add_test(tc, test_add_38);
  tcase_add_test(tc, test_add_39);
  tcase_add_test(tc, test_add_40);
  tcase_add_test(tc, test_add_41);
  tcase_add_test(tc, test_add_42);
  tcase_add_test(tc, test_add_43);
  tcase_add_test(tc, test_add_44);
  tcase_add_test(tc, test_add_45);
  tcase_add_test(tc, test_add_46);
  tcase_add_test(tc, test_add_47);
  tcase_add_test(tc, test_add_48);
  tcase_add_test(tc, test_add_49);
  tcase_add_test(tc, test_add_50);
  tcase_add_test(tc, test_add_51);
  tcase_add_test(tc, test_add_52);
  tcase_add_test(tc, test_add_53);
  tcase_add_test(tc, test_add_54);
  tcase_add_test(tc, test_add_55);
  tcase_add_test(tc, test_add_56);
  tcase_add_test(tc, test_add_57);
  tcase_add_test(tc, test_add_58);
  tcase_add_test(tc, test_add_59);
  tcase_add_test(tc, test_add_60);
  tcase_add_test(tc, test_add_61);
  tcase_add_test(tc, test_add_62);
  tcase_add_test(tc, test_add_63);
  tcase_add_test(tc, test_add_64);
  tcase_add_test(tc, test_add_65);
  tcase_add_test(tc, test_add_66);
  tcase_add_test(tc, test_add_67);
  tcase_add_test(tc, test_add_68);
  tcase_add_test(tc, test_add_69);
  tcase_add_test(tc, test_add_70);
  tcase_add_test(tc, test_add_71);
  tcase_add_test(tc, test_add_72);
  tcase_add_test(tc, test_add_73);
  tcase_add_test(tc, test_add_74);
  tcase_add_test(tc, test_add_75);
  tcase_add_test(tc, test_add_76);
  tcase_add_test(tc, test_add_77);
  tcase_add_test(tc, test_add_78);
  tcase_add_test(tc, test_add_79);
  tcase_add_test(tc, test_add_80);
  tcase_add_test(tc, test_add_81);
  tcase_add_test(tc, test_add_82);
  tcase_add_test(tc, test_add_83);
  tcase_add_test(tc, test_add_84);
  tcase_add_test(tc, test_add_85);
  tcase_add_test(tc, test_add_86);
  tcase_add_test(tc, test_add_87);
  tcase_add_test(tc, test_add_88);
  tcase_add_test(tc, test_add_89);
  tcase_add_test(tc, test_add_90);
  tcase_add_test(tc, test_add_91);
  tcase_add_test(tc, test_add_92);
  tcase_add_test(tc, test_add_93);
  tcase_add_test(tc, test_add_94);
  tcase_add_test(tc, test_add_95);
  tcase_add_test(tc, test_add_96);
  tcase_add_test(tc, test_add_97);
  tcase_add_test(tc, test_add_98);
  tcase_add_test(tc, test_add_99);
  tcase_add_test(tc, test_add_100);
  tcase_add_test(tc, test_add_101);
  tcase_add_test(tc, test_add_102);
  tcase_add_test(tc, test_add_103);
  tcase_add_test(tc, test_add_104);
  tcase_add_test(tc, test_add_105);
  tcase_add_test(tc, test_add_106);
  tcase_add_test(tc, test_add_107);
  tcase_add_test(tc, test_add_108);
  tcase_add_test(tc, test_add_109);
  tcase_add_test(tc, test_add_110);
  tcase_add_test(tc, test_add_111);
  tcase_add_test(tc, test_add_112);
  tcase_add_test(tc, test_add_113);
  tcase_add_test(tc, test_add_114);
  tcase_add_test(tc, test_add_115);
  tcase_add_test(tc, test_add_116);
  tcase_add_test(tc, test_add_117);
  tcase_add_test(tc, test_add_118);
  tcase_add_test(tc, test_add_119);
  tcase_add_test(tc, test_add_120);
  tcase_add_test(tc, test_add_121);
  tcase_add_test(tc, test_add_122);
  tcase_add_test(tc, test_add_123);
  tcase_add_test(tc, test_add_124);

  suite_add_tcase(suite, tc);
  return suite;
}