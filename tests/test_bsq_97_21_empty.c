/*
** EPITECH PROJECT, 2019
** Test bsq()
** File description:
** Test a function
*/

#include <criterion/criterion.h>
#include <my.h>
#include <bsq.h>

Test(bsq, intermediate_map_97_21_empty)
{
    char map_test[] = "mouli_maps/"
    "intermediate_map_97_21_empty";
    char map_expected[] = "mouli_maps_solved/"
    "intermediate_map_97_21_empty";
    buffer_t *buffer = bsq(map_test);
    buffer_t *result = read_buffer(map_expected);

    cr_expect_str_eq(buffer->string, result->string);
    free_buffer(&buffer);
    free_buffer(&result);
}
