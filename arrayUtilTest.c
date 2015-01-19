#include "expr_assert.h"
#include "arrayUtil.h"

void test_areEqual_should_return_1_when_two_array_util_are_same () {
	ArrayUtil array1, array2;
	int *a1, *a2;
	int isSuccess;

	array1.typeSize = sizeof(int);
	array1.length = 2;

	array2.typeSize = sizeof(int);
	array2.length = 2;

	a1 = (int*)malloc(array1.typeSize * array1.length);
	a2 = (int*)malloc(array2.typeSize * array2.length);

	a1[0] = 1; a1[1] = 2;
	a2[0] = 1; a2[1] = 2;

	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 1);
	free(a1);
	free(a2);

}

void test_areEqual_should_return_0_when_two_array_util_are_not_same () {
	ArrayUtil array1, array2;
	int *a1, *a2;
	int isSuccess;

	array1.typeSize = sizeof(int);
	array1.length = 3;

	array2.typeSize = sizeof(int);
	array2.length = 4;

	a1 = (int*)malloc(array1.typeSize * array1.length);
	a2 = (int*)malloc(array2.typeSize * array2.length);

	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 0);
	free(a1);
	free(a2);

}

void test_areEqual_should_return_0_when_two_array_util_elements_are_not_same () {
	ArrayUtil array1, array2;
	int *a1, *a2;
	int isSuccess;

	array1.typeSize = sizeof(int);
	array1.length = 3;

	array2.typeSize = sizeof(int);
	array2.length = 3;

	a1 = (int*)malloc(array1.typeSize * array1.length);
	a2 = (int*)malloc(array2.typeSize * array2.length);
	
	a1[0] = 1;

	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 0);
	free(a1);
	free(a2);

}

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_are_same () {
	ArrayUtil array1, array2;
	float *a1, *a2;
	float isSuccess;

	array1.typeSize = sizeof(float);
	array1.length = 2;

	array2.typeSize = sizeof(float);
	array2.length = 2;

	a1 = (float*)malloc(array1.typeSize * array1.length);
	a2 = (float*)malloc(array2.typeSize * array2.length);

	a1[0] = 1.1; a1[1] = 2.1;
	a2[0] = 1.1; a2[1] = 2.1;
	
	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 1);
	free(a1);
	free(a2);

}

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_not_are_same () {
	ArrayUtil array1, array2;
	float *a1, *a2;
	int isSuccess;

	array1.typeSize = sizeof(float);
	array1.length = 2;

	array2.typeSize = sizeof(float);
	array2.length = 2;

	a1 = (float*)malloc(array1.typeSize * array1.length);
	a2 = (float*)malloc(array2.typeSize * array2.length);

	a1[0] = 1.1; a1[1] = 1.1;
	a2[0] = 1.1; a2[1] = 2.6;
	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 0);
	free(a1);
	free(a2);

}