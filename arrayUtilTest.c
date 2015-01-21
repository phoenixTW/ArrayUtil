#include "expr_assert.h"
#include "arrayUtil.h"

void test_areEqual_should_return_1_when_two_array_util_are_same () {
	ArrayUtil util1 = { (int[]){1, 2}, sizeof(int), 2};
	ArrayUtil util2 = { (int[]){1, 2}, sizeof(int), 2};
	assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_should_return_0_when_two_array_util_are_not_same () {
	ArrayUtil util1 = { (int[]){1, 2, 3}, sizeof(int), 3};
	ArrayUtil util2 = { (int[]){1, 2}, sizeof(int), 2};
	assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_should_return_0_when_two_array_util_elements_are_not_same () {
	ArrayUtil util1 = { (int[]){1, 2}, sizeof(int), 2};
	ArrayUtil util2 = { (int[]){3, 2}, sizeof(int), 2};
	assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_are_same () {
	ArrayUtil util1 = { (float[]){1.1, 2.2}, sizeof(float), 2};
	ArrayUtil util2 = { (float[]){1.1, 2.2}, sizeof(float), 2};
	assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_are_not_same () {
	ArrayUtil util1 = { (float[]){1.2, 2.2}, sizeof(float), 2};
	ArrayUtil util2 = { (float[]){1.1, 2.2}, sizeof(float), 2};
	assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_for_char_should_return_1_when_two_array_util_elements_are_same () {
	ArrayUtil util1 = { (char[]){'a', 'b'}, sizeof(char), 2};
	ArrayUtil util2 = { (char[]){'a', 'b'}, sizeof(char), 2};
	assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_for_char_should_return_0_when_two_array_util_elements_are_not_same () {
	ArrayUtil util1 = { (char[]){'a', 'b'}, sizeof(char), 2};
	ArrayUtil util2 = { (char[]){'c', 'b'}, sizeof(char), 2};
	assertEqual(areEqual(util1, util2), 0);
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
	int sizeofFloat;
	float element, *a;
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

void test_dispose_should_free_the_memory_of_util_array () {
	ArrayUtil array;
	int *a;
	array = create(sizeof(int), 2);
	a = ((int*)(array.base));

	a[0] = 1;
	a[1] = 2;

	dispose(array); 
	/*	Think for some test
		When we do free, the memory doesn't get free instantly 
		So, that could be accessable after doing free also*/
}

int isEven(void *hint, void *element) {
	int* _hint = (int*)hint;
	int* _element = (int*)element; 
	return ((*_element) % (*_hint)) == 0;
}

void test_findFirst_should_return_4_as_a_even_value () {
	ArrayUtil array;
	int hint;
	MatchFunc* match;
	int element, *a;

	array = create(sizeof(int), 3);

	a = (int*)(array.base);

	a[0] = 1;
	a[1] = 4;
	a[2] = 6;

	match= &isEven;
	hint = 2;
	element = (int*)findFirst(array, match, ((void*)hint));
	assertEqual(element, 4);
}

void test_findFirst_should_return_NULL_as_a_even_value () {
	ArrayUtil array;
	int hint;
	MatchFunc* match;
	int element, *a;

	array = create(sizeof(int), 3);

	a = (int*)(array.base);

	a[0] = 1;
	a[1] = 7;
	a[2] = 45;

	match= &isEven;
	hint = 2;
	element = (int*)findFirst(array, match, ((void*)hint));
	assertEqual(element, 0);
}

// Need to write for other data types rather than int

// void test_findLast_should_return_4_as_a_even_value () {
// 	ArrayUtil array;
// 	int hint;
// 	MatchFunc* match;
// 	int element, *a;

// 	array = create(sizeof(int), 3);

// 	a = (int*)(array.base);

// 	a[0] = 1;
// 	a[1] = 6;
// 	a[2] = 4;

// 	match= &isEven;
// 	hint = 2;
// 	element = (int*)findLast(array, match, ((void*)hint));
// 	assertEqual(element, 4);
// }
