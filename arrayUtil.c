#include "arrayUtil.h"
#include <stdio.h>
#include <stdlib.h>

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
	int newTypeSize;
	ArrayUtil util = create(array.typeSize, length);
	newTypeSize = length >= array.length ? array.length * array.typeSize : length * array.typeSize;

	memcpy(util.base, array.base, newTypeSize);

	return util;
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

void *findFirst(ArrayUtil util, MatchFunc *match, void *hint) {
	int count;
	void* element = malloc(util.typeSize);
	char* base = (char*) util.base;
	
	for (count = 0; count < util.length; count++){
		element = &(base[count * util.typeSize]);
		if(match(hint, element)){
			return element;
		}
	}
	
	return NULL;
}

void *findLast (ArrayUtil array, MatchFunc *match, void *hint) {
	int count;
	void *element = malloc(array.typeSize);
	int *convArray = array.base;

	for(count = array.length - 1; count > 0; count--){
		memcpy(element, &(convArray[(count)]), array.typeSize);
		if(match(hint, element)){
			free(element);
			return convArray[(count)];
		}
	}

	free(element);	
	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint) {
	int count, total = 0;
	char *convArray = util.base;

	void *element = malloc(util.typeSize);

	for(count = 0; count < util.length; count++){
		memcpy(element,&(convArray[(count * util.typeSize)]),util.typeSize);
		if(match(hint, element))
			total++;
	}

	free(element);
	return total;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int count;
	int total = 0;
	char** _destination;
	char* base = (char*) util.base;
	void * element ;
	*destination = calloc(util.typeSize, util.length);
	_destination = (char**) destination;

	for (count = 0; count < util.length;count++){
		element = &(base[(count * util.typeSize)]);
		
		if(match(hint,element)){
			memcpy(&((*_destination)[total * util.typeSize]), element, util.typeSize);
			total++;
		}

		if(total == maxItems){
			return total;
		}
	}

	return total;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint) {
	int count;
	char* _source = (char*)source.base;
	char* _destination = (char*)source.base;

	for(count = 0; count < (source.length * source.typeSize); count++)
		convert(hint, &(_source[(count * source.typeSize)]), &(_destination[(count * destination.typeSize)]));
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint) {
	int count;
	char* _util = (char*)util.base;

	for(count = 0; count < (util.length * util.typeSize); count++)
		operation(hint, &(_util[(count * util.typeSize)]));	
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue) {
	int count;
	char* base = (char*)util.base;
	void* previous = intialValue ;
	
	for (count = 0; count < util.length; count++){
		previous = reducer(hint, previous, &(base[(count * util.typeSize)]));
	}
	
	return previous;
}