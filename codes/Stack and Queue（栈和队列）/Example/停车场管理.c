#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ������Ŀû�и��շѱ�׼��Ĭ��Ϊ1ʱ�䵥λһԪ�������Ļ�������ʱ����Ƕ�Ӧ��ͣ���ѣ���˵��Խ�������ʱ�����Ƕ�Ӧ��ͣ����

typedef struct car Car;  // �����Ľṹ�� 
typedef struct car{
	int id;  // ���� 
	int time;  // �볡ʱ��
	Car* next;  // ֻ�ڱ���������壬��ʾ��һ����
}Car; 

int n;  // ͣ������С 

Car parking[200];  // ��ջģ��ͣ���� 
int count1 = -1;  // count = -1��ʾͣ����Ϊ�� 
Car stack[200];  // stackջ������ʱͣ������·��ȥ������ 
int count2 = -1;  // count2 = -1��ʾstackջΪ�� 

Car* begin = NULL;  // begin = end = NULL ��ʾģ�����Ķ��� 
Car* end = NULL;
int count3 = -1;  // count3 = -1��ʾ���Ϊ�� 

void LineEnter(int id,int time);  // Ԫ�ؽ������ 
Car LineLeave();  // Ԫ���뿪���� 

/*
Input:
2
A 4 25
A 5 30
A 1 35
D 2 40
D 1 45
D 4 50
E 0 0
Output:
ID: 4 Parking: 0
ID: 5 Parking: 1
ID: 1 Line: 0
Not find
Not find
ID: 4 Time: 25
ID: 1 Parking: 1
*/

int main(){
	int i,j;
	scanf("%d",&n);   
	getchar();  // �ų�\n�ĸ��� 
	
	char ch;
	int id,time;
	bool flag;
	while(true){
		flag = true; // flag = true��ʾ��ch == 'D'������ҵ�Ԫ�� 
		scanf("%c %d %d",&ch,&id,&time);
		getchar();  // �ų�\n�ĸ���
		
		if(ch == 'A'){  // ����׼������
			if(n - 1 > count1){  // ͣ������λ�� 
				++ count1;
				parking[count1].id = id;
				parking[count1].time = time;
				printf("ID: %d Parking: %d\n",id,count1);
			}
			else{  // ͣ����ûλ��
				LineEnter(id,time);  // ������ 
				printf("ID: %d Line: %d\n",id,count3);
			}
		}
		else if(ch == 'D'){  // ����׼���뿪
			while(parking[count1].id != id && count1 >= 0)  // �鵽����ID������ 
				stack[++ count2] = parking[count1 --];
				
			if(count1 >= 0){  // ���ҳɹ� 
				printf("ID: %d Time: %d\n",id,time - parking[count1].time);
				count1 --;
			}
			else{  // ����ʧ��
				printf("Not find\n");
				flag = false;
			}
			
			while(count2 >= 0)  // ͨ��stack�ָ�ԭ���������Ⱥ�˳�� 
				parking[++ count1] = stack[count2 --];
			
			if(begin && flag){  // �����Ϊ����ͣ�������� 
				parking[++ count1] = LineLeave();  // �����뿪�������ͣ����
				parking[count1].time = time;  // ������������ͣ������ʱ�� 
				printf("ID: %d Parking: %d\n",parking[count1].id,count1); 
			}
		}
		else
			break;
	}
	return 0;
}

void LineEnter(int id,int time){
	Car* temp = (Car*)malloc(sizeof(Car));  // ����������
	temp->next = NULL;
	temp->id = id;
	temp->time = time;
	
	if(!begin)  // ���Ϊ�� 
		begin = end = temp;
	else{  // �����Ϊ��
		end->next = temp;
		end = end->next;
	}
	count3 ++;
}

Car LineLeave(){
	Car temp;  // �����뿪���
	temp.id = begin->id;
	temp.time = begin->time;	

	Car* out = begin;
	
	begin = begin->next;  // ���������ǰ��
    count3 --;

	free(out);
	
	return temp;
}

