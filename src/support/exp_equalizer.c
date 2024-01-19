#include "../s21_decimal.h"

void exp_equalizer(s21_decimal *value_1, s21_decimal *value_2,
                   s21_int256 *eq_value_1, s21_int256 *eq_value_2) {
  uint8_t exp_1 = get_exponent(value_1);
  uint8_t exp_2 = get_exponent(value_2);
  s21_int256 tmp_1 = decimal_to_int256(value_1);
  s21_int256 tmp_2 = decimal_to_int256(value_2);

  if (exp_1 > exp_2) {
    s21_int256 diff_2 = int256_pow_ten(exp_1 - exp_2);
    *eq_value_1 = tmp_1;
    *eq_value_2 = int256_mantissa_mul(&tmp_2, &diff_2);
  } else if (exp_1 < exp_2) {
    s21_int256 diff_1 = int256_pow_ten(exp_2 - exp_1);
    *eq_value_1 = int256_mantissa_mul(&tmp_1, &diff_1);
    *eq_value_2 = tmp_2;
  } else {
    *eq_value_1 = tmp_1;
    *eq_value_2 = tmp_2;
  }
}