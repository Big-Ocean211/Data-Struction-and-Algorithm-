#include <stdio.h>
#include <string.h>

int next[1000];  // next���� 
char str1[500];  // ���� 
char str2[100];  // ģʽ�� 

void getnext(int len);  // ��next���� 

/*
Input:
12345
234
Output:
1
*/

int main(void){
	
	scanf("%s %s",str1,str2);  // ��ȡ������ģʽ�� 
	
	int len1 = strlen(str1);  // �������� 
	int len2 = strlen(str2);  // ģʽ������ 
	getnext(len2);  // ���next���� 
	
	int i = 0;  // ��ʼ�� 
	int j = 0;
	
	while(i < len1 && j < len2){  // kmpģʽƥ�� 
		if(j == -1 || str1[i] == str2[j]){  // �ַ���ͬʱi��jͬʱ�ƶ� 
			i ++;
			j ++;
		}
		else
			j = next[j];  // jת��ָ��λ�ã�i����Ҫ���� 
		
	}
	
	if(j == len2)  // ƥ��ɹ� 
		printf("%d",i - j);  // ����ģʽ��λ�� 
	else  // ƥ��ʧ�� 
		printf("-1");
		
	return 0;
}

void getnext(int len){
	int j,k;
	next[0] = -1;  // �����j�޷��ƶ��������д˳�ʼ�� 
	
	j = 0;
	k = -1;
	
	while(j < len - 1){
		if(k == -1 || str2[k] == str2[j])  // ����ֵj��k��Ӧ���ַ���Ȼ�k = -1ʱ 
			next[++ j] = ++ k;
		else  // kת��ָ��λ�� 
			k = next[k];
	}
} 
