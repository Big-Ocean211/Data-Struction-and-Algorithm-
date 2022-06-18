#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;  // �����Ľṹ�� 
typedef struct node{
	Node* left;  // ���ӽ�� 
	Node* right;  // �Һ��ӽ�� 
	char value;  // ���ֵ 
	int height;  // ������ 
}Node; 

void TreeNodeCreate(Node** node,int height);  // ����һ����(����)
void PrintTreeGroup(Node* node);  // ��ӡ����� 

/*
Input: 
AB-D--CE-F---
Output:
   C
         F
      E
A
      D
   B
*/

int main(){
	Node* rootNode;  // ���ĸ���� 
	
	TreeNodeCreate(&rootNode,1);
	
	PrintTreeGroup(rootNode);
	
	return 0;
}

void TreeNodeCreate(Node** node,int height){
	char ch;
	ch = getchar();
	if(ch == '-')  // �ս�� 
		*node = NULL;
	else{  // �ǿս�� 
	
		(*node) = (Node*)malloc(sizeof(Node));  // DRL��������
		(*node)->value = ch;
		(*node)->height = height;
		
		TreeNodeCreate(&(*node)->left,height + 1);
		TreeNodeCreate(&(*node)->right,height + 1);
	}
}

void PrintTreeGroup(Node* node){
	if(node != NULL){  // RDL��������
		PrintTreeGroup(node->right);
		
		int i;
		for(i = 1; i < node->height; i ++)  // ��ʽ����� 
			printf("   ");
		printf("%c\n",node->value);
		
		PrintTreeGroup(node->left);
	}
}

