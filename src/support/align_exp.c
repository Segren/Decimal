#include "../s21_decimal.h"

void align_exp(s21_decimal *dec_1, s21_decimal *dec_2, s21_int256 *man_1,
               s21_int256 *man_2) {
  uint8_t exp_1 = get_exponent(dec_1);
  uint8_t exp_2 = get_exponent(dec_2);
  s21_int256 ten = {{0x000000A, 0x0, 0x0, 0x0}};

  // конвертация мантиссы из типа decimal в тип int256
  *man_1 = decimal_to_int256(dec_1);
  *man_2 = decimal_to_int256(dec_2);

  while (exp_1 > MAX_EXP) {
    *man_1 = mantissa_div(man_1, &ten, NULL);
    exp_1--;
  }
  while (exp_2 > MAX_EXP) {
    *man_2 = mantissa_div(man_2, &ten, NULL);
    exp_2--;
  }
  while (exp_1 > exp_2) {
    *man_2 = int256_mantissa_mul(man_2, &ten);
    exp_2++;
  }
  while (exp_1 < exp_2) {
    *man_1 = int256_mantissa_mul(man_1, &ten);
    exp_1++;
  }

  set_exponent(dec_1, exp_1);
  set_exponent(dec_2, exp_2);
}