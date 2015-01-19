#include "arrayUtil.h"
#include <stdio.h>

int areEqual (ArrayUtil array1, ArrayUtil array2) {
	int count;
	char *a1 = ((char*)(array1.base));
	char *a2 = ((char*)(array2.base));
	if(array1.length != array2.length)
		return 0;

	for (count = 0; count < (array1.length * array1.typeSize); ++count) {
		if(a1[count] != a2[count])
			return 0;	
	}

	return 1;
}
