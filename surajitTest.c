#include "expr_assert.h"
#include "arrayUtil.h"
#include <stdlib.h>
#define SIZEOF_INT sizeof(int)
#define SIZEOF_FLOAT sizeof(float)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_DOUBLE sizeof(double)

void test_resize_add_0_to_the_new_places_created_in_integer_array(){
    ArrayUtil array2, util1, expected;
    int *array, *arr;
    util1 = create(SIZEOF_INT, 3);
    expected = create(SIZEOF_INT, 5);

    array = ((int*)(util1.base));
    arr = ((int*)(expected.base));

    array[0] = 1; array[1] = 2; array[2] = 3;
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 0; arr[4] = 0;
	
	array2 =  resize(util1,5);

    assert(areEqual(array2 , expected));

   	dispose(array2);
   	dispose(util1);
   	dispose(expected);
}
