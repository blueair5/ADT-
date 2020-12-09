#include <stdio.h>
# define MaxSize 100
typedef struct Snode {
	int data[MaxSize];
	int rear=0;
	int front=0;
};
typedef struct Snode*  Quene;
void push(int a,Quene Ptrq)
{
	if ((Ptrq->rear+1) %MaxSize == Ptrq->front){
		printf("队列满");
		return;
	}
	else {
		Ptrq->rear = (Ptrq->rear + 1) % MaxSize;
		Ptrq->data[Ptrq->rear] = a;
	}
}

int pop(Quene Ptrq)
{
	if (Ptrq->front == Ptrq->rear) {
		printf("队列空");
		return;
	} else {
		Ptrq->front = (Ptrq->front+1)%MaxSize;
		return Ptrq->data[Ptrq->front];

	}
}

int main()
{

}