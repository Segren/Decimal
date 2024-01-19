#include "../s21_decimal.h"

int div_decimal(s21_decimal *value_1, s21_decimal *value_2,
                s21_decimal *result) {
  int status = OK;
  // общая степень после деления
  s21_int256 eq_value_1 = {{0x0}};
  s21_int256 eq_value_2 = {{0x0}};
  exp_equalizer(value_1, value_2, &eq_value_1, &eq_value_2);

  s21_int256 remainder = {{0x0}};
  // общая мантисса
  s21_int256 res = mantissa_div(&eq_value_1, &eq_value_2, &remainder);
  // находим последний значимый бит
  int l_bit = find_last_significant_bit(&res);
  if (l_bit >= DECIM_MAX_BITS) {
    status = TOO_LARGE_OR_POS_INF;
    *result = get_inf_result();
  } else {
    // учет остатка и степени
    status = div_remainder(&res, result, &eq_value_2, &remainder);

    // проверяем ситуацию, где результат меньше 1e-28, но больше 0
    if (status == OK && is_dec_zero(*result)) {
      status = TOO_SMALL_OR_NEG_INF;
    }
  }
  return status;
}