#include <stdio.h>
#include <string.h>

char string[201];  // ���������ַ��� 
char stack[201];  // ����ջ 
int top = -1;  // top = -1��ʾջΪ�� 

/*
Input:
[ ([] []) ]
Output:
ƥ�� 
*/

void Func(int len){
	int i;
	char ch;
	for(i = 0; i < len; i ++){
		ch = string[i];  // ��ȡ���ַ�ʱ�Ƚ����ж� 
		if(ch == ' ')  // �ų��ո���� 
			continue;
		else if(top >= 0 && ( (stack[top] == '(' && ch == ')') || (stack[top] == '[' && ch == ']') ) )  // ջ�����ַ�����������ƥ�� 
			top --;  // ��ջ�е��������� 
		else if(ch == ']' || ch == ')'){  // ջ�����ַ��������Ų�ƥ�����Ϊ������������ 
			printf("�˴�����ƥ�䲻�Ϸ�\n");
			return;
		}
		else  // ����������ջ 
			stack[++ top] = ch;
		
	}
	printf("ƥ��\n");  // ƥ��ɹ� 
}

int main(){
	gets(string);  // ����������תΪ�ַ��� 
	int len = strlen(string);  // ��ȡ�����ַ����ĳ��� 
	
	Func(len);  // �ж�����ƥ��ĺ��� 
	return 0;
}

