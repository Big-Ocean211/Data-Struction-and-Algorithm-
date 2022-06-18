#include <stdio.h>
#include <stdbool.h>
#define MAX 50  // ���е��������
#define ERROR -1

typedef struct queue{  // ���еĽṹ�壨��ѭ�����б�ʾ��
	int array[MAX];  // �����ֵ�����飨����ֵ��0��ʼ��
	int begin;  // ��β������ֵ
	int end;  // ��ͷ������ֵ
}Queue;

Queue QueueCreate();  // ����һ���ն���
bool IsEmpty(Queue* q);  // �ж϶����Ƿ�Ϊ�� 
bool IsFull(Queue* q);  // �ж϶����Ƿ�Ϊ��
void EnQueue(Queue* q,int value);  // Ԫ����� 
int DeQueue(Queue* q);  // Ԫ�س��� 

/*
Output: 0 1 2 3 4
*/

int main(void){
	Queue q = QueueCreate();

    int i;
    for(i = 0; i < 5; i ++)
        EnQueue(&q,i);
    
    for(i = 0; i < 5; i ++)
        printf("%d ",DeQueue(&q));
	
	return 0;
}

Queue QueueCreate(){
    Queue q;  // ��ʼ������Ϊ��
	q.begin = q.end = -1;

    return q;
}

void EnQueue(Queue* q,int value){
	if(IsFull(q)){  // ����Ϊ��
		printf("Error for full\n");
		return;
	}
	else{
		q->end = (q->end + 1) % MAX;  // Ԫ�����
		q->array[q->end] = value;
	}
}

int DeQueue(Queue* q){
	if(IsEmpty(q)){  // ����Ϊ��
		printf("Error\n");
		return ERROR;
	}
	else{
		q->begin = (q->begin + 1) % MAX;  // Ԫ�س���
		return q->array[q->begin];
	}
}

bool IsEmpty(Queue* q){
	return (q->begin == q->end);
}

bool IsFull(Queue* q){
	return (q->end + 1) % MAX == q->begin;
}
