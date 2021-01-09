#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[1024]; //������ �Է¹��� ���ڿ�
	char op = NULL; //�����ڸ� ������ ����
	int idx;        //�������� ��ġ�� ������ ����
	int length;

	printf("�Է�: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';     //fgets�� �޾ƿ��� ���๮�� ����
	length = strlen(str);

	/* �Է� ���� ���ڿ��� Ž���ϸ� �����ڸ� ã�� �� ��ġ�� �����Ѵ�. */
	for (int i = 0; i < length; i++)
	{
		if (str[i] < '0' || str[i] >'9')
		{
			if (op != NULL)
			{
				puts("�߸��� �������Դϴ�.");
				return -1;
			}
			op = str[i];
			str[i] = NULL;
			idx = i;
		}
	}

	/* switch���� �̿��� �� �����ڸ� �Է¹޾��� ����� ����� ����Ѵ�. */
	switch (op)
	{
	case '\0': // �����ڰ� ���� �� 
		puts("�����ڰ� �����ϴ�.");
		return -1;

	case '+':  // �����ڰ� +�� ��
		printf("���: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) + atoi(str + idx + 1));
		break;

	case '-':  // �����ڰ� -�� ��
		printf("���: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) - atoi(str + idx + 1));
		break;

	case '*':  // �����ڰ� *�� ��
		printf("���: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) * atoi(str + idx + 1));
		break;

	case '/':  // �����ڰ� /�� ��
		printf("���: %s %c %s = %d\n", str, op, (str + idx + 1), atoi(str) / atoi(str + idx + 1));
		break; 

	default:   // �̿��� �����ڸ� �Է¹޾��� ��
		printf("�߸��� �������Դϴ�.\n");
		return -1;
	}

	return 0;
}