#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node Node;  // �����Ľṹ�� 
typedef struct node{
	Node* left;  // ���ӽ�� 
	Node* right;  // �Һ��ӽ�� 
	char value;  // ���ֵ
	bool tag;  // �Ƿ�����ջ�ı�־�����ں�������� 
}Node; 

void TreeNodeCreate(Node** node);  // ����һ����(����)
void PreorderTraversal(Node* node);  // ������� 
void InorderTraversal(Node* node);  // ������� 
void PostorderTraversal(Node* node);  // ������� 

/*
Input:
ABC--DE-G--F---
Output:
ǰ��ABCDEGF
����CBEGDFA
����CGEFDBA
*/

int main(){
	Node* rootNode;  // ����� 
	TreeNodeCreate(&rootNode);
	
	printf("����");
	PreorderTraversal(rootNode);
	printf("\n");
	
	printf("����");
	InorderTraversal(rootNode);
	printf("\n");
	
	printf("����");
	PostorderTraversal(rootNode);
	printf("\n");
	return 0;
}

void TreeNodeCreate(Node** node){
	char ch;
	ch = getchar();  // ��������ֵ
	 
	if(ch == '-')  // �ս�� 
		*node = NULL;
	else{  // �ǿս�� 
		(*node) = (Node*)malloc(sizeof(Node));
		(*node)->value = ch;
		(*node)->tag = false;
		
		TreeNodeCreate(&(*node)->left);
		TreeNodeCreate(&(*node)->right);
	}
}

void PreorderTraversal(Node* node){
	Node* temp = node;  // ��ʼ�� 
	
	Node* stack[1000];  // ������ջ 
	int top = -1;
	
	while(top != -1 || temp){  // ջ��Ϊ����temp��Ϊ�ս�� 
		while(temp){  // ������������ 
			stack[++ top] = temp;
			printf("%c",temp->value);
			temp = temp->left;
		}
		
		if(top != -1){  // ջ��Ϊ��
			temp = stack[top --];
			temp = temp->right;
		}
	}
}

void InorderTraversal(Node* node){
	Node* temp = node;  // ��ʼ��
	
	Node* stack[1000];  // ������ջ 
	int top = -1;
	
	while(top != -1 || temp){  // ջ��Ϊ����temp��Ϊ�ս�� 
		while(temp){  // ������������ 
			stack[++ top] = temp;
			temp = temp->left;
		}
		
		if(top != -1){  // ջ��Ϊ��
			temp = stack[top --];
			printf("%c",temp->value);
			temp = temp->right;
		}
	}
}

void PostorderTraversal(Node* node){
	Node* temp = node;  // ��ʼ��
	
	Node* stack[1000];  // ������ջ 
	int top = -1;
	
	while(top != -1 || temp){  // ջ��Ϊ����temp��Ϊ�ս�� 
		while(temp){  // ������������ 
			stack[++ top] = temp;
			temp = temp->left;
		}
		
		if(top != -1){  // ջ��Ϊ��
			temp = stack[top --];
			if(!temp->tag){  // ���û���ջ 
			
				temp->tag = true;  // �޸�tagֵ��������ջ 
				stack[++ top] = temp;
				
				temp = temp->right;
			}
			else{  // ������ջ
				printf("%c",temp->value);
				temp = NULL;
			}
		}
	}
}
