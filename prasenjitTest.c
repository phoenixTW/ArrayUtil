#include "expr_assert.h"
#include "arrayUtil.h"

int isDivisible(void* a,void *b){
    return ((*((int*)b))%(*((int*)a)) == 0) ? 1 : 0;
}
int isUpperCase(void* a,void *b){
    return (*((char*)b) >= 'A' && *((char*)b) <= 'Z') ? 1 : 0;
}
void intAddOperation(void* hint, void* item) {
    *((int *)item) = *((int *)hint) + *((int *)item);    
}

void intConvertFunc(void* hint, void* sourceItem, void* destinationItem){
    *((int *)destinationItem) = *((int *)hint) + *((int *)sourceItem);
}

void charConvertFunc(void* hint, void* sourceItem, void* destinationItem){
    *((char*)destinationItem) = *((char*)sourceItem) - 32;
}

int isEven(void *hint, void *element) {
    int* _hint = (int*)hint;
    int* _element = (int*)element; 
    return (((*_element) % 2) == 0) ? 1 : 0;
}

void test_create_returns_same_array_if_array_lengths_are_same_and_values_are_same() {
    ArrayUtil a,b;
    int expected = 1,actual;
    a = create(sizeof(int),2);
    b = create(sizeof(int),2);
    assert(areEqual(a,b) == 1);
}

void test_filter_gives_2_4_for_1_2_3_4_5(){
    ArrayUtil util = create(sizeof(int),5);
    int *arr, i, result, hint = 2, *lIst;
    void* list;
    arr = (int*)util.base;

    list = (int*)malloc(sizeof(int) * 2);
    
    for(i=0; i<5; i++){
        arr[i] = i+1;
    }

    result = filter(util, isDivisible, &hint, &list, 2);
    lIst = (int*)list;
    assertEqual(result,2);
    assertEqual(lIst[0],2);
    assertEqual(lIst[1],4);
    free(list); 
}

void test_filter_gives_D_E_for_a_b_c_D_E() {
    ArrayUtil a = {(char[]){'a','b','c','D','E'},sizeof(char),5};
    char *result,hint = 'a',*lIst;
    void* list;
    int count;
    list = (char*)malloc(sizeof(char) * 2);
    count =  filter(a,isUpperCase,&hint,&list,2);
    lIst = (char*)list;
    assertEqual(count, 2);
    assertEqual(lIst[0],'D');
    assertEqual(lIst[1],'E');
    free(list); 
}

void test_findLast_returns_null_if_there_is_no_match_in_integer_array(){
    ArrayUtil a = {(int[]){1,3,5,7,9}, sizeof(int), 5};
    int x = 2;
    assertEqual((int*)findLast(a,isEven,&x), 0);
}

// void test_findLast_returns_the_last_element_if_there_is_match_in_character_array(){
//     ArrayUtil a = {(char[]){'a','b','C','D','e'}, sizeof(char), 5};
//     int x = 'D';
//     assertEqual(((char*)findLast(a, isUpperCase, &x)),'D');
// }

void test_findLast_returns_the_last_element_if_there_is_match_in_integer_array(){
    ArrayUtil a = {(int[]){1,3,5,8,10},sizeof(int),5};
    int x = 2;
    assertEqual(((int*)findLast(a,isEven,&x)),10);
}
