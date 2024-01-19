#ifndef S21_SUPPORT_H_
#define S21_SUPPORT_H_

#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

void init_with_zero_decimal(s21_decimal *dec);
void set_sign(s21_decimal *dec, uint8_t sign);
uint8_t get_sign(s21_decimal *dec);
bool is_decimal_valid(const s21_decimal *dec);
uint8_t get_exponent(const s21_decimal *dec);
bool set_exponent(s21_decimal *dec, uint8_t exponent);
uint8_t get_bit(uint32_t number, uint8_t index);
uint8_t get_bit_from_int256(s21_int256 *man, uint8_t index);
int divide_by_integer(s21_decimal value, int num, s21_decimal *result);
int add_integer(s21_decimal value, int num, s21_decimal *result);
int div_by_integer(s21_decimal value, int num);
int add_positive_decimal(s21_decimal *dec_1, s21_decimal *dec_2,
                         s21_decimal *result);
void align_exp(s21_decimal *dec_1, s21_decimal *dec_2, s21_int256 *man_1,
               s21_int256 *man_2);
s21_int256 decimal_to_int256(s21_decimal *dec);
s21_int256 mantissa_add(s21_int256 mantissa_1, s21_int256 mantissa_2);
s21_int256 mantissa_sub(s21_int256 mantissa_1, s21_int256 mantissa_2);
int sub_decimal(s21_decimal *dec_1, s21_decimal *dec_2, s21_decimal *result);
int int256_to_decimal(s21_int256 *man, s21_decimal *dst);
int mul_decimal(s21_decimal *value_1, s21_decimal *value_2,
                s21_decimal *result);
s21_int256 mantissa_mul(s21_decimal *mantissa_1, s21_decimal *mantissa_2);
int div_decimal(s21_decimal *value_1, s21_decimal *value_2,
                s21_decimal *result);
s21_int256 mantissa_div(const s21_int256 *mantissa_1,
                        const s21_int256 *mantissa_2, s21_int256 *remainder);
void round_uint256_bankers(s21_int256 *value, const s21_decimal *remainder);
int find_last_significant_bit(const s21_int256 *man);
s21_int256 shift_right(s21_int256 number);
bool is_zero(s21_int256 number);
uint32_t int256_div_to_decimal(s21_int256 res);
bool int256_equal_zero(s21_int256 res);
s21_decimal get_inf_result(void);
int count_leading_zeroes(s21_int256 value);
bool int256_is_greater(s21_int256 i1, s21_int256 i2);
s21_int256 shift_left(s21_int256 number);
bool int256_set_bit(s21_int256 *dec, uint8_t number, uint8_t index);
s21_int256 int256_pow_ten(uint32_t pow);
s21_int256 int256_mantissa_mul(const s21_int256 *m1, const s21_int256 *m2);
bool is_dec_zero(s21_decimal number);
void exp_equalizer(s21_decimal *value_1, s21_decimal *value_2,
                   s21_int256 *eq_value_1, s21_int256 *eq_value_2);
int div_remainder(s21_int256 *res, s21_decimal *result,
                  const s21_int256 *eq_value_2, s21_int256 *remainder);
uint8_t remainder_transform(s21_int256 *res, const s21_int256 *eq_value_2,
                            s21_int256 *remainder);
uint8_t get_dec_bit(const s21_decimal *dec, int index);

#endif  // S21_SUPPORT_H_
