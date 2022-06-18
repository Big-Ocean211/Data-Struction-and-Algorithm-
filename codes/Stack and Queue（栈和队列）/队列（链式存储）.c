#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{  // ���Ľṹ�� 
	int value;  // ���ֵ 
	struct node* next;  // ָ����һ������ָ�� 
}Node;

typedef struct queue{  // ���еĽṹ�� 
	Node* begin;  // ָ���β��ָ�� 
	Node* end;  // ָ���ͷ��ָ��
}Queue;

Queue QueueCreate();  // ����һ���ն��� 
void EnQueue(Queue* q,int value);  // Ԫ����� 
int DeQueue(Queue* q);  // Ԫ�س��� 
bool IsEmpty(Queue* q);  // �ж϶����Ƿ�Ϊ�� 
 
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
	q.begin = q.end = NULL;
	
	return q;
}

void EnQueue(Queue* q,int value){
	Node* temp;  // �����½�� 
	temp = (Node*)malloc(sizeof(Node));  // ����ռ� 
	temp->next = NULL;  // ��ʼ�� 
	temp->value = value;
	
	if(IsEmpty(q))  // ����Ϊ�� 
		q->begin = q->end = temp;
	else{  // ���в�Ϊ�� 
		q->end->next = temp;  // ����½�� 
		q->end = q->end->next;  // �ƶ���ͷendָ�� 
	}
}

int DeQueue(Queue* q){
	if(IsEmpty(q)){  // ����Ϊ�� 
		printf("Error for empty\n");
		exit(1);
	}
	else{
		Node* temp = q->begin;  // ����ɾ�����ĵ�ַ 
		
		q->begin = q->begin->next;  // �ƶ���βbeginָ�� 
		int value = temp->value;
		
		free(temp);  // �ͷ��ڴ� 
		
		return value;
	}
}

bool IsEmpty(Queue* q){
	return (q->begin == NULL);
}
