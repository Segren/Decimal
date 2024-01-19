#include "../s21_decimal.h"

void round_uint256_bankers(s21_int256 *value, const s21_decimal *remainder) {
  s21_decimal dec_five = {{0x5, 0x0, 0x0, 0x10000}};
  s21_int256 one = {{0x00000001, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
  // проверка на необходимость округления
  if (s21_is_greater(*remainder, dec_five)) {
    // округляем вверх
    *value = mantissa_add(*value, one);
  } else if (s21_is_equal(*remainder, dec_five)) {
    // округляем до ближайшего четного значения
    if ((value->bits[0] & 1) == 1) {
      // если младший бит нечетный, округляем вверх
      *value = mantissa_add(*value, one);
    }
    // если младший бит четный, ничего не делаем(округляем вниз)
  }
  // если остаток меньше 5, ничего не делаем
}