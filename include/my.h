/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** Write your my.h header file that contains the prototypes
** of all the functions exposed by your libmy.a
*/

#ifndef MY_H
    #define MY_H
    #define SUCCESS 0
    #define ERROR 84
    #define IN 1
    #define OUT -1
    #define NOT_FOUND -1

int my_putchar(char);
int my_putchar_err(char);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_unbr(unsigned int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strstrlen(char **str);
char **my_str_to_line_array(char *array);
char *my_nb_to_str(int nb);
int fs_open_file(char const *filePath);
int my_getnbr_size(int nb);
char **my_str_to_word_array(char const *str);
char **my_pimp_str_to_wa(char *str, char *delim);
int mini_printf(char const *format, ...);
char *my_strdup(const char *s);
void my_strstrfree(char **array);
char *my_nb_to_str_base(int nb, int base);
char **my_tuned_str_to_wa(char *str, char **delim);
int my_strstr_contains(char *str, char **delim);

#endif /*MY_H*/
