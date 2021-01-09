#include <stdio.h>

void swap(int*** ptr1, int*** ptr2)
{
	// *ptr1이 이중포인터이므로 **temp로 선언해준다.
	int** temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main(void)
{
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1, * ptr2 = &num2;
	int** dptr1 = &ptr1, ** dptr2 = &ptr2;

	printf("**dptr1 = %d\t**dptr2 = %d\n\n", **dptr1, **dptr2);

	swap(&dptr1, &dptr2);

	printf("**dptr1 = %d\t**dptr2 = %d\n\n", **dptr1, **dptr2);

	return 0;
}