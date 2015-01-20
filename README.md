# ArrayUtil
It is a ArrayUtil written in C

*************************** Modules *****************************
							v1.0

The ArrayUtil contains

    base
    	-which is a pointer to the array

    typeSize
    	-which is size of one array element

    length
    	-which is how many elements are there.


	NB: To use the array you just have to cast the base to the 
		pointer of the respective type: like int* a, float* a ,etc and 
		then a[5] will give you the fifth int or float

int areEqual(ArrayUtil a, ArrayUtil b)

    will compare a with b and return 1 if both are equal, if not it returns 0 


ArrayUtil create(int typeSize, int length)

    will create an array and wrap it with the ArrayUtil and return it.

    the array contents will all be set to zero or its equivalent value.


ArrayUtil resize(ArrayUtil util, int length)

    will resize the array and return the modified ArrayUtil.

    the array contents should be trimmed 
    	if new size is less and copied over 
    	if the new size is more.

									v1.1

int findIndex(ArrayUtil util, void* element)

	will return -1 if not found and the array index of the element if found

	for example to search 5 in [4,2,1,5,6,0]

		int x = 5;

		findIndex(util, &x) will return 3

									v1.2

void dispose(ArrayUtil util)
	-a method dispose to free the memory allocated for the Array inside array util