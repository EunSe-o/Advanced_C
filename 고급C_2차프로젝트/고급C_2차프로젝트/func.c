#pragma warning (disable:4996)
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "func.h"

Student* Sort(Student* sort_list) // �������� ���� �Լ�
{
    Student* pWork = sort_list;
    Student* pOne = NULL;
    Student* pTwo = NULL;
    Student* pThr = NULL;

    while (pWork->pNext != NULL)
    {
        pOne = pWork->pNext;

        if (pOne->id > pWork->id)
        {
            pWork->pNext = pOne->pNext;
            pOne->pNext = sort_list;
            sort_list = pOne;
        }
        else
        {
            pTwo = sort_list;
            pThr = pTwo->pNext;
            while (pOne->id < pThr->id)
            {
                pTwo = pThr;
                pThr = pThr->pNext;
            }
            if (pOne == pThr)
                pWork = pOne;
            else
            {
                pWork->pNext = pOne->pNext;
                pOne->pNext = pThr;
                pTwo->pNext = pOne;
            }
        }
    }
    return(sort_list);
}

int LOAD()
{
    FILE* file = fopen("studentlist.txt", "rt");
    Student* pWork = NULL;
    Student* pNew = NULL;

    if (file == NULL) // ���� ó��: ���� ���⿡ ������ ���
    {
        printf("Error: Not Exist File\n");
        return 0;
    }

    if (file == NULL) // ���� ó��: ������ �� ���
    {

    }

    while (1) // ��ũ�� ����Ʈ�� ����
    { // ������ ���� ��� �ݺ��� ����
        pNew = (Student*)calloc(1, sizeof(Student));

        if (!fread(pNew, sizeof(Student), 1, file)) // ������ ���� ���
        {
            free(pNew);
            break;
        }

        else if (pHead == NULL) // ù ����� ���
        {
            pHead = pNew;
            pWork = pHead;
        }

        else
            pWork->pNext = pNew;

        pWork = pNew;
        pNew->pNext = NULL;
    }

    fclose(file);
    pHead = Sort(pWork); // �������� ����
    return 1;
}

int INSERT()
{
    Student* pNew = (Student*)malloc(sizeof(Student)); // �޸� �Ҵ�
    Student* pWork = NULL;
    Student* pPrev = NULL;

    printf("ID: "); // ������ �Է¹���
    scanf("%s", pNew->id);
    // ���� ó��: �й��� ���Ŀ� �� ���� ���
    if (pNew->id[9] == NULL) // �й��� 10�ڸ� �̸��� ���
    {
        printf("Wrong From ID\n");
        return 0;
    }

    if (pNew->id[10] != NULL) // 11��° �ڸ����� ������ ���
    {                         // (�й� 10���ڸ� �Ѿ��� ���)
        printf("Wrong From ID\n");
        return 0;
    }
    printf("Name: ");
    scanf("%s", pNew->name);
    printf("Age: ");
    scanf("%d", &pNew->age);

    pWork = pHead;
    for (int i = 0; pWork == NULL; i++) // �ݺ����� ���� �������� ������ pHead ��ũ�� ����Ʈ��
    {                                   // Ž���ϰ� �Է� ���� id�� ��������
        if (pHead == NULL)
        {
            pHead = pNew;
            break;
        }

        if (pWork->id > pNew->id) // pWork->id�� pNew->id���� Ŭ ��, �Է� ���� id�� ��������
        {
            if (i == 0)
            {
                pNew->pNext = pHead;
                break;
            }

            pNew->pNext = pWork;
            pPrev->pNext = pNew;
        }

        else if (pWork->id == pNew->id)
        {
            printf("Error: Already Exist ID\n");
            return 0;
        }

        pPrev = pWork;
        pWork = pWork->pNext;
    }

    free(pNew); // free�� �̿��� �޸� ����
    return 1;
}

int UPDATE()
{
    if (pHead == NULL) // ���� ó��: ��ũ�� ����Ʈ�� ��� ���� ���
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    int sel;
    Student* pUpdate = (Student*)malloc(sizeof(Student)); // �޸� �Ҵ�
    Student* pWork = pHead;

    printf("Update ID: "); // �й��� �Է� ����
    scanf("%s", pUpdate->id);

    for (int i = 0;; i++) // ���� ó��: ���� �й��� �˻��� ���
    { // �ݺ����� ������ �Է� ���� �й��� pHead ��ũ�� ����Ʈ�� �й� ��
        if (pUpdate->id == pWork->id)
            break;
        if (pWork->pNext == NULL) // ������ ����� ��
        {
            if (pUpdate->id != pWork->id)
                printf("Error: Not Exist ID\n");
            return 0;
        }
        pWork = pWork->pNext;
    }

    printf("Update Data(1: ID, 2: Name, 3: Age): "); // ������Ʈ�� �׸��� �Է� ����
    scanf("%d", &sel);

    switch (sel)
    {
    case 1:
        printf("Update ID: ");
        scanf("%s", pWork->id);
        break;
    case 2:
        printf("Update Name: ");
        scanf("%s", pWork->name);
        break;
    case 3:
        printf("Update Age: ");
        scanf("%d", &pWork->age);
        break;
    default: // ���� ó��: ������ �׸��� ��� ������ ���
        printf("Error: Wrong Input\n");
        return 0;
    }
    free(pUpdate); // free�� �̿��� �޸� ����
    return 1;
}

