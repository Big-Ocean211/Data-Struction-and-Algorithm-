#include <stdio.h>
#define ERROR -1

int array[1200];  // ������ݵ�����

int Find(int array[],int n);  // ���ֲ���

/*
Input:
2
4
-1 1 3 4
5
1 2 3 4 5
Output:
1
-1
*/

int main(){
	
	int i,j,n,m;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // ����n������

		scanf("%d",&m);  // ��ȡ����
		for(j = 0; j < m; j ++)
			scanf("%d",array + j);
		
		printf("%d\n",Find(array,m));
	}

	return 0;
} 

int Find(int array[],int n){  // ���ö��ֲ��ң��ҳ�����mid = array[mid]��Ԫ��
	int left = 0, right = n - 1;  // ��ʼ��
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		if(mid < array[mid])  // ���߲���
			right = mid - 1;
		else if(mid > array[mid])  // �Ұ�߲���
			left = mid + 1;
		else  // ���ҳɹ�
			return mid;
	}
	
	return ERROR;  // ����ʧ��
}
