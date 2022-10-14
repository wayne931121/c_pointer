# c_pointer
Explore C Pointer

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	/// Here "*resultIndex1" is the pointer that point to 1 dimension array (many int).
	/// Here "**resultIndex" is the pointer that point to "*resultIndex1" ("*resultIndex1" memory address.)
	int *resultIndex1;
 	int **resultIndex = &resultIndex1;
	/// "*resultIndex" is "resultIndex1", they have same memory address and contents.
	*resultIndex = (int*)malloc(sizeof(int)*10);
	/// Here suggest not using *resultIndex[0] = 5;
	(*resultIndex)[0] = 5;
	*resultIndex = (int*)realloc(*resultIndex, sizeof(int)*2);
	
	/// Here can't use *resultIndex[1] = 8;
	/// "*resultIndex[1]" is not (*resultIndex)[1], "*resultIndex[1]" memory address is resultIndex[1] contents.
	/// "*resultIndex[1]" mean "*(resultIndex[1]), not "(*resultIndex)[1]"
	/// "&*resultIndex[1]" == "resultIndex[1]"
	(*resultIndex)[1] = 8;
	
	printf("%d\n", (*resultIndex)[1]);
	free(*resultIndex);
    return 0;
} 
```


```
/////////////////////////////////////////////////////OUTPUT//////////////////////////////////////////////////
/*
$ ./a
resultIndex1     0000020710151400, resultIndex     00000036a13ffde8, *resultIndex       0000020710151400
&resultIndex1    00000036a13ffde8, &resultIndex    00000036a13ffde0, &*resultIndex      00000036a13ffde8
resultIndex1[0]  0000000000000005, resultIndex[0]  0000020710151400, *resultIndex[0]    0000000000000005
&resultIndex1[0] 0000020710151400, &resultIndex[0] 00000036a13ffde8, &*resultIndex[0]   0000020710151400
resultIndex1[1]  0000000000000207, resultIndex[1]  00000207101513b0, *resultIndex[1]    0000000010151361
&resultIndex1[1] 0000020710151404, &resultIndex[1] 00000036a13ffdf0, &*resultIndex[1]   00000207101513b0
                                                                   , *(resultIndex[1])  0000000010151361
                                                                   , &*(resultIndex[1]) 00000207101513b0
                                                                   , (*resultIndex)[0]  0000000000000005
                                                                   , &(*resultIndex)[0] 0000020710151400
                                                                   , (*resultIndex)[1]  0000000000000207
                                                                   , &(*resultIndex)[1] 0000020710151404
5
8
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
```
