#ifndef TEST_RUNNER_H_
#define TEST_RUNNER_H_

#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

#define SEP "|================================|"
Suite *s21_equal_cases(void);
Suite *s21_not_equal_cases(void);
Suite *s21_is_less_cases(void);
Suite *s21_is_greater_cases(void);
Suite *s21_is_less_or_equal_cases(void);
Suite *s21_is_greater_or_equal_cases(void);
Suite *s21_negate_cases(void);
Suite *s21_truncate_cases(void);
Suite *s21_floor_cases(void);
Suite *s21_round_cases(void);
Suite *s21_mul_cases(void);
Suite *s21_add_cases(void);
Suite *s21_div_cases(void);
Suite *s21_sub_cases(void);
Suite *s21_from_int_to_decimal_cases(void);
Suite *s21_from_decimal_to_int_cases(void);
Suite *s21_from_float_to_decimal_cases(void);
Suite *s21_from_decimal_to_float_cases(void);

#endif  // TEST_RUNNER_H_
