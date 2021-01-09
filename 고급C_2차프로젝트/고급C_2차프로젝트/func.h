#define __FUNC_H__
#ifdef __FUNC_H__


typedef struct
{
    char id[32];
    char name[32];
    int age;
    struct student* pNext;

}Student;

extern Student* pHead;

int LOAD();
int INSERT();
int UPDATE();
int DELETE();
int SEARCH();
int PRINT();
int SAVE();

void print_menu();
#endif // !1


