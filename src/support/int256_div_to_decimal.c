#include "../s21_decimal.h"

uint32_t int256_div_to_decimal(s21_int256 res) {
  uint32_t result = 0;

  if (!int256_equal_zero(res)) {
    s21_int256 max_decim = {
        {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0, 0x0, 0x0, 0x0}};
    // находим насколько результат больше максимального 96 битного числа
    s21_int256 grade = mantissa_div(&res, &max_decim, NULL);

    // ищем ближайшую степень 10 больше степени grade
    while (1) {
      int is_greater = int256_is_greater(grade, int256_pow_ten(result));
      if (!is_greater) {
        break;
      }
      result++;
    }

    // проверяем, что степень подобрана точно
    s21_int256 res256 = int256_pow_ten(result);
    s21_int256 check = mantissa_div(&res, &res256, NULL);

    // Проверяем, содержат ли элементы массива check, начиная с 4-го элемента,
    // значащие биты.
    bool should_break = false;
    for (int i = 3; i < 8 && !should_break; i++) {
      if (check.bits[i] != 0x0) {
        result++;
        should_break = true;
      }
    }
  }
  return result;
}
