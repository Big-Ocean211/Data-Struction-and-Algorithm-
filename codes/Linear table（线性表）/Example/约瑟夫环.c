#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;  // �����˵Ľṹ�� 
typedef struct node{
	int code;  // ���� 
	bool exist;  // exist = falseʱ��ʾ�˳��� 
}Node;
Node array[30];  // ���������ֵ�����˵ı�� - 1 

/*
Input:
20 7 3 1 7 2 4 8 4
Output:
6 1 4 7 2 3 5
*/

int main(void){
	int i,n,m;
	scanf("%d %d",&m,&n);  // ��ʼ��m��n 
	
	for(i = 0; i < n; i ++){  // ��ȡ���� 
		scanf("%d",&array[i].code);
		array[i].exist = true;
	}
	
	int scan = 0;
	for(i = 0; i < n; i ++){  // ������ģ��ѭ������ 
		
		while(!array[scan].exist)  // �������ҵ����ε�һ����������
			scan = (scan + 1) % n;
		
		while(-- m){  // ģ�ⱨ��
			scan = (scan + 1) % n;
			while(!array[scan].exist)  // �������ҵ���һ�������е���
				scan = (scan + 1) % n;
		}
		
		array[scan].exist = false;  // ģ���˵ĳ��� 
		printf("%d ",scan + 1);  // ������е��˵ı�� 
		m = array[scan].code;
		
	}
	return 0;
}

