#include "expr_assert.h"
#include "arrayUtil.h"

#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)

#define null '\0'

typedef char* String; 
ArrayUtil util, resultUtil, expectedUtil;
int sample[] = {1,2,3,4,5};
//-----------------------------------------------Helper Functions --------------------------------
int isEven(void *hint, void *item){
    int *numberPtr = (int*)item;
    return *numberPtr % 2 ? 0 : 1;
}

int isDivisible(void *hint, void *item){
    int *numberPtr = (int*)item;
    int *hintPtr = (int*)hint;
    return *numberPtr % *hintPtr ? 0 : 1;
}

void increment(void* hint, void* sourceItem, void* destinationItem){
    int *hintPtr = (int*)hint;
    int *numberPtr = (int*)sourceItem;
    int *resultPtr = (int*)destinationItem;

    *resultPtr = *numberPtr + *hintPtr;
}

void toChar(void* hint, void* sourceItem, void* destinationItem){
    int *numberPtr = (int*)sourceItem;
    int *charPtr = (int*)destinationItem;
    *charPtr = *numberPtr;
}


void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
    ArrayUtil a = create(1,3);
    assert(a.length == 3);
    assert(a.typeSize == 1);
    dispose(a);
}

void test_resize_should_grow_length_of_array_and_set_them_to_zero_when_new_size_is_more(){
    ArrayUtil a = create(4,2), b;
    int i;
    b = resize(a,5);
    assert(b.length == 5);
    dispose(a);
}

void test_resize_should_not_change_length_of_array_when_new_size_is_same_as_old_size(){
    ArrayUtil a = create(1,5);
    int i;
    a = resize(a,5);
    assert(a.length == 5);
    dispose(a);
}
