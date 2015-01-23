#include "expr_assert.h"
#include "arrayUtil.h"

typedef char*  String;

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
    double a [] = {2.34};
    double b [] = {2.34};
    ArrayUtil array1 = {a, sizeof(double), 1};
    ArrayUtil array2 = {b, sizeof(double), 1};

    assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
    String a[] = {"hello"};
    String b[] = {"hello"};
    ArrayUtil array1 = {a, sizeof(String), 1};
    ArrayUtil array2 = {b, sizeof(String), 1};

    assert(areEqual(array1,array2));
};
