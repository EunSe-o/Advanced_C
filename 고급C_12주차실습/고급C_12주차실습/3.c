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
		printf("�Է�(����: -1): ");
		scanf("%d", &num);

		if (num == -1)
			break;

		pHead = make_Node(num, pHead);
	}
	print_linkedlist(pHead);

	if (pHead == NULL) //-1�� �Է� �޾� �Ҵ�� �޸� ������ ���� ��
		return 0;

	free_linkedlist(pHead);

	return 0;
}

Node* make_Node(int num, Node* pNode)
{
	Node* pNew = NULL; 
	pNew = (Node*)malloc(sizeof(Node)); //�޸� �Ҵ�
	
	pNew->num = num;     //pNew.num�� �Է¹��� num�� ����
	pNew->pNext = pNode; //pNew�� pNext�� pHead�� ����Ű�� ��
	pNode = pNew;        //pHead�� pNew�� ������ pHead�� ����Ű�� ��带 �ٲ�
}

void print_linkedlist(Node* pNode)
{
	while (1)
	{
		if (pNode == NULL) //-1�� �Է� �޾��� ��
			break;

		printf("%d->", pNode->num);

		if (pNode->pNext == NULL)
			break;

		pNode = pNode->pNext; //���� ��带 ����Ŵ
	}
	printf("NULL\n");
}

void free_linkedlist(Node* pNode)
{
	Node* pTemp = NULL;

	while (pNode->pNext)
	{
		pTemp = pNode;  //pNode�� pTemp�� ����
		pNode = pNode->pNext; //pNode�� ���� ��带 ����Ű�� ��.
		free(pTemp);
	}
}