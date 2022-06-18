#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node Node;  // �����Ľṹ�� 
typedef struct node{
	Node* left;  // ���ӽ�� 
	Node* right;  // �Һ��ӽ�� 
	char value;  // ���ֵ
}Node; 

void TreeNodeCreate(Node** node);  // ����һ����(����)
void LevelTraversal(Node* node);  // ��α���

/*
Input:
ABC--DE-G--F---
Output:

*/

int main(){
	Node* rootNode;  // ����� 
	TreeNodeCreate(&rootNode);
	
	LevelTraversal(rootNode);
	
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
		
		TreeNodeCreate(&(*node)->left);
		TreeNodeCreate(&(*node)->right);
	}
}

void LevelTraversal(Node* node){
	Node* queue[100];  // �����ն��У����ڸö��в���ѭ�����У��������Ľ�㲻Ҫ����100���� 
	int begin,end;
	begin = end = -1;
	
	Node* temp = node;  // �������� 
	queue[++ end] = temp;  
	
	while(begin != end){
		temp = queue[++ begin];  // ������ 
		printf("%c",temp->value);
		
		if(temp->left)  // ���ӽ��ǿս�� 
			queue[++ end] = temp->left;  // ������ 
			
		if(temp->right)  // �Һ��ӽ��ǿս�� 
			queue[++ end] = temp->right;  // ������ 
	}
}
