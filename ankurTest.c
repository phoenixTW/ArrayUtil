#include "expr_assert.h"
#include "arrayUtil.h"

#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)


int isEven(void *hint,void *item){
    return *((int*)item)%2==0;
}



void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
    int array1[]={1,2,3,4,5};
    char array2[]={'a','b','c','d','\0'};
    ArrayUtil u1={array1,INT_SIZE,5};
    ArrayUtil u2={array2,CHAR_SIZE,5};
    assertEqual(areEqual(u1,u2), 0);
}

void test_filter_fills_filtered_array_with_even_numbers_of_existing_array_and_returns_count(){
    int array[]={1,2,3,4,5,6,7,8};
    int newArray[]={2,4,6,8};
    ArrayUtil util={array,INT_SIZE,8};
    int *filtered=(int *)malloc(INT_SIZE*5);
    int counter=filter(util,isEven,0,(void**)filtered,5);
     assertEqual(counter,4);
     free(filtered);
}

void test_filter_returns_0_when_there_are_no_enven_no_in_existing_array(){
    int array[]={1,3,5,7};
    ArrayUtil util={array,INT_SIZE,4};
    int *filtered=(int *)malloc(INT_SIZE*2);
    int counter=filter(util,isEven,0,(void**)filtered,2);
     assertEqual(counter,0);
     free(filtered);
}

