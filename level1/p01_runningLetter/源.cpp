#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#pragma warning(disable : 4996)

#define LENGTH 50								//����
#define SET_CON "mode con cols=50 lines=10"		//���ÿ���̨��Ⱥ͸߶�

void show(char str[])							//������ո�֮���ӡ�ַ�
{
	printf("%s", str);
	Sleep(10);
	system("cls");
}
int main(void)
{
	char str[100];
	system(SET_CON);
	scanf("%s", &str);							//д��ʱ����Ϊ���Լ������ַ�
	int len = strlen(str);
	while (1) {
		for (int i = 0; i < LENGTH - len; i++)
		{
			for (int j = 0; j <= i; j++)
				printf(" ");
			show(str);
		}
		for (int i = 0; i < LENGTH - len; i++)
		{
			for (int j = LENGTH - len - i; j > 0; j--)
				printf(" ");
			show(str);
		}
	}
	return 0;
}