#include "../../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result_conv = OK;
  init_with_zero_decimal(dst);
  if (!isinf(src) && !isnan(src)) {
    if (src != 0) {
      int sign = (src < 0) ? 1 : 0;
      int exp;
      double temp = (double)fabsl(src);
      frexp(temp, &exp);

      int offset = 0;
      while (offset < MAX_EXP && (int)temp / (int)pow(2, 21) == 0) {
        temp *= 10;
        offset++;
      }
      temp = round(temp);
      if (offset <= MAX_EXP && (exp >= -95 && exp <= 96)) {
        f_bits f = {0};
        temp = (float)temp;
        while (fmod(temp, 10) == 0 && offset > 0) {
          temp /= 10;
          offset--;
        }
        f.f = (float)temp;
        frexp(temp, &exp);
        exp -= 1;
        dst->bits[exp / 32] |= 1 << exp % 32;
        for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
          if ((f.bits & (1 << j)) != 0) {
            dst->bits[i / 32] |= 1 << i % 32;
          }
        }
        set_sign(dst, sign);
        set_exponent(dst, offset);
      }
    } else {
      int sign = (signbit(src) != 0) ? 1 : 0;
      set_sign(dst, sign);
    }
  } else {
    result_conv = ERROR;
  }
  return result_conv;
}