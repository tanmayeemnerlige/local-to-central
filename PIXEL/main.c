#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"

int main()
{
    PiArray *test;
    Count count;

    test = initialize(10);

    assert(test->c_size == 0);
    assert(test->t_size == 10);

    assert(insert_pixel(test, 238, 29, 104, 0.3));
    assert(test->c_size == 1);
    assert(count_red(test) == 0);

    assert(insert_pixel(test, 255, 0, 83, 0.6));
    assert(test->c_size == 2);
    assert(count_red(test) == 0);

    assert(insert_pixel(test, 255, 0, 0, 0.23));
    assert(test->c_size == 3);
    assert(count_red(test) == 1);

    assert(insert_pixel(test, 0, 255, 0, 0.734));
    assert(test->c_size == 4);
    assert(count_green(test) == 1);

    //printf("%f\n", test->point[2].opac);

    assert(insert_pixel(test, 0, 0, 255, 0.45));
    assert(test->c_size == 5);
    assert(count_blue(test) == 1);

    assert(set_opac(test, 1));
    assert(set_opac(test, 2));
    assert(set_opac(test, 5));

    //printf("%f\n", test->point[1].opac);

    assert(set_opac(test, 1));
    assert(set_opac(test, 2));
    assert(set_opac(test, 5));

    //printf("%f\n", test->point[1].opac);

    count = all_count(test);

    assert(count.red == 1);
    assert(count.green == 1);
    assert(count.blue == 1);

    return 0;
}
