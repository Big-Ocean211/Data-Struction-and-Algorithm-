#include <stdio.h>

char string[120];  // ��ű��ʽ������ 
char stack[5];  // ����ջ 
int prior[50];  // ���������ASCII����ʾ���ȼ� 

int main(){
	prior[43] = prior[45] = 1;  // +��-�����ȼ� 
	prior[42] = prior[47] = 2;  // /��*�����ȼ� 
	int n,m,i,j;
	int count = -1;  // ��ʼ��ջΪ�� 
	char ch;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // ����n����ʽ 
		scanf("%d",&m);  // ��ȡ���ʽ���� 
		scanf("%s",string);  // ��ȡ���ʽ 
		
		for(j = 0; j < m; j ++){
			if('A' <= string[j] && string[j] <= 'Z')  // ��д��ĸֱ����� 
				printf("%c",string[j]);
			else{  // ����������ж� 
				ch = string[j];  // ���汾������� 
				while(count >= 0 && prior[ch] <= prior[stack[count]])  // �������������������ȼ���ߵ� 
					printf("%c",stack[count --]);  // �ȴ�ջ���е������������������ 
				stack[++ count] = ch;  // ���������ֱ����ջ 
			}
			
		}
		
		while(count >= 0)  // ���ջ�е��������� 
			printf("%c",stack[count --]);
		printf("\n");
		
	}
	
	return 0;
}
