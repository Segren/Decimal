#include "../s21_decimal.h"

int div_remainder(s21_int256 *res, s21_decimal *result,
                  const s21_int256 *eq_value_2, s21_int256 *remainder) {
  int status = OK;
  s21_int256 bin_res = {{0x0}};
  // рассчитываем дробную часть и переносим ее в результат(в remainder останется
  // остаток от деления не поместившийся в дробную часть)
  uint8_t exp_1 = remainder_transform(res, eq_value_2, remainder);
  // расчет степени остатка
  uint8_t exp_2 = remainder_transform(&bin_res, eq_value_2, remainder);

  // установка степени остатка
  s21_decimal dec_bin_res = {{0x0}};
  int256_to_decimal(&bin_res, &dec_bin_res);
  set_exponent(&dec_bin_res, exp_2);

  // корректировка остатка
  s21_decimal dec_five = {{0x5, 0x0, 0x0, 0x10000}};
  s21_decimal min = {{0x1, 0x0, 0x0, 0x1C0000}};
  // если остаток равен 0.5, но после расчетов remainder не равен 0,то
  // корректируем остаток тк по факту он больше 0.5
  if (s21_is_equal(dec_bin_res, dec_five) && !int256_equal_zero(*remainder)) {
    s21_add(dec_bin_res, min, &dec_bin_res);
  }
  // банковское округление
  round_uint256_bankers(res, &dec_bin_res);

  s21_decimal dec_res = {{0x0}};
  int check = int256_to_decimal(res, &dec_res);
  // устанавливаем степень результата
  set_exponent(&dec_res, exp_1);

  if (check == ERROR) {
    status = TOO_LARGE_OR_POS_INF;
    *result = get_inf_result();
  } else {
    *result = dec_res;
  }

  return status;
}