#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;  // ����ڵ�Ľṹ�� 
typedef struct node{
	int val;
	Node* next;
}Node;
// ����Ϊ��ͷ��������

void Add(Node* head,int val);  // ����Ĳ��� 
void Print(Node* head);  // ���������� 
void ListMerge(Node* ahead,Node* bhead,Node* chead);  // ��������鲢Ϊһ������ 

/*
Input:
2
3 4
1 2 3
1 2 3 4
5 2
1 1 1 1 1
2 2
Output:
1 1 2 2 3 3 4
1 2 1 2 1 1 1
*/

int main(void){
	int n,i,j,val;
    int len1,len2;  // ��������A,B�ĳ���
	scanf("%d",&n);
	Node ahead,bhead,chead;  // ��������A,B,C��ͷ��� 
	
	for(i = 0; i < n; i ++){
	
		//  ��ʼ�� 
		ahead.next = NULL;
		bhead.next = NULL;
		chead.next = NULL;
		scanf("%d %d",&len1,&len2);
		
		for(j = 0; j < len1; j ++){
			scanf("%d",&val);
			Add(&ahead,val);
		}
		
		for(j = 0; j < len2; j ++){
			scanf("%d",&val);
			Add(&bhead,val);
		}
		
		// �鲢A��B����
		ListMerge(&ahead,&bhead,&chead);
		
		Print(&chead);
		
		//  �ͷ��ڴ棬������һ�ֵ����� 
		Node* scan = chead.next;
		while(scan){
			Node* temp = scan;
			scan = scan->next;
			free(temp);
			temp = NULL;
		}
		
	}
	return 0;
}

void Add(Node* head,int val){
	Node* scan = head;
	while(scan->next)
		scan = scan->next;
		
	Node* node = (Node*)malloc(sizeof(Node));  // �����½ڵ� 
	node->next = NULL;
	node->val = val;
	
	scan->next = node;  // ���ڵ�������� 
}

void Print(Node* head){  // �������� 
	Node* scan = head->next;

	while(scan){
		printf("%d ",scan->val);
		scan = scan->next;
	}
	printf("\n");
}

void ListMerge(Node* ahead,Node* bhead,Node* chead){
	Node* scan1 = ahead->next;
	Node* scan2 = bhead->next;
	Node* scan = chead;
		
	while(scan1 && scan2){  //   A��B����δȫ���鲢ʱ��C������������A��B�����Ԫ��
			
		scan->next = scan1;
		scan1 = scan1->next;
		scan = scan->next;

		scan->next = scan2;
		scan2 = scan2->next;
		scan = scan->next;
		
	}
		
	while(scan1){  // B������ȫ���鲢��C���� 
		scan->next = scan1;
		scan1 = scan1->next;
		scan = scan->next;
	}
	while(scan2){  // A������ȫ���鲢��C���� 
		scan->next = scan2;
		scan2 = scan2->next;
		scan = scan->next;
	}
}
