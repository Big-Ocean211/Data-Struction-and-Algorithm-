#include <stdio.h>
#include <string.h>

char s[501], t[501];  // sΪ������tΪģʽ��
// �ַ���������1��ʼ 

/*
Input:
12345
234
Output:
2
*/

int Func(char* s,char* t){
	t[0] = strlen(t + 1);  // ��¼�ַ���t�ĳ��� 
	
	int i = 1,j = 1;  // �ַ���������ʼ�� 
	while(s[i]){
		while(s[i] == t[j] && t[j]){  // �ַ����ʱ 
			i ++;
			j ++;
		}
		if(!t[j])  // ƥ��ɹ� 
			return i - t[0];  // ����ģʽ��������������ֵ 
		else{  // ����ƥ��ʧ�� 
			i = i - j + 2;  // �������ص�����ƥ�俪ʼ����һ���ַ� 
			j = 1;  // ģʽ���ص���ͷ 
		}
	}
	
	return 0;  // ����ƥ��ʧ��
}

int main(){
	scanf("%s %s",s + 1,t + 1);  // ��ȡ�ַ��� 
	
	int num = Func(s,t);
	if(num)  // ƥ��ɹ� 
		printf("%d\n",num);
	else  // ƥ��ʧ�� 
		printf("ƥ��ʧ��\n"); 
	return 0;
}

