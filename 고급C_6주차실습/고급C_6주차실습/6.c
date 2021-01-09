#pragma warning (disable: 4996) //완료
#include <stdio.h>

void rev(double m[][2]); 

int main(void)
{
	double matrix[2][2];
	int i, j = 0;

	/* 2x2 행렬을 입력받음 */
	printf("2x2 행렬 입력\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%lf", &matrix[i][j]);
		}
	}

	rev(matrix); //rev함수 호출

	return 0;
}

void rev(double m[][2]) //2차원 배열을 매개변수로 받음
{
	//ad-bc 계산
	double ad_bc = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);

	//ad-bc=0일 경우 
	if (ad_bc == 0)
		printf("역행렬이 존재하지 않습니다.\n");

	//역행렬 출력
	else
	{
		printf("역행렬\n");
		printf("%6.2lf", m[1][1] / ad_bc);
		printf("%6.2lf\n", -(m[0][1] / ad_bc));
		printf("%6.2lf", -(m[1][0] / ad_bc));
		printf("%6.2lf\n", m[0][0] / ad_bc);
	}

}