/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** 
*/

#include "eval.h"
#include "infin_add.h"

#ifndef __MY_H__
#define __MY_H__


char *infin_add(char *a, char *b, int nb);
char *my_itoa(int value);
char *eval_expr(char const *str, int nb);
void my_inpar(char *str, array_t *cal, int nb);
int my_nb_nb(char *str);
int my_nbs(char *str, int count, int nb);
void nbs(char *str, array_t *cal, int nb);
void my_array_swap(array_t *cal);
void my_pre_inpar(char *str, array_t *cal, int nb);
void my_par_is_first(char *str, array_t *cal, int nb);
char *addition(char *nb1, char *nb2, int nb);
char *soustraction(char *nb1, char *nb2, int nb);
char *multiplication(char *nb1, char *nb2, int nb);
char *division(char *nb1, char *nb2, int nb);
char *modulos(char *nb1, char *nb2, int nb);
char *my_doop(char *a1, char *a2, char *a3, int nb);
char *my_pre_use_doop(char **str, int nb);
int checker(char *str, char c);
char *my_strdup(char const *str);
int my_str_isnum(char *str, int nb);
int size_base(char *argv);
char *my_replacer(char *argv, char const *buff, char *cpy, char *str);
char *my_numbers(char *argv1, char const *buff, char *cpy);
char *my_operators(char *argv2, char const *buff, char *cpy);
char *my_reader(char *buff);
char *my_combiner(char *argv1, char *argv2, char *cpy);
char *my_translator(char *cpy, char *result);
char *my_duprev(char const *str);
char *my_infin_div(char *div, char *divisor, int nb);
char *my_infin_mod(char *div, char *divisor, int nb);
char my_rep(char *rest, char *div, int nb);
int div_step(char *rest, char *div, char *divisor, int start);
int my_compar(char *big, char *small);
int my_first_div(char *rest, char *div, char *divisor);
char *my_is_it_neg(char *av);
char *my_del_blanc(int i, char *cpy);
char *my_cpy_to_cpy(char *cpy, char *prty);
char *my_priorities(char *cpy, int base);
char *infin_mult(char *nb1, char *nb2, int base);
char *error(char *base, char *ops, int nb_dig, int ac);
int my_h(void);
//lib
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char *str);
char *my_revstr(char *str);
void my_putstr(char *str);
int  my_strcmp(char const *s1, char const *s2);
#endif
