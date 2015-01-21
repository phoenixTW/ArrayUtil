#include "arrayUtil.h"
#include <stdio.h>
// #include <stdli.h>

int areEqual (ArrayUtil array1, ArrayUtil array2) {
	int count;
	char *a1 = ((char*)(array1.base));
	char *a2 = ((char*)(array2.base));
	if(array1.length != array2.length || array1.typeSize != array2.typeSize)
		return 0;

	for (count = 0; count < (array1.length * array1.typeSize); ++count) {
		if(a1[count] != a2[count])
			return 0;	
	}

	return 1;
}

ArrayUtil create(int typeSize, int length) {
	ArrayUtil array;
	int *newArray;
	newArray = calloc(typeSize, length);
	array.length = length;
	array.typeSize = typeSize;
	array.base = newArray;

	return array;
}

ArrayUtil resize(ArrayUtil array, int length) {
	ArrayUtil newUtil;
	int newSize = array.typeSize * length;
	newUtil.length = newSize;
	newUtil.base = realloc(array.base, newSize);
	return newUtil;
}

int findIndex(ArrayUtil array, void *element) {
	int count, size = sizeof(element);

	for(count = 0; count < (array.length * array.typeSize); count++) {
		if(sizeof(int) == size){
			if(((int*)array.base)[count] == *((int*)element))
				return count;			
		}

		if(sizeof(float) == size){
			if(((float*)array.base)[count] == *((float*)element))
				return count;			
		}
	}

	for(count = 0; count < (array.length * array.typeSize); count++) {
		if(((char*)array.base)[count] == *((char*)element))
			return count;			
	}

	return -1;
}

void dispose (ArrayUtil array) {
	free(array.base);
	array.base = NULL;
}

void *findFirst(ArrayUtil array, MatchFunc *match, void *hint) {
	int count;
	int *convArray = array.base;

	for(count = 0; count < array.length; count++)
		if(match(&hint, ((void*)(&convArray[count]))))
			return convArray[count];
	return NULL;
}

void *findLast (ArrayUtil array, MatchFunc *match, void *hint) {
	int count;
	int *convArray = array.base;

	for(count = array.length - 1; count > 0; count--)
		if(match(&hint, ((void*)(&convArray[count]))))
			return convArray[count];
	return NULL;
}