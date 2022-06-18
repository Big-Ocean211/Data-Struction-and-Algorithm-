#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
//#define MAX 100

typedef struct table{  // ���Ա�ṹ�� 
	int* array;  // ������ݵ����飬����ֵ��0��ʼ 
	int capacity;  // ���Ա�������� 
	int size;  // ��ǰԪ�ظ���
}Table;

Table Initialization(int capacity);  // �������Ա� 
void Insert(Table* tablep,int index,int element);  // ���Ա�Ԫ�ز��� 
int Find(Table table,int element);  // ���Ա�Ԫ�ز���(����Ԫ��ֵ)
void DelElement(Table* tablep,int element);  // ���Ա�Ԫ��ɾ��(����Ԫ��ֵ)
void DelIndex(Table* tablep,int element);  // ���Ա�Ԫ��ɾ��(��������ֵ)
int Length(Table table);  // �����Ա��� 
int Top(Table table);  // �����Ա����һ��Ԫ�� 
void Print(Table table);  // ˳��������Ա��Ԫ�� 

/*
Output: 4 3 2 1 0
*/

int main(void){
    Table table;
    table = Initialization(50);
    
    int i;
    for(i = 0; i < 5; i ++)
    	Insert(&table,0,i);
	
	Print(table);
	printf("\n");

    return 0;
}

Table Initialization(int capacity){
	Table table;
	table.array = (int*)malloc(sizeof(int) * capacity);  // ����ռ� 
	table.capacity = capacity;  // ���Ա�������� 
	table.size = 0;  // ���Ա��ʼ��Ϊ�� 
	return table;
}

void Insert(Table* tablep,int index,int element){
	
	if(Length(*tablep) == tablep->capacity){  // ���Ա����� 
		printf("Error for full of room\n");
		return;
	}
	
	if(index < 0 || index > Length(*tablep)){  // ����ֵ����
		printf("Error for index value\n");
		return;
	}
	
	int i;
	for(i = Length(*tablep); i >= index + 1; i --)  // �Ӻ���ǰ�ƶ�Ԫ�� 
		tablep->array[i] = tablep->array[i - 1];
	
	tablep->array[index] = element;  // ����Ԫ�� 
	tablep->size ++;  // ���Ա�Ԫ�ظ�����һ 
}

int Find(Table table,int element){
	int i;
	for(i = 0; i < Length(table); i ++){  // �������Ա� 
		if(element == table.array[i])  // ���ҳɹ�����������ֵ 
			return i;
	}
	
	printf("Error for not find\n");  // ����ʧ�� 
	return ERROR;
}

void DelElement(Table* tablep,int element){
	int i;
	for(i = 0; i < Length(*tablep); i ++){  // �������Ա� 
		if(element == tablep->array[i]){  // ɾ���ɹ� 
			tablep->size --;  // ���Ա�Ԫ�ظ�����һ 
			return;
		}
	}
	
	printf("Error for not find\n");  // ɾ��ʧ�� 
}

void DelIndex(Table* tablep,int index){
	if(Length(*tablep) == 0){  // ���Ա�Ϊ�� 
		printf("Error for the linear table is empty\n");
		return;
	}
	
	if(index < 0 || index >= Length(*tablep)){  // ����ֵ����
		printf("Error for index value\n");
		return;
	}
	
	int i;
	for(i = index; i < Length(*tablep) - 1; i ++)  // ��ǰ�����ƶ�Ԫ�� 
		tablep->array[i] = tablep->array[i + 1];  // ɾ��Ԫ�� 
	
	tablep->size --;  // ���Ա�Ԫ�ظ�����һ
}

int Length(Table table){
	return table.size;  // �������Ա��� 
}

int Top(Table table){
	if(!Length(table)){  // ���Ա�Ϊ�� 
		printf("Error for the linear table is empty\n");
		return ERROR;
	}
	else
		return table.array[table.size - 1];  // ����Ԫ��ֵ 
}

void Print(Table table){
	int i;
	for(i = 0; i < Length(table); i ++)  // �������Ա���� 
		printf("%d ",table.array[i]);
}
