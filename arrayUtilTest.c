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

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_are_not_same () {
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

void test_areEqual_for_char_should_return_1_when_two_array_util_elements_are_same () {
	ArrayUtil array1, array2;
	char *a1, *a2;
	int isSuccess;

	array1.typeSize = sizeof(char);
	array1.length = 2;

	array2.typeSize = sizeof(char);
	array2.length = 2;

	a1 = (char*)malloc(array1.typeSize * array1.length);
	a2 = (char*)malloc(array2.typeSize * array2.length);

	a1[0] = 'c'; a1[1] = 'd';
	a2[0] = 'c'; a2[1] = 'd';
	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 1);
	free(a1);
	free(a2);

}

void test_areEqual_for_char_should_return_1_when_two_array_util_elements_are_not_same () {
	ArrayUtil array1, array2;
	char *a1, *a2;
	int isSuccess;

	array1.typeSize = sizeof(char);
	array1.length = 2;

	array2.typeSize = sizeof(char);
	array2.length = 2;

	a1 = (char*)malloc(array1.typeSize * array1.length);
	a2 = (char*)malloc(array2.typeSize * array2.length);

	a1[0] = 'c'; a1[1] = 'd';
	a2[0] = 'c'; a2[1] = 'f';
	array1.base = a1;
	array2.base = a2;

	isSuccess = areEqual(array1, array2);

	assertEqual(isSuccess, 0);
	free(a1);
	free(a2);
}

void test_should_return_1_when_two_same_type_of_array_are_created_as_int_type () {
	ArrayUtil array1, array2;
	int isSuccess, sizeofInt;
	sizeofInt = sizeof(int);
	array1 = create(sizeofInt, 2);
	array2 = create(sizeofInt, 2);

	isSuccess = areEqual(array1, array2);
	assertEqual(isSuccess, 1);
	free(array1);
	free(array2);
}

void test_should_return_0_when_two_different_size_of_array_are_created_as_int_type () {
	ArrayUtil array1, array2;
	int isSuccess, sizeofInt;
	sizeofInt = sizeof(int);
	array1 = create(sizeofInt, 2);
	array2 = create(sizeofInt, 3);

	isSuccess = areEqual(array1, array2);
	assertEqual(isSuccess, 0);
	free(array1);
	free(array2);
}

void test_should_return_0_when_two_different_type_of_array_are_created_as_int_type () {
	ArrayUtil array1, array2;
	int isSuccess, sizeofInt;
	sizeofInt = sizeof(float);
	array1 = create(sizeofInt, 2);
	array2 = create(sizeof(int), 2);

	((float*)(array1.base))[0] = 1.2;

	isSuccess = areEqual(array1, array2);
	assertEqual(isSuccess, 0);
	free(array1);
	free(array2);
}

void test_should_return_1_when_two_float_type_of_array_are_created_whose_length_are_same () {
	ArrayUtil array1, array2;
	int isSuccess, sizeofFloat;
	sizeofFloat = sizeof(float);
	array1 = create(sizeofFloat, 2);
	array2 = create(sizeofFloat, 2);

	isSuccess = areEqual(array1, array2);
	assertEqual(isSuccess, 1);
	free(array1);
	free(array2);
}

void test_should_return_0_when_one_float_and_one_char_type_of_array_are_created_whose_length_are_same () {
	ArrayUtil array1, array2;
	int isSuccess, sizeofFloat, sizeofChar;
	sizeofFloat = sizeof(float);
	sizeofChar = sizeof(char);
	array1 = create(sizeofFloat, 2);
	array2 = create(sizeofChar, 2);

	isSuccess = areEqual(array1, array2);
	assertEqual(isSuccess, 0);
	free(array1);
	free(array2);
}

