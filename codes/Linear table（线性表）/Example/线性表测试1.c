#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;  // ����ڵ�Ľṹ�� 
typedef struct node{
	int val;
	Node* next;
}Node;
// ����Ϊ��ͷ��������

void Add(Node* head,int val);  // ����Ĳ��� 
void ListReverse(Node* head);  // ��ת���� 
void Print(Node* head);  // ���������� 
void ListMerge(Node* ahead,Node* bhead,Node* chead);  // ��������鲢Ϊһ������ 

/*
Input:
2
5 5
1 2 3 4 5
1 2 3 4 5
3 3
2 4 8
3 6 9
Output:
5 5 4 4 3 3 2 2 1 1
9 8 6 4 3 2
*/

int main(void){
	int n,i,j,val;
    int len1,len2;  // ����A,B�ĳ���

	scanf("%d",&n);
	Node ahead,bhead,chead;  // ��������A,B,C��ͷ��� 
	
	for(i = 0; i < n; i ++){
		
		//  ��ʼ�� 
		ahead.next = NULL;
		bhead.next = NULL;
		chead.next = NULL;
		scanf("%d %d",&len1,&len2);
		
		for(j = 0; j < len1; j ++){  // ����A����
			scanf("%d",&val);
			Add(&ahead,val);
		}
		
		for(j = 0; j < len2; j ++){  // ����B����
			scanf("%d",&val);
			Add(&bhead,val);
		}
		
		// ��תA��B����ʹ�����ǰ��ݼ���������
		ListReverse(&ahead);
		ListReverse(&bhead);
		
		// �鲢A��B�����鲢�������C���ݼ���������
		ListMerge(&ahead,&bhead,&chead);
		
		Print(&chead);
		
		//  �ͷ��ڴ棬������һ�ֵ����� 
		Node* scan = chead.next;
		while(scan){
			Node* temp = scan;
			scan = scan->next;
			free(temp);
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

void ListReverse(Node* head){  // ��ת����������3����ʱ�ڵ������ 
	Node* a = head;
	Node* b = head->next;
	Node* c = head->next->next;
	
	b->next = NULL;  // ��ת��������һ�����nextָ����ΪNULL

	while(c){
		a = b;
		b = c;
		c = c->next;
		b->next = a;  // �����µ�nextָ��
	}
	
	head->next = b;  // ͷ���ָ��ת����ĵ�һ�����
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
		
	while(scan1 && scan2){  // A,B����û�й鲢��
			
		if(scan1->val >= scan2->val){
			scan->next = scan1;
			scan1 = scan1->next;
			scan = scan->next;
		}
		else{
			scan->next = scan2;
			scan2 = scan2->next;
			scan = scan->next;
		}
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
