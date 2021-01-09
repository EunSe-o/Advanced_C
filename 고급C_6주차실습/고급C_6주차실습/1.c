#include <stdio.h>

int main(void)
{
	int num = 314;
	int* ptr = &num;
	int** dptr = &ptr;

	/* num의 주소 = ptr이 가리키는 주소 */
	printf("num의 주소: %p\n", &num);
	printf("ptr이 가리키는 주소: %p\n", ptr);

	/* ptr의 주소 = dptr이 가리키는 주소 */
	printf("ptr의 주소: %p\n", &ptr);
	printf("dptr이 가리키는 주소: %p\n", dptr);

	printf("dptr의 주소: %p\n", &dptr);

	printf("num의 값: %d\n", num); //num 사용
	printf("num의 값: %d\n", *ptr); //ptr 사용
	printf("num의 값: %d\n", **dptr); //dptr 사용

	return 0;
}