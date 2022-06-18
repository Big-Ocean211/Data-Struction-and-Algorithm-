#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;  // �����Ľṹ�� 
typedef struct node{
	Node* left;  // ���ӽ�� 
	Node* right;  // �Һ��ӽ�� 
	char value;  // ���ֵ 
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
		
		TreeNodeCreate(&(*node)->left);
		TreeNodeCreate(&(*node)->right);
	}
}

void PreorderTraversal(Node* node){
	if(node != NULL){
		printf("%c",node->value);
		PreorderTraversal(node->left);
		PreorderTraversal(node->right);
	}
}

void InorderTraversal(Node* node){
	if(node != NULL){
		InorderTraversal(node->left);
		printf("%c",node->value);
		InorderTraversal(node->right);
	}
}

void PostorderTraversal(Node* node){
	if(node != NULL){
		PostorderTraversal(node->left);
		PostorderTraversal(node->right);
		printf("%c",node->value);
	}
}