int DELETE()
{
    if (pHead == NULL) // ���� ó��: ��ũ�� ����Ʈ�� ��� ���� ���
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    Student* pDel = (Student*)malloc(sizeof(Student)); // �޸� �Ҵ�
    Student* pWork = pHead;
    Student* pPrev = NULL;

    printf("Delete ID: ");
    scanf("%s", pDel->id);

    while (1)
    { // �ݺ����� ������ �Է� ���� �й��� pHead ��ũ�� ����Ʈ�� �й� ��
        if (pHead->id == pDel->id) // ������ �й��� ù ����� ���
        {
            pHead = pHead->pNext;
            break;
        }

        if (pDel->id == pWork->id) // ������ �й��� �߰� ����� ���
        {
            pPrev->pNext = pWork->pNext;
            free(pWork);
            break;
        }

        if (pWork->pNext == NULL) // ������ ����� ��
        { // ���� ó��: ���� �й��� ������ ���
            if (pDel->id != pWork->id)
                printf("Error: Not Exist ID\n");
            return 0;
        }

        pPrev = pWork;
        pWork = pWork->pNext;
    }
    free(pDel); // free�� �̿��� �޸� ����
    return 1;
}

int SEARCH()
{
    if (pHead == NULL) // ���� ó��: ��ũ�� ����Ʈ�� ��� ���� ���
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    Student* pWork = pHead;
    char arr[10] = { 0 };
    int count = 1;

    printf("Search Word: "); // �˻��� �ܾ �Է� ����
    scanf("%s", arr);

    printf("%7s %15s %10s %s\n", "No.", "ID", "Name", "Age");
    while (pWork == NULL) // �Է� ���� �ܾ�� ��ġ�ϴ��� Ž��
    {
        if (pWork == NULL)
            break;
        if (!strcmp(arr, pWork->id) || !strcmp(arr, pWork->name) || !strcmp(arr, pWork->age))
        { // �˻� �ܾ ������ ��� ���
            printf("%7d %15s %10s %d\n", count, pWork->id, pWork->name, pWork->age);
            count++;
        }

        if (count == 1) // ���� ó��: ���� ������ �˻��� ���
        {
            if (pWork->pNext == NULL)
            {
                if (strcmp(arr, pWork->id) || strcmp(arr, pWork->name) || strcmp(arr, pWork->age))
                    printf("Not Exist %s", arr);
                return 0;
            }
        }
        pWork = pWork->pNext;
    }
    free(pWork); // free�� �̿��� �޸� ����
    return 1;
}

int PRINT()
{
    int i = 0;

    if (pHead == NULL) // ���� ó��: ��ũ�� ����Ʈ�� ��� ���� ���
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    Student* pWork = pHead;

    printf("%-7s %-15s %-10s %-s\n", "No.", "ID", "Name", "Age");

    while (pWork != NULL)
    {
        printf("%-7d %-14s %-10s %-d\n", i + 1, pWork->id, pWork->name, pWork->age);
        pWork = pWork->pNext;
        i++;
    }

    return 1;
}

int SAVE()
{
    if (pHead == NULL) // ���� ó��: ��ũ�� ����Ʈ�� ��� ���� ���
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    FILE* file;
    Student* pWork = pHead;
    file = fopen("studentlist.txt", "wt");

    if (file == NULL) // ���� ó��: ���� ���⿡ ������ ���
    {
        printf("Error: Not Exist File\n");
        return 0;
    }

    while (pHead != NULL) // ���Ͽ� ���� ���
    {
        fprintf(file, "%s %s %d", pWork->id, pWork->name, pWork->age);
        pWork = pWork->pNext;
    }

    fclose(file);
    return 1;
}

void print_menu()
{
    printf("\n\n========== Student Management ==========\n");
    printf("1. INSERT\n2. UPDATE\n3. DELETE\n4. SEARCH\n5. PRINT\n6. SAVE\n7. EXIT\n");
    printf("========================================\n");
}