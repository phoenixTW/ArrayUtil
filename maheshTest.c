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
