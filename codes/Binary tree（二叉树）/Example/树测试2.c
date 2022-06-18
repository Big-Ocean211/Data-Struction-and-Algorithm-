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
void ExchangeLeftRightSubtree(Node* rootNode);  // ������������ 
void LevelTraversal(Node* rootNode);  // ��α���

/*
Input:
2
1 0 2 0 3 0 0 -1
1 2 3 4 0 5 6 0 0 0 0 0 0 -1
Output:
1 2 0 3 0 0 0 
1 3 2 6 5 0 4 0 0 0 0 0 0 
*/

int main(){
	int i,n;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // ����n������ 
		Node* rootNode = TreeCreate();
		ExchangeLeftRightSubtree(rootNode);
		LevelTraversal(rootNode); 
		printf("\n");
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

void ExchangeLeftRightSubtree(Node* rootNode){
	if(rootNode != NULL){  // �ǿս�� 
		if(rootNode->left || rootNode->right){  // ���ҽ�㲻���ǿս�� 
			Node* temp;  // ������� 
			temp = rootNode->left;
			rootNode->left = rootNode->right;
			rootNode->right = temp;
		}
		ExchangeLeftRightSubtree(rootNode->left);
		ExchangeLeftRightSubtree(rootNode->right);
	}
}

void LevelTraversal(Node* rootNode){
	Node* temp;
	
	Node* queue[1000];  // �����ն��� 
	int begin = -1;
	int end = -1;

	queue[++ end] = rootNode;  // �������� 
	
	while(begin != end){  // ���в�Ϊ�� 
		temp = queue[++ begin];  // ���� 
		printf("%d ",temp->value);
		
		if(temp->value == 0)  // �ս�� 
			continue;
		
		if(temp->left)  // ���㲻Ϊ�� 
			queue[++ end] = temp->left;  // ��� 
		else{
			temp->value = 0;  // �ս����� 
			queue[++ end] = temp;
		}
		if(temp->right)  // �ҽ�㲻Ϊ�� 
			queue[++ end] = temp->right;  // ��� 
		else{
			temp->value = 0;  // �ս�����
			queue[++ end] = temp;
		}
		
	}
}

