#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

typedef struct node Node;  // ���ڵ�Ľṹ�� 
typedef struct node{
	Node* left;
	bool isLeftThread;
	Node* right;
	bool isRightThread;
	int value;
}Node; 

Node* currentNode;  // �����������������������б�ʾ��ǰ��� 

Node* TreeCreate();  // ������(���)
void InorderInthreadTree(Node* node);  // ���������������� 
Node* PrecursorNode(Node* node);  // ��ǰ����� 
Node* ReardriveNode(Node* node);  // �������� 
void LevelTraversal(Node* rootNode);  // ��α�������ǰ�����ͺ������ 

/*
Input:
3
1 0 0  -1
1 2 3 0 0 0 0  -1
1 2 3 4 0 0 5 6 7 8 9 0 0 0 0 0 0 0 0  -1
Output:
0 0
2 3 0 1 1 0
2 3 7 1 1 8 6 7 8 9 0 4 4 2 3 5 5 0
*/

int main(){
	int i,n;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // ����n������ 
		currentNode = NULL; 
		Node* rootNode = TreeCreate();
		
		InorderInthreadTree(rootNode);  // ������ 
		
		if(currentNode){  // ���һ�����ĺ������Ϊ�� 
			currentNode->isRightThread = true;
			currentNode->right = NULL;
		}
		
		LevelTraversal(rootNode);  // ���� 
		printf("\n");
	}
	
	return 0;
}

Node* TreeCreate(){
	Node* rootNode;  // ���ڵ� 
	Node* temp;
	
	Node* queue[1000];  // �����ն��� 
	int begin,end;

	begin = end = -1;
	int num;
	scanf("%d",&num);
	if(num == 0)  // �ս�� 
		return NULL;
	else{  // �ǿս�� 
		rootNode = (Node*)malloc(sizeof(Node));
		rootNode->value = num;
		rootNode->isLeftThread = rootNode->isRightThread = false;
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
			temp->left->isLeftThread = temp->left->isRightThread = false;
			
			queue[++ end] = temp->left;  // ��� 
		}
		
		scanf("%d",&num);  // �Һ��ӽ�㴦��
		if(num == 0)  
			temp->right = NULL;
		else{
			temp->right = (Node*)malloc(sizeof(Node));
			temp->right->value = num;
			temp->right->isLeftThread = temp->right->isRightThread = false;
			
			queue[++ end] = temp->right;  // ��� 
		}
	}
	
	scanf("%d",&num);  // ��������-1 
	return rootNode;
}

void InorderInthreadTree(Node* node){
	if(node){
		InorderInthreadTree(node->left);
		
		if(!node->left){  // ���ǰ����� 
			node->isLeftThread = true;
			node->left = currentNode; 
		}
		if(currentNode && !currentNode->right){  // ��Ӻ������ 
			currentNode->isRightThread = true;
			currentNode->right = node;
		}
		currentNode = node;  // ���½�� 
		
		InorderInthreadTree(node->right);
	}
}

Node* PrecursorNode(Node* node){
	if(!node)
		return NULL;
	
	if(node->isLeftThread)  // �������� 
		return node->left;
		
	Node* temp = node->left;  // �����������ҽ�� 
	while(!temp->isRightThread)  
		temp = temp->right;
		
	return temp;
}

Node* ReardriveNode(Node* node){
	if(!node)
		return NULL;
	
	if(node->isRightThread)  // �������� 
		return node->right;
		
	Node* temp = node->right;  // ��������������
	while(!temp->isLeftThread)
		temp = temp->left;
		
	return temp;
}

void LevelTraversal(Node* rootNode){
	Node* temp;
	
	Node* queue[1000];  // �����ն��� 
	int begin = -1;
	int end = -1;

	queue[++ end] = rootNode;  // �������� 
	
	while(begin != end){  // ���в�Ϊ�� 
		temp = queue[++ begin];  // ���� 
		printf("%d ",PrecursorNode(temp) ? PrecursorNode(temp)->value : 0);  // ���ǰ����� 
		printf("%d ",ReardriveNode(temp) ? ReardriveNode(temp)->value : 0);  // ���������� 
		
		if(!temp->isLeftThread)  // ���㲻Ϊ�� 
			queue[++ end] = temp->left;  // ��� 
		if(!temp->isRightThread)  // �ҽ�㲻Ϊ�� 
			queue[++ end] = temp->right;  // ��� 
		
	}
}
