#include "expr_assert.h"
#include "arrayUtil.h"

ArrayUtil util,expectedUtil;

void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
    int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
    ArrayUtil a_array = {a,sizeof(int),8};
    ArrayUtil b_array = {b,sizeof(int),5};
    assertEqual(areEqual(a_array, b_array),0);
}

void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
    double doubleArray[] = {0,0,0,0};
    expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
    util = create(sizeof(double),4);
    assertEqual(areEqual(expectedUtil,util),1);
    dispose(util);
}

void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
    int intArray[] = {0,0,0,0};
    expectedUtil = (ArrayUtil){intArray,sizeof(int),4};
    util = create(sizeof(int),4);
    assertEqual(areEqual(expectedUtil,util),1);
    dispose(util);
}
