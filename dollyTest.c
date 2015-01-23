#include "expr_assert.h"
#include "arrayUtil.h"

#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)

void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
    int x = 'a';
    char array[] = "car";
    ArrayUtil util = create(CHAR_SIZE,3);
    util.base = (void*)array;
    assertEqual(findIndex(util,&x),1);
}
