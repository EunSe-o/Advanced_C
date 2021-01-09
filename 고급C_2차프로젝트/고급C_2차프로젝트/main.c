#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

Student* pHead = NULL;

int main()
{
	Student* pTemp = NULL;
	int sel = 0;
	LOAD();

	while (1)
	{
		print_menu();
		printf("SELECT: ");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
			if (INSERT())
				printf("\nINSERT Success\n");
			break;
		case 2:
			if (UPDATE())
				printf("\nUPDATE Success\n");
			break;
		case 3:
			if (DELETE())
				printf("\nDELETE Success\n");
			break;
		case 4:
			if (SEARCH())
				printf("\nSEARCH Success\n");
			break;
		case 5:
			PRINT();
			break;
		case 6:
			if (SAVE())
				printf("\nSAVE Success\n");
			break;
		case 7:
			printf("\nEXIT\n");
			for (int i = 0; pHead == NULL; i++)
			{
				pTemp = pHead;
				pHead = pHead->pNext;
				free(pTemp);
			}
			return 0;
		default: // 예외 처리: 1~7 이외의 번호를 선택한 경우
			printf("\nError: Wrong Input\n");
			break;
		}
	}

	return 0;
}
