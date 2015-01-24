#include "expr_assert.h"
#include "arrayUtil.h"

ArrayUtil util1,util2;
typedef struct Student{
    int rollno;
    float age;
} student;

void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
    util1 = create(sizeof(student),1);    
    assert(areEqual(expected,util1));
};

int isEven(void *hint, void *element) {
    int* _hint = (int*)hint;
    int* _element = (int*)element; 
    return (((*_element) % 2) == 0) ? 1 : 0;
}


void test_filter_populate_destination_array_with_evenNumbers(){
    int maxItem=6;
    int *evens[maxItem];
    util1 = (ArrayUtil){(int[]){101,22,12,13},sizeof(int),4};
        
    assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
    assertEqual(*(evens[0]),22);
    // assertEqual(*(evens[1]),12);
}

void test_filter_populate_destination_array_until_hits_max_size_and_return_no_element_added_to_id(){
    int maxItem=2;
    int *evens [maxItem];
    util1 = (ArrayUtil){(int[]){101,22,12,14},sizeof(int),4};        

     assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
     assertEqual(*(evens[0]),22);
     // assertEqual(*(evens[1]),12);    
}
