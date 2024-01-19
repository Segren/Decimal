#include "test_runner.h"

START_TEST(test_sub_fail_1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_sub(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, OK);
}

START_TEST(test_sub_fail_2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_9) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_fail_17) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_sub_18) {
  // 7.922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 3.9614081257132168796771975172
  s21_decimal check = {{0x4, 0x0, 0x80000000, 0x1C0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 79228162514264337593543949689
  s21_decimal check = {{0xFFFFFD79, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 79228162514240090656400479551
  s21_decimal check = {{0x4AC153F, 0xFFA9DB8A, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_34) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // 18994429982494779296567793531
  s21_decimal check = {{0xB3DC177B, 0x9B738FD3, 0x3D5FD300, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // overflow
  int check = TOO_LARGE_OR_POS_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_36) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_37) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x00000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_38) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -1431655765.5000000000000000000
  s21_decimal check = {{0x16FC0000, 0x9A6E85D6, 0x2E426101, 0x80130000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_39) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 1431655764.5000000000000000000
  s21_decimal check = {{0x8D140000, 0xFA762D1, 0x2E426101, 0x130000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_40) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -26409388.004754779197847983445
  s21_decimal check = {{0x44A55555, 0x703A2C38, 0x55555570, 0x80150000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_41) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // 26409387.004754779197847983445
  s21_decimal check = {{0x66055555, 0x3A707E72, 0x5555553A, 0x150000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_42) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -26409387.998605864508043122005
  s21_decimal check = {{0x44A55555, 0x1AE4D6E3, 0x55555570, 0x80150000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_43) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 26409386.998605864508043122005
  s21_decimal check = {{0x66055555, 0xE51B291D, 0x55555539, 0x150000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_44) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -26409387.500000000000000000000
  s21_decimal check = {{0x44300000, 0x1358F6D8, 0x55555555, 0x80150000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_45) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 26409386.500000000000000000000
  s21_decimal check = {{0x65900000, 0xDD8F4912, 0x5555551E, 0x150000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_46) {
  // -0.5000000000000000000000000001
  s21_decimal decimal1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -8.422816251426433759354395034
  s21_decimal check = {{0xD99999A, 0xE981D9B8, 0x1B3730B7, 0x801B0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_47) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_48) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_49) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_50) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_51) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_52) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_53) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_54) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_55) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_56) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal check = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_57) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_58) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 646.33673839575124685661598885
  s21_decimal check = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_59) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 646.33673839575124685661598885
  s21_decimal check = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_60) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 646.33673839575124685661598885
  s21_decimal check = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_61) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 0.00000000000000000000000000
  s21_decimal check = {{0x0, 0x0, 0x0, 0x1A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_62) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // -646.33673839575124685661598885
  s21_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 1292.6734767915024937132319777
  s21_decimal check = {{0x23C16421, 0xED05BA53, 0x29C4BE8F, 0x190000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_63) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // -24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // 24246937143471430.154179596851
  s21_decimal check = {{0xAC45233, 0x5A82E4DF, 0x4E5898A8, 0xC0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_64) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // -24246937143470137.480702805349
  s21_decimal check = {{0xB5F4565, 0x5A7E4D31, 0x4E5898A8, 0x800C0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_65) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // -60233732531769558296976156158
  s21_decimal check = {{0x4C23E5FE, 0x648C702C, 0xC2A02CFF, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_66) {
  // 646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // -60233732531769558296976156804
  s21_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // 60233732531769558296976157450
  s21_decimal check = {{0x4C23EB0A, 0x648C702C, 0xC2A02CFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_67) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_68) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543949689
  s21_decimal check = {{0xFFFFFD79, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_69) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TOO_SMALL_OR_NEG_INF;

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, check);
}

START_TEST(test_sub_70) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543949688
  s21_decimal check = {{0xFFFFFD78, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_71) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395679
  s21_decimal check = {{0x99999C1F, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_72) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354394386.7
  s21_decimal check = {{0xFFFFE6BB, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_73) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395680
  s21_decimal check = {{0x99999C20, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_74) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354394387.2
  s21_decimal check = {{0xFFFFE6C0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_75) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395680
  s21_decimal check = {{0x99999C20, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_76) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354394387.7
  s21_decimal check = {{0xFFFFE6C5, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_77) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759354395681
  s21_decimal check = {{0x99999C21, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_78) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354394388.7
  s21_decimal check = {{0xFFFFE6CF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_79) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -647.33673839575124685661598885
  s21_decimal check = {{0x96C6F4A5, 0x7DE4B072, 0xD12A70A2, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_80) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -645.33673839575124685661598885
  s21_decimal check = {{0xCEC6F4A5, 0xC45496CC, 0xD08500FC, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_81) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -646.83673839575124685661598885
  s21_decimal check = {{0x24C6F4A5, 0xF80AA09, 0xD10114B9, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_82) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -645.83673839575124685661598885
  s21_decimal check = {{0x40C6F4A5, 0x32B89D36, 0xD0AE5CE6, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_83) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -646.83673839575124685661598885
  s21_decimal check = {{0x24C6F4A5, 0xF80AA09, 0xD10114B9, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_84) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -645.83673839575124685661598885
  s21_decimal check = {{0x40C6F4A5, 0x32B89D36, 0xD0AE5CE6, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_85) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -646.83673839575124685661598885
  s21_decimal check = {{0x24C6F4A5, 0xF80AA09, 0xD10114B9, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_86) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -645.83673839575124685661598885
  s21_decimal check = {{0x40C6F4A5, 0x32B89D36, 0xD0AE5CE6, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_87) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -648.33673839575124685661598875
  s21_decimal check = {{0x7AC6F49B, 0x5AACBD45, 0xD17D2875, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_88) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -644.33673839575124685661598895
  s21_decimal check = {{0xEAC6F4AF, 0xE78C89F9, 0xD0324929, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_89) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -647.33673839575124685661598885
  s21_decimal check = {{0x96C6F4A5, 0x7DE4B072, 0xD12A70A2, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

START_TEST(test_sub_90) {
  // -646.33673839575124685661598885
  s21_decimal decimal1 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -645.33673839575124685661598885
  s21_decimal check = {{0xCEC6F4A5, 0xC45496CC, 0xD08500FC, 0x801A0000}};

  s21_decimal result;
  int return_value = s21_sub(decimal1, decimal2, &result);
  ck_assert_int_eq(return_value, OK);
  ck_assert_uint_eq(check.bits[0], result.bits[0]);
  ck_assert_uint_eq(check.bits[1], result.bits[1]);
  ck_assert_uint_eq(check.bits[2], result.bits[2]);
  ck_assert_uint_eq(check.bits[3], result.bits[3]);
}

Suite *s21_sub_cases(void) {
  Suite *suite = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");

  tcase_add_test(tc, test_sub_fail_1);
  tcase_add_test(tc, test_sub_fail_2);
  tcase_add_test(tc, test_sub_fail_3);
  tcase_add_test(tc, test_sub_fail_4);
  tcase_add_test(tc, test_sub_fail_5);
  tcase_add_test(tc, test_sub_fail_6);
  tcase_add_test(tc, test_sub_fail_7);
  tcase_add_test(tc, test_sub_fail_8);
  tcase_add_test(tc, test_sub_fail_9);
  tcase_add_test(tc, test_sub_fail_10);
  tcase_add_test(tc, test_sub_fail_11);
  tcase_add_test(tc, test_sub_fail_12);
  tcase_add_test(tc, test_sub_fail_13);
  tcase_add_test(tc, test_sub_fail_14);
  tcase_add_test(tc, test_sub_fail_15);
  tcase_add_test(tc, test_sub_fail_16);
  tcase_add_test(tc, test_sub_fail_17);
  tcase_add_test(tc, test_sub_18);
  tcase_add_test(tc, test_sub_19);
  tcase_add_test(tc, test_sub_20);
  tcase_add_test(tc, test_sub_21);
  tcase_add_test(tc, test_sub_22);
  tcase_add_test(tc, test_sub_23);
  tcase_add_test(tc, test_sub_24);
  tcase_add_test(tc, test_sub_25);
  tcase_add_test(tc, test_sub_26);
  tcase_add_test(tc, test_sub_27);
  tcase_add_test(tc, test_sub_28);
  tcase_add_test(tc, test_sub_29);
  tcase_add_test(tc, test_sub_30);
  tcase_add_test(tc, test_sub_31);
  tcase_add_test(tc, test_sub_32);
  tcase_add_test(tc, test_sub_33);
  tcase_add_test(tc, test_sub_34);
  tcase_add_test(tc, test_sub_35);
  tcase_add_test(tc, test_sub_36);
  tcase_add_test(tc, test_sub_37);
  tcase_add_test(tc, test_sub_38);
  tcase_add_test(tc, test_sub_39);
  tcase_add_test(tc, test_sub_40);
  tcase_add_test(tc, test_sub_41);
  tcase_add_test(tc, test_sub_42);
  tcase_add_test(tc, test_sub_43);
  tcase_add_test(tc, test_sub_44);
  tcase_add_test(tc, test_sub_45);
  tcase_add_test(tc, test_sub_46);
  tcase_add_test(tc, test_sub_47);
  tcase_add_test(tc, test_sub_48);
  tcase_add_test(tc, test_sub_49);
  tcase_add_test(tc, test_sub_50);
  tcase_add_test(tc, test_sub_51);
  tcase_add_test(tc, test_sub_52);
  tcase_add_test(tc, test_sub_53);
  tcase_add_test(tc, test_sub_54);
  tcase_add_test(tc, test_sub_55);
  tcase_add_test(tc, test_sub_56);
  tcase_add_test(tc, test_sub_57);
  tcase_add_test(tc, test_sub_58);
  tcase_add_test(tc, test_sub_59);
  tcase_add_test(tc, test_sub_60);
  tcase_add_test(tc, test_sub_61);
  tcase_add_test(tc, test_sub_62);
  tcase_add_test(tc, test_sub_63);
  tcase_add_test(tc, test_sub_64);
  tcase_add_test(tc, test_sub_65);
  tcase_add_test(tc, test_sub_66);
  tcase_add_test(tc, test_sub_67);
  tcase_add_test(tc, test_sub_68);
  tcase_add_test(tc, test_sub_69);
  tcase_add_test(tc, test_sub_70);
  tcase_add_test(tc, test_sub_71);
  tcase_add_test(tc, test_sub_72);
  tcase_add_test(tc, test_sub_73);
  tcase_add_test(tc, test_sub_74);
  tcase_add_test(tc, test_sub_75);
  tcase_add_test(tc, test_sub_76);
  tcase_add_test(tc, test_sub_77);
  tcase_add_test(tc, test_sub_78);
  tcase_add_test(tc, test_sub_79);
  tcase_add_test(tc, test_sub_80);
  tcase_add_test(tc, test_sub_81);
  tcase_add_test(tc, test_sub_82);
  tcase_add_test(tc, test_sub_83);
  tcase_add_test(tc, test_sub_84);
  tcase_add_test(tc, test_sub_85);
  tcase_add_test(tc, test_sub_86);
  tcase_add_test(tc, test_sub_87);
  tcase_add_test(tc, test_sub_88);
  tcase_add_test(tc, test_sub_89);
  tcase_add_test(tc, test_sub_90);

  suite_add_tcase(suite, tc);
  return suite;
}