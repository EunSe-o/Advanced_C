#include <stdio.h>

int main(void)
{
	int num = 314;
	int* ptr = &num;
	int** dptr = &ptr;

	/* num�� �ּ� = ptr�� ����Ű�� �ּ� */
	printf("num�� �ּ�: %p\n", &num);
	printf("ptr�� ����Ű�� �ּ�: %p\n", ptr);

	/* ptr�� �ּ� = dptr�� ����Ű�� �ּ� */
	printf("ptr�� �ּ�: %p\n", &ptr);
	printf("dptr�� ����Ű�� �ּ�: %p\n", dptr);

	printf("dptr�� �ּ�: %p\n", &dptr);

	printf("num�� ��: %d\n", num); //num ���
	printf("num�� ��: %d\n", *ptr); //ptr ���
	printf("num�� ��: %d\n", **dptr); //dptr ���

	return 0;
}