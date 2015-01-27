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

                                    v1.3

Implement a findFirst method to find the first element matching the criteria.

    void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);

        - which returns the first element which matches the criteria or null if there is no match.

        - where the signature of the MatchFunc is:

    int MatchFunc(void* hint, void* item);

        - which will return 0 in case of no match and 1 in case of match.

As C language does not have closure, we have some hint that can be passed, which will help in customizing the match.

for example:

    int isEven(void* hint, void* item)

        - can be used to find if a given number is even. Here the hint is not needed.

    int isDivisible(void* hint, void* item)

        - can be used to find if a given number is divisible by the number mentioned in the hint.

                                    v1.4

Implement a findLast method similar to findFirst

                                    v1.5

Implement a count method to count the number of elements matching the criteria.

    int count(ArrayUtil util, MatchFunc* match, void* hint);

                                    v1.6

Implement a filter method to find the first n elements matching the criteria.

    int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );

        - where destination is an array of pointers into which the address of the matching elements are copied onto. maxitems is the capacity of destination.

        - The method returns the number of elements which matches the criteria that have been copied onto the destination.

                                    v1.7

Implement a map method.

    void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);

        - maps source to destination using the provided convert function.
        where the signature of the ConvertFunc is:

    void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

                                    v1.8

Implement forEach method

    void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
        - performs operation on all items in the array.

        where the signature of the OperationFunc is:
            void OperationFunc(void* hint, void* item);

                                    v1.9

Implement reduce method

    void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);
        - returns the reduced answer.

    where the signature of ReducerFunc is:
        void* ReducerFunc(void* hint, void* previousItem, void* item);