void test_should_return_1_when_two_char_type_of_array_are_created_whose_length_are_same () {
	ArrayUtil array1, array2;
	int isSuccess, sizeofChar;
	sizeofChar = sizeof(char);
	array1 = create(sizeofChar, 2);
	array2 = create(sizeofChar, 2);

	isSuccess = areEqual(array1, array2);
	assertEqual(isSuccess, 1);
	free(array1);
	free(array2);
}

void test_should_compress_the_size_of_an_array () {
	ArrayUtil array1;
	int isSuccess, sizeofChar;
	sizeofChar = sizeof(char);
	array1 = create(sizeofChar, 2);

	((char*)(array1.base))[0] = 'c';
	((char*)(array1.base))[1] = 'd';

	array1 = resize(array1, 3);
	assertEqual(array1.length, 3);
	assertEqual(((char*)(array1.base))[0], 'c');
	assertEqual(((char*)(array1.base))[1], 'd');
	assertEqual(((char*)(array1.base))[2], 0);
}

void test_should_compress_the_size_of_an_array_when_new_size_is_smaller_than_the_previous_size () {
	ArrayUtil array1;
	int isSuccess, sizeofChar;
	sizeofChar = sizeof(char);
	array1 = create(sizeofChar, 2);


	((char*)(array1.base))[0] = 'c';
	((char*)(array1.base))[1] = 'd';

	array1 = resize(array1, 1);

	assertEqual(array1.length, 1);
	assertEqual(((char*)(array1.base))[0], 'c');
}

void test_findIndex_should_give_2_as_index_of_the_array () {
	ArrayUtil array1;
	int *a, sizeofInt, element;
	sizeofInt = sizeof(int);
	array1 = create(sizeofInt, 2);

	a = ((int*)(array1.base));

	a[0] = 1;
	a[1] = 2;

	element = 2;

	assertEqual(findIndex(array1, &element), 1);
	element = 1;
	assertEqual(findIndex(array1, &element), 0);
}

void test_findIndex_should_give_minus_1_as_index_of_the_array () {
	ArrayUtil array1;
	int *a, sizeofInt, element;
	sizeofInt = sizeof(int);
	array1 = create(sizeofInt, 2);

	a = ((int*)(array1.base));

	a[0] = 1;
	a[1] = 2;

	element = 3;

	assertEqual(findIndex(array1, &element), -1);
}

void test_findIndex_should_give_minus_1_as_index_of_the_float_type_array () {
	ArrayUtil array1;
	int *a, sizeofFloat;
	float element;
	sizeofFloat = sizeof(float);
	array1 = create(sizeofFloat, 2);

	a = ((float*)(array1.base));

	a[0] = 1.1;
	a[1] = 2.4;

	element = 1.3;

	assertEqual(findIndex(array1, &element), -1);
}

void test_findIndex_should_give_0_as_index_of_the_float_type_array () {
	ArrayUtil array1;
	int sizeofFloat;
	float element, *a;
	sizeofFloat = sizeof(float);
	array1 = create(sizeofFloat, 2);

	a = ((float*)(array1.base));

	a[0] = 1.1;
	a[1] = 2.4;

	element = 1.1;

	assertEqual(findIndex(array1, &element), 0);
}

void test_findIndex_should_give_1_as_index_of_the_float_type_array () {
	ArrayUtil array1;
	int sizeofFloat;
	float element, *a;
	sizeofFloat = sizeof(float);
	array1 = create(sizeofFloat, 2);

	a = ((float*)(array1.base));

	a[0] = 1.1;
	a[1] = 2.4;

	element = 2.4;

	assertEqual(findIndex(array1, &element), 1);
}

// void test_findIndex_should_give_0_as_index_of_the_char_type_array () {
// 	ArrayUtil array1;
// 	int sizeofchar;
// 	char element, *a;
// 	sizeofchar = sizeof(char);
// 	array1 = create(sizeofchar, 2);

// 	a = ((char*)(array1.base));

// 	a[0] = 'a';
// 	a[1] = 'b';

// 	element = 'a';

// 	assertEqual(findIndex(array1, &element), 0);
// }