#pragma warning (disable:4996)
#include <stdio.h>

typedef struct node
{
	int num;
	struct node* pNext;
}Node;

Node* make_Node(int num, Node* pNode);
void print_linkedlist(Node* pNode);
void free_linkedlist(Node* pNode);

int main(void)
{
	Node* pHead = NULL;
	int num = 0;

	while (1)
	{
		printf("입력(종료: -1): ");
		scanf("%d", &num);

		if (num == -1)
			break;

		pHead = make_Node(num, pHead);
	}
	print_linkedlist(pHead);

	if (pHead == NULL) //-1을 입력 받아 할당된 메모리 공간이 없을 때
		return 0;

	free_linkedlist(pHead);

	return 0;
}

Node* make_Node(int num, Node* pNode)
{
	Node* pNew = NULL; 
	pNew = (Node*)malloc(sizeof(Node)); //메모리 할당
	
	pNew->num = num;     //pNew.num에 입력받은 num을 저장
	pNew->pNext = pNode; //pNew의 pNext가 pHead를 가리키게 함
	pNode = pNew;        //pHead에 pNew를 대입해 pHead가 가리키는 노드를 바꿈
}

void print_linkedlist(Node* pNode)
{
	while (1)
	{
		if (pNode == NULL) //-1을 입력 받았을 때
			break;

		printf("%d->", pNode->num);

		if (pNode->pNext == NULL)
			break;

		pNode = pNode->pNext; //다음 노드를 가리킴
	}
	printf("NULL\n");
}

void free_linkedlist(Node* pNode)
{
	Node* pTemp = NULL;

	while (pNode->pNext)
	{
		pTemp = pNode;  //pNode를 pTemp에 저장
		pNode = pNode->pNext; //pNode가 다음 노드를 가리키게 함.
		free(pTemp);
	}
}