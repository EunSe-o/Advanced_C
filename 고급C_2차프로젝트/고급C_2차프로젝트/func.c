#pragma warning (disable:4996)
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "func.h"

Student* Sort(Student* sort_list) // 오름차순 정렬 함수
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

    if (file == NULL) // 예외 처리: 파일 열기에 실패한 경우
    {
        printf("Error: Not Exist File\n");
        return 0;
    }

    if (file == NULL) // 예외 처리: 파일이 빈 경우
    {

    }

    while (1) // 링크드 리스트를 생성
    { // 파일의 끝일 경우 반복문 종료
        pNew = (Student*)calloc(1, sizeof(Student));

        if (!fread(pNew, sizeof(Student), 1, file)) // 파일의 끝인 경우
        {
            free(pNew);
            break;
        }

        else if (pHead == NULL) // 첫 노드인 경우
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
    pHead = Sort(pWork); // 오름차순 정렬
    return 1;
}

int INSERT()
{
    Student* pNew = (Student*)malloc(sizeof(Student)); // 메모리 할당
    Student* pWork = NULL;
    Student* pPrev = NULL;

    printf("ID: "); // 정보를 입력받음
    scanf("%s", pNew->id);
    // 예외 처리: 학번이 형식에 안 맞을 경우
    if (pNew->id[9] == NULL) // 학번이 10자리 미만일 경우
    {
        printf("Wrong From ID\n");
        return 0;
    }

    if (pNew->id[10] != NULL) // 11번째 자리수가 존재할 경우
    {                         // (학번 10글자를 넘었을 경우)
        printf("Wrong From ID\n");
        return 0;
    }
    printf("Name: ");
    scanf("%s", pNew->name);
    printf("Age: ");
    scanf("%d", &pNew->age);

    pWork = pHead;
    for (int i = 0; pWork == NULL; i++) // 반복문을 돌며 오름차순 정렬한 pHead 링크드 리스트를
    {                                   // 탐색하고 입력 받은 id를 끼워넣음
        if (pHead == NULL)
        {
            pHead = pNew;
            break;
        }

        if (pWork->id > pNew->id) // pWork->id가 pNew->id보다 클 시, 입력 받은 id를 끼워넣음
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

    free(pNew); // free를 이용해 메모리 삭제
    return 1;
}

int UPDATE()
{
    if (pHead == NULL) // 예외 처리: 링크드 리스트가 비어 있을 경우
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    int sel;
    Student* pUpdate = (Student*)malloc(sizeof(Student)); // 메모리 할당
    Student* pWork = pHead;

    printf("Update ID: "); // 학번을 입력 받음
    scanf("%s", pUpdate->id);

    for (int i = 0;; i++) // 예외 처리: 없는 학번을 검색한 경우
    { // 반복문을 돌리며 입력 받은 학번과 pHead 링크드 리스트의 학번 비교
        if (pUpdate->id == pWork->id)
            break;
        if (pWork->pNext == NULL) // 마지막 노드일 때
        {
            if (pUpdate->id != pWork->id)
                printf("Error: Not Exist ID\n");
            return 0;
        }
        pWork = pWork->pNext;
    }

    printf("Update Data(1: ID, 2: Name, 3: Age): "); // 업데이트할 항목을 입력 받음
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
    default: // 예외 처리: 수정할 항목을 벗어나 선택한 경우
        printf("Error: Wrong Input\n");
        return 0;
    }
    free(pUpdate); // free를 이용해 메모리 삭제
    return 1;
}

int DELETE()
{
    if (pHead == NULL) // 예외 처리: 링크드 리스트가 비어 있을 경우
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    Student* pDel = (Student*)malloc(sizeof(Student)); // 메모리 할당
    Student* pWork = pHead;
    Student* pPrev = NULL;

    printf("Delete ID: ");
    scanf("%s", pDel->id);

    while (1)
    { // 반복문을 돌리며 입력 받은 학번과 pHead 링크드 리스트의 학번 비교
        if (pHead->id == pDel->id) // 삭제할 학번이 첫 노드인 경우
        {
            pHead = pHead->pNext;
            break;
        }

        if (pDel->id == pWork->id) // 삭제할 학번이 중간 노드인 경우
        {
            pPrev->pNext = pWork->pNext;
            free(pWork);
            break;
        }

        if (pWork->pNext == NULL) // 마지막 노드일 때
        { // 예외 처리: 없는 학번을 삭제한 경우
            if (pDel->id != pWork->id)
                printf("Error: Not Exist ID\n");
            return 0;
        }

        pPrev = pWork;
        pWork = pWork->pNext;
    }
    free(pDel); // free를 이용해 메모리 삭제
    return 1;
}

int SEARCH()
{
    if (pHead == NULL) // 예외 처리: 링크드 리스트가 비어 있을 경우
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    Student* pWork = pHead;
    char arr[10] = { 0 };
    int count = 1;

    printf("Search Word: "); // 검색할 단어를 입력 받음
    scanf("%s", arr);

    printf("%7s %15s %10s %s\n", "No.", "ID", "Name", "Age");
    while (pWork == NULL) // 입력 받은 단어와 일치하는지 탐색
    {
        if (pWork == NULL)
            break;
        if (!strcmp(arr, pWork->id) || !strcmp(arr, pWork->name) || !strcmp(arr, pWork->age))
        { // 검색 단어가 존재할 경우 출력
            printf("%7d %15s %10s %d\n", count, pWork->id, pWork->name, pWork->age);
            count++;
        }

        if (count == 1) // 예외 처리: 없는 정보를 검색한 경우
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
    free(pWork); // free를 이용해 메모리 삭제
    return 1;
}

int PRINT()
{
    int i = 0;

    if (pHead == NULL) // 예외 처리: 링크드 리스트가 비어 있을 경우
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
    if (pHead == NULL) // 예외 처리: 링크드 리스트가 비어 있을 경우
    {
        printf("Error: Empty Student List\n");
        return 0;
    }

    FILE* file;
    Student* pWork = pHead;
    file = fopen("studentlist.txt", "wt");

    if (file == NULL) // 예외 처리: 파일 열기에 실패한 경우
    {
        printf("Error: Not Exist File\n");
        return 0;
    }

    while (pHead != NULL) // 파일에 내용 출력
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