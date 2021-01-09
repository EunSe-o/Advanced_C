#include <stdio.h> //헤더파일 선언

void swap_call_by_value(n1, n2); //함수 선언
void swap_call_by_refer(int* n3, int* n4);

int main(void)
{
	int num1 = 41, num2 = 59;
	int num3 = 76, num4 = 24;

	swap_call_by_value(num1, num2);
	swap_call_by_refer(&num3, &num4); //주소값을 받음

	printf("num1 = %d, num2 = %d\n", num1, num2);
	printf("num3 = %d, num4 = %d\n", num3, num4);

	return 0;
}

void swap_call_by_value(n1, n2)
{
	int temp = 0;

	temp = n1;
	n1 = n2; //전달받은 인자값으로 계산
	n2 = temp;
}

void swap_call_by_refer(int* n3, int* n4)
{
	int temp = 0;

	temp = *n3;
	*n3 = *n4; //전달받은 인자의 주소값을 이용해 계산
	*n4 = temp;
}