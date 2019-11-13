/*
** EPITECH PROJECT, 2019
** Test bsq()
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <my.h>
#include <bsq.h>

Test(bsq, map_no_existing)
{
    cr_expect_null(bsq("unknown_map"));
}

Test(bsq, no_lines)
{
    cr_expect_null(bsq("tests/map_no_lines"));
}

Test(bsq, invalid_first_line)
{
    cr_expect_null(bsq("tests/map_invalid_first_line"));
    cr_expect_null(bsq("tests/map_invalid_first_line_2"));
}

Test(bsq, invalid_nb_given)
{
    cr_expect_null(bsq("tests/map_invalid_nb_given"));
    cr_expect_null(bsq("tests/map_invalid_nb_given_2"));
}

Test(bsq, invalid_columns)
{
    cr_expect_null(bsq("tests/map_invalid_columns"));
    cr_expect_null(bsq("tests/map_invalid_columns_2"));
}

Test(bsq, invalid_chars)
{
    cr_expect_null(bsq("tests/map_invalid_chars"));
}
