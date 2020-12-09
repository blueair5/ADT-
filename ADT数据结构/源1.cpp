//顺序表的增删查找
#include <stdio.h>
#include <malloc.h>
#define Max 100
typedef struct LNode* List;
struct LNode {
	int data[Max];
	int Last;           //线性表的长度，Last+1就可以了
};
struct LNode L;
List Ptrl;

//初始化，建立一个空表
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List)malloc(sizeof(struct LNode));
	Ptrl -> Last = -1;
	return  Ptrl;

}

//查找
int Find(int number, List Ptrl)
{
	int i = 0;
	while (i <= Ptrl->Last && Ptrl->data[i] != number) {
		i++;
	}
	if (i > Ptrl->Last) return -1;
	else  return i;

}

//插入,先移动，再插入
void insert(int number, int i, List Ptrl)
{
	int j;
	if (Ptrl->Last == Max - 1) {
		printf("表满");
		return;
	}
	if (i<1 || i>Ptrl -> Last + 2) {
		printf("位置不合法");
		return;
	}
	for (j = Ptrl->Last; j >= i - 1; j--) {
		Ptrl->data[j + 1] = Ptrl->data[j];
	}
	Ptrl->data[i - 1] = number;
	Ptrl->Last++;
}

//删除
void Delete(int i, List Ptrl)
{
	int j;
	if (i < 1 || Ptrl->Last + 1) {
		printf("不存在第%d个元素", i);
		return;
	}
	for (j = i; j <= Ptrl -> Last; j++) {
		Ptrl->data[j - 1] = Ptrl->data[j];
	}
	Ptrl->Last--;
	return;
}

