//˳������ɾ����
#include <stdio.h>
#include <malloc.h>
#define Max 100
typedef struct LNode* List;
struct LNode {
	int data[Max];
	int Last;           //���Ա�ĳ��ȣ�Last+1�Ϳ�����
};
struct LNode L;
List Ptrl;

//��ʼ��������һ���ձ�
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List)malloc(sizeof(struct LNode));
	Ptrl -> Last = -1;
	return  Ptrl;

}

//����
int Find(int number, List Ptrl)
{
	int i = 0;
	while (i <= Ptrl->Last && Ptrl->data[i] != number) {
		i++;
	}
	if (i > Ptrl->Last) return -1;
	else  return i;

}

//����,���ƶ����ٲ���
void insert(int number, int i, List Ptrl)
{
	int j;
	if (Ptrl->Last == Max - 1) {
		printf("����");
		return;
	}
	if (i<1 || i>Ptrl -> Last + 2) {
		printf("λ�ò��Ϸ�");
		return;
	}
	for (j = Ptrl->Last; j >= i - 1; j--) {
		Ptrl->data[j + 1] = Ptrl->data[j];
	}
	Ptrl->data[i - 1] = number;
	Ptrl->Last++;
}

//ɾ��
void Delete(int i, List Ptrl)
{
	int j;
	if (i < 1 || Ptrl->Last + 1) {
		printf("�����ڵ�%d��Ԫ��", i);
		return;
	}
	for (j = i; j <= Ptrl -> Last; j++) {
		Ptrl->data[j - 1] = Ptrl->data[j];
	}
	Ptrl->Last--;
	return;
}

