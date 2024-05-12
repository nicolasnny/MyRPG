/*
** EPITECH PROJECT, 2024
** unit_tests
** File description:
** function that allow me to test my program
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "../include/rpg.h"

char **create_strstr(char *s1, char *s2, char *s3, char *s4);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/* error handling */

Test(unit_test, err_handling, .init=redirect_all_stdout)
{
    char **av = create_strstr("./rpg", "hello", "sompthing", "test");
    char **av2 = malloc(sizeof(char *) * 2);

    av2[0] = strdup("./my_rpg");
    av2[1] = NULL;
    cr_assert_eq(err_handling(4, av), ERROR);
    cr_assert_eq(err_handling(1, av2), SUCCESS);   
}

/* initialisation*/

Test(unit_test, init_args, .init=redirect_all_stdout)
{
    parameters_t params = {0};

    cr_assert_eq(init_args(&params), SUCCESS);
}

Test(unit_test, get_map, .init=redirect_all_stdout)
{
    parameters_t params = {0};

    cr_assert_eq(init_args(&params), SUCCESS);
    cr_assert(params.sys);
    cr_assert(get_map(MAP_ARRAY_PATH, params.sys));
}

/* utilities */

Test(unit_test, file_content, .init=redirect_all_stdout)
{
    cr_assert(get_file_content(MAP_ARRAY_PATH));
}

Test(unit_test, read_file, .init=redirect_all_stdout)
{
    cr_assert_neq(read_open(MAP_ARRAY_PATH), OPEN_ERROR);
}

Test(unit_test, open_append, .init=redirect_all_stdout)
{
    cr_assert_neq(open_append(MAP_ARRAY_PATH), OPEN_ERROR);
}

Test(unit_test, get_file_size, .init=redirect_all_stdout)
{
    cr_assert_neq(get_file_size(MAP_ARRAY_PATH), OPEN_ERROR);
}

Test(unit_test, strstr_functions, .init=redirect_all_stdout)
{
    char **array = create_strstr("test", "1", "2", "3");

    cr_assert(array);
    cr_assert_eq(my_strstrlen(array), 4);
    free_str_array(array);
}

/* end of programm*/

Test(unit_test, clean, .init=redirect_all_stdout)
{
    parameters_t params = {0};

    cr_assert_eq(init_args(&params), SUCCESS);
    cr_assert(params.sys);
    cr_assert(get_map(MAP_ARRAY_PATH, params.sys));
    clean(&params);
}
