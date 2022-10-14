#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	/// setvbuf(stdout, NULL, _IONBF, 0); if you want to debug in many code using printf to stdout, disable buffer.
	/// Here "*resultIndex1" is the pointer that point to 1 dimension array (many int).
	/// Here "**resultIndex" is the pointer that point to "*resultIndex1" ("*resultIndex1" memory address.)
	int *resultIndex1;
 	int **resultIndex = &resultIndex1;
	/// "*resultIndex" is "resultIndex1", they have same memory address and contents.
	*resultIndex = (int*)malloc(sizeof(int)*10);
	/// Here suggest not using *resultIndex[0] = 5;
	(*resultIndex)[0] = 5;
	
	printf("resultIndex1     %p, resultIndex     %p, *resultIndex       %p\n", resultIndex1    , resultIndex    , *resultIndex      );
	printf("&resultIndex1    %p, &resultIndex    %p, &*resultIndex      %p\n", &resultIndex1   , &resultIndex   , &*resultIndex     );
	printf("resultIndex1[0]  %p, resultIndex[0]  %p, *resultIndex[0]    %p\n", resultIndex1[0] , resultIndex[0] , *resultIndex[0]   );
	printf("&resultIndex1[0] %p, &resultIndex[0] %p, &*resultIndex[0]   %p\n", &resultIndex1[0], &resultIndex[0], &*resultIndex[0]  );
    printf("resultIndex1[1]  %p, resultIndex[1]  %p, *resultIndex[1]    %p\n", resultIndex1[1] , resultIndex[1] , *resultIndex[1]   );
	printf("&resultIndex1[1] %p, &resultIndex[1] %p, &*resultIndex[1]   %p\n", &resultIndex1[1], &resultIndex[1], &*resultIndex[1]  );
	printf("                                     %s, *(resultIndex[1])  %p\n", "                              " , *(resultIndex[1]) );
	printf("                                     %s, &*(resultIndex[1]) %p\n", "                              " , &*(resultIndex[1]));
	printf("                                     %s, (*resultIndex)[0]  %p\n", "                              " , (*resultIndex)[0] );
	printf("                                     %s, &(*resultIndex)[0] %p\n", "                              " , &(*resultIndex)[0]);
    printf("                                     %s, (*resultIndex)[1]  %p\n", "                              " , (*resultIndex)[1] );
	printf("                                     %s, &(*resultIndex)[1] %p\n", "                              " , &(*resultIndex)[1]);
	printf("\n\n\n");
	printf("%d\n", (*resultIndex)[0]);
	
	*resultIndex = (int*)realloc(*resultIndex, sizeof(int)*2);
	
	/// Here can't use *resultIndex[1] = 8;
	/// "*resultIndex[1]" is not (*resultIndex)[1], "*resultIndex[1]" memory address is resultIndex[1] contents.
	/// "*resultIndex[1]" mean "*(resultIndex[1]), not "(*resultIndex)[1]"
	/// "&*resultIndex[1]" == "resultIndex[1]"
	(*resultIndex)[1] = 8;
	
	printf("%d\n", (*resultIndex)[1]);
	free(*resultIndex);
	
////////////////////////////////////////////////////////////////////
/* 	int *resultIndex = (int*)malloc(sizeof(int));
	resultIndex[0] = 5;
	printf("%d\n", resultIndex[0]);
	resultIndex = (int*)realloc(resultIndex, sizeof(int)*2);
	resultIndex[1] = 8;
	printf("%d\n", resultIndex[1]);
	free(resultIndex); */ 
///////////////////////////////////////////////////////////////////

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
    return 0;
} 
