#pragma warning (disable:4996)
#include <stdio.h>

int main(void)
{
	int num = 0;
	int count = 0;
	int* ptr = NULL;
	int i = 0;

	while (1)
	{
		printf("���� ������ �Է��ϼ���(����: -1): ");
		scanf("%d", &num);

		if (num == -1)
			break;

		//realloc�� ����Ͽ� �޸� �Ҵ�
		ptr = (int*)realloc(ptr, sizeof(int)*(count+1)); 
		ptr[count] = num; 
		count++;
	}

	/* ������� ��� */
	for (i = 0; i < count; i++)
		printf("ptr[%d]: %d\n", i, ptr[i]);

	free(ptr);

	return 0;
}