#pragma warning (disable: 4996) //�Ϸ�
#include <stdio.h>

void rev(double m[][2]); 

int main(void)
{
	double matrix[2][2];
	int i, j = 0;

	/* 2x2 ����� �Է¹��� */
	printf("2x2 ��� �Է�\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%lf", &matrix[i][j]);
		}
	}

	rev(matrix); //rev�Լ� ȣ��

	return 0;
}

void rev(double m[][2]) //2���� �迭�� �Ű������� ����
{
	//ad-bc ���
	double ad_bc = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);

	//ad-bc=0�� ��� 
	if (ad_bc == 0)
		printf("������� �������� �ʽ��ϴ�.\n");

	//����� ���
	else
	{
		printf("�����\n");
		printf("%6.2lf", m[1][1] / ad_bc);
		printf("%6.2lf\n", -(m[0][1] / ad_bc));
		printf("%6.2lf", -(m[1][0] / ad_bc));
		printf("%6.2lf\n", m[0][0] / ad_bc);
	}

}