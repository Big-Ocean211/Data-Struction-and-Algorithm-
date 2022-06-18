#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;  // ���ڵ�Ľṹ�� 
typedef struct node{
	Node* left;
	Node* right;
	int value;
}Node; 

int count;
Node* TreeCreate();  // ����������Σ�
void CountLeafNode(Node* rootNode);  // ��������Ҷ���

/*
Input:
3
1 2 3 0 0 0 0 -1
1 0 2 0 3 4 0 0 0 -1
1 2 3 4 5 6 7 0 0 8 9 10 11 12 13 0 0 0 0 0 0 0 0 0 0 0 0 -1
Output:
2
1
7
*/ 

int main(){
	int i,n;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // ����n������ 
		Node* rootNode = TreeCreate();
		count = 0;  // count��0�����¼��� 
		CountLeafNode(rootNode);
		printf("%d\n",count);
	}
	
	return 0;
}

Node* TreeCreate(){
	Node* rootNode;  // ���ڵ� 
	Node* temp;
	
	Node* queue[1000];  // �����ն��� 
	int begin = -1;
	int end = -1;

	int num;
	scanf("%d",&num);
	if(num == 0)  // �ս�� 
		return NULL;
	else{  // �ǿս�� 
		rootNode = (Node*)malloc(sizeof(Node));
		rootNode->value = num;
		queue[++ end] = rootNode;
	}
	
	while(begin != end){  // ���в�Ϊ�� 
		temp = queue[++ begin];  // ���� 
		
		scanf("%d",&num);  // ���ӽ�㴦��
		if(num == 0)   
			temp->left = NULL;
		else{
			temp->left = (Node*)malloc(sizeof(Node));
			temp->left->value = num;
			queue[++ end] = temp->left;  // ��� 
		}
		
		scanf("%d",&num);  // �Һ��ӽ�㴦��
		if(num == 0)  
			temp->right = NULL;
		else{
			temp->right = (Node*)malloc(sizeof(Node));
			temp->right->value = num;
			queue[++ end] = temp->right;  // ��� 
		}
	}
	
	scanf("%d",&num);  // ��������-1 
	return rootNode;
}

void CountLeafNode(Node* rootNode){
	if(rootNode != NULL){  // �ǿս�� 
		if(rootNode->left == NULL && rootNode->right == NULL)  // ���ΪҶ��� 
			count ++;
		CountLeafNode(rootNode->left);
		CountLeafNode(rootNode->right);
	}
}

