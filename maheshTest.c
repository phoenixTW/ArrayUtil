#include "expr_assert.h"
#include "arrayUtil.h"

typedef char*  String;

int isCapital(void *hint, void *item) {
	printf("%c\n", (*(char *)item));
    return((*(char *)item >=65) && (*(char *)item <= 91));
}

int isEven(void *hint, void *item) {
    return(*(int *)item%2==0);
}

int isGreaterThan5(void *hint, void *item) {
    return(*(float *)item > 5);
}

void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
    int array1[] = {1,2,3,4};
    char array2[] = {'m','a','h','e'};
    ArrayUtil util1 = {array1,sizeof(int),4};
    ArrayUtil util2 = {array2,sizeof(char),4};
    assertEqual(areEqual(util1, util2), 0);
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
    char array1[] = {'k','M','k'};
    ArrayUtil util1 = {array1, sizeof(char), 3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,'a')), 'M');
}

void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
    float array1[] = {1.1,6.6,5.5,8.8,2.2};
    ArrayUtil util1 ={array1, sizeof(float),5};
    assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), (float)6.6);
}

void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    String array1[] = {"Mahesh","Kumar","Kolla"};
    String element = "Kumar";
    ArrayUtil util1 = {array1,sizeof(String),3};
    assertEqual(findIndex(util1,&element), 1);
}

void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
    char array1[] = {'m','a','h','e','s','h'};
    char element = 's';
    ArrayUtil util1 = {array1,sizeof(char),6};
    assertEqual(findIndex(util1,&element), 4);
}

void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
    float array1[] = {1.1,2.2,3.3,4.4};
    float element = 4.4;
    ArrayUtil util1 = {array1,sizeof(float),4};
    assertEqual(findIndex(util1,&element), 3);
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
    int array1[] = {1,2,3,4,5};
    int element = 2;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(findIndex(util1,&element), 1);
}

void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    ArrayUtil util1, util2;
    String array1[] = {"Mahesh","Kumar"}, arr1, arr2;
    util1 = create(sizeof(String), 2);
    util2 = create(sizeof(String), 5);

    ((String*)(util1.base))[0] = "Mahesh";
    ((String*)(util1.base))[1] = "Kolla";
    ((String*)(util2.base))[0] = "Mahesh";
    ((String*)(util2.base))[1] = "Kolla";
    ((String*)(util2.base))[2] = 0;
    ((String*)(util2.base))[3] = 0;
    ((String*)(util2.base))[4] = 0;


    assertEqual(areEqual(resize(util1, 5), util2), 1);    
}

// void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
// 	ArrayUtil util1, util2;
//     util1 = create(sizeof(String), 3);
//     util2 = create(sizeof(String), 2);

//     ((String*)(util1.base))[0] = "Mahesh";
//     ((String*)(util1.base))[1] = "Kumar";
//     ((String*)(util1.base))[2] = "Kolla";
    
//     ((String*)(util2.base))[0] = "Mahesh";
//     ((String*)(util2.base))[1] = "Kolla";

//     assertEqual(areEqual(resize(util1, 2), util2), 1);    
// }
