#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define ERROR -1 

typedef struct node{  // ���Ľṹ�� 
	int value;  // ���ֵ 
	struct node* next;  // ָ����һ������ָ�� 
}Node;

Node* StackCreate();  // ����һ����ջ 
int Pop(Node* head);  // ����ջ��Ԫ�� 
void Push(Node* head,int value);  // ��ջ��ѹ��Ԫ�� 
bool IsEmpty(Node* head);  // �ж�ջ���Ƿ�Ϊ�� 

/*
Output: 15 25 10
*/

int main(void){
	int i;
	Node* head = StackCreate();
	
	Push(head,10);
	Push(head,25); 
	Push(head,15);
	
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	
	return 0;
}

Node* StackCreate(){
	Node* head;  // ͷ��㣬ͷ��㲻�����ֵ��ָ��ʼ��ָ��ջ��Ԫ��
	
	head = (Node *)malloc(sizeof(Node));  // ��ʼ�� 
	head->next = NULL;
	
	return head;
}

void Push(Node* head,int value){
	Node* temp;
	temp = (Node *)malloc(sizeof(Node));  // �����½�� 
	temp->value = value;
	
	temp->next = head->next;  // ѹ��Ԫ�� 
	head->next = temp;
}

int Pop(Node* head){
	if(IsEmpty(head)){  // ջΪ�� 
		printf("Stack is empty\n");
		return ERROR;
	}
	else{
		Node* temp = head->next;  // ����ɾ�����ĵ�ַ 
		head->next = temp->next;  // �ƶ�ͷ���ָ�� 
		
		int value = temp->value;
		
		free(temp);  // �ͷ��ڴ� 
		
		return value;  // ����ջ��Ԫ�ص���ֵ 
	}
}

bool IsEmpty(Node* head){
	return (head->next == NULL);
}

