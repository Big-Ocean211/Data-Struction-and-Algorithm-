#include <stdio.h>
#include <stdbool.h>
#define MAX 100  // ��ջ������� 
#define ERROR -1

typedef struct stack{  // ��ջ�Ľṹ�� 
	int array[MAX];  // �����ֵ�����飨����ֵ��0��ʼ�� 
	int top;  // ջ��Ԫ�ص�����ֵ 
}Stack;

Stack StackCreate();  // ����һ����ջ 
void Push(Stack* sp,int value);  // ����ջ��Ԫ�� 
int Pop(Stack* sp);  // ��ջ��ѹ��Ԫ��
bool IsEmpty(Stack* sp);  // �ж�ջ���Ƿ�Ϊ�� 
bool IsFull(Stack* sp);  // �ж�ջ���Ƿ�Ϊ��

/*
Output: 15 25 10
*/

int main(void){
    Stack s = StackCreate();
	
    Push(&s,10);
	Push(&s,25); 
	Push(&s,15);
	
	printf("%d ",Pop(&s));
	printf("%d ",Pop(&s));
	printf("%d ",Pop(&s));

	return 0;
} 

Stack StackCreate(){
    Stack s;  // �����ն�ջ
	s.top = -1;

    return s;
}

void Push(Stack* sp,int value){
	if(IsFull(sp)){  // ջΪ��
		printf("Stack is full\n");
		return;
	}
	else
		sp->array[++ sp->top] = value;  // ѹ��Ԫ��
	
}

int Pop(Stack* sp){
	if(IsEmpty(sp)){  // ջΪ��
		printf("Stack is empty\n");
		return -1;
	}
	else
		return sp->array[sp->top --];  // ����Ԫ��
} 

bool IsEmpty(Stack* sp){
	return (sp->top == -1);
}

bool IsFull(Stack* sp){
	return (sp->top + 1 == MAX);
}