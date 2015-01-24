#include "expr_assert.h"
#include "arrayUtil.h"

#define log(test_description) int log = (printf("\t     %s\n\n", test_description))
#define sizeOf_char sizeof(char)
#define sizeOf_int sizeof(int)
#define sizeOf_float sizeof(float)
#define sizeOf_double sizeof(double)
#define sizeOf_String sizeof(String)
#define sizeOf_Student sizeof(Student)
#define sizeOf_int10 sizeof(int10)
#define sizeOf_float5 sizeof(float5)
#define sizeOf_void_star sizeof(void_star)
#define sizeOf_char_star sizeof(char_star)
#define sizeOf_int_star sizeof(int_star)
#define sizeOf_float_star sizeof(float_star)
#define YES 1
#define NO 0

typedef char String[256];
typedef int int10[10];
typedef float float5[5];
typedef struct Stud { char name[27]; int std; float percentage; } Student;
typedef void *void_star;
typedef char *char_star;
typedef int *int_star;
typedef float *float_star;

ArrayUtil utils[3];
int array_1[1] = {1};
int array_1_2[2] = {1, 2};
int array_1_3[2] = {1, 3};
int array_0_0[2] = {0, 0};
int array_1_0[2] = {1, 0};
char array_null_null[2] = {'\0', '\0'};
float array_flt_flt[2] = {0, 0};
double array_dble_dble[2] = {0, 0};
String array_empty_strings[2] = {"", ""};
void_star array_void_stars[1] = {0x0};
char_star array_char_stars[1] = {(char *)('\0')};
int_star array_int_stars[1] = {(int *)(0)};
// float_star array_float_stars[1] = {(float **)(0.0)};

int10 array_int10_0s[1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
float5 array_float5_0s[1] = {{0.0, 0.0, 0.0, 0.0, 0.0}};
Student array_Students[1] = {{"", 0, 0.0}};


void test_create_001(){
    log("returns an ArrayUtil with bytes initialized to ZERO for int");
    ArrayUtil util1 = {array_0_0, sizeOf_int, 2};
    ArrayUtil util2 = create(sizeOf_int, 2);
    assertEqual(areEqual(util1, util2), YES);
    dispose(util2);
}
