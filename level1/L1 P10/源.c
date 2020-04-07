#include<stdio.h>
#define Length 7
#pragma warning(disable : 4996)
void PrintMap(int map[Length][Length]);
void OpenFile(int map[Length][Length]);
void Player(int map[Length][Length]);
int map[Length][Length];
struct point {
	int x, y;
};
struct point p;
int box = 0;
int main(void)
{
	OpenFile(map);
	Player(map);
}
void PrintMap(int map[Length][Length])
{
	for (int i = 0; i < Length; i++) {
		for (int j = 0; j < Length; j++) {

			switch (map[i][j]) {
			case 0:printf("��"); break;
			case 1:printf("  "); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			case 6:printf("��"); break;//D:\map1.txt
			}
		}
		printf("\n");
	}
}

void OpenFile(int map[Length][Length])		//��֪Ϊʲô
{
	char file_address[100];
	printf("�������ļ�����");
	scanf("%s", &file_address);
	FILE* f;
	if ((f = fopen(file_address, "r")) == NULL){
		printf("δ��\n");
		exit(0);
	}else{
		for (int i = 0; i < Length; i++)
			for (int j = 0; j < Length; j++){
				fscanf(f, "%d", &map[i][j]);
				if (map[i][j] == 2){
					p.x = i;
					p.y = j;
				}
				else if (map[i][j] == 3)
					box++;
			}
	}
	PrintMap(map);
}
void Player(int map[Length][Length])
{
	int direction;
	int now_ok = 0;
	do {
		char c;
		scanf_s("%c", &c);
		int direction = c;
		switch (direction) {
		case 97://a
			if (map[p.x][p.y - 1] == 1 || map[p.x][p.y - 1] == 3) {
				map[p.x][p.y - 1] += 1;
				map[p.x][p.y] -= 1;
				p.y -= 1;
			}
			else if (map[p.x][p.y - 1] == 5 && (map[p.x][p.y - 2] == 1 || map[p.x][p.y - 2] == 3))
			{
				if (map[p.x][p.y - 2] == 3) { 
					map[p.x][p.y - 2] = 6;
					now_ok++;
				}else map[p.x][p.y - 2] = 5;
				map[p.x][p.y] = 1;
				map[p.x][p.y - 1] = 2;
				p.y -= 1;
			}
			break;
		case 100://d
			if (map[p.x][p.y+1] == 1 || map[p.x][p.y+1] == 3) {
				map[p.x][p.y+1] += 1;
				map[p.x][p.y] -= 1;
				p.y += 1;
			}
			else if (map[p.x][p.y+1] == 5 && (map[p.x][p.y+2] == 1 || map[p.x][p.y + 2] == 3))
			{
				if (map[p.x][p.y + 2] == 3)
				{
					map[p.x][p.y + 2] = 6;
					now_ok++;
				}
				else map[p.x][p.y + 2] = 5;
				map[p.x][p.y] = 1;
				map[p.x][p.y+1] = 2;
				p.y += 1;
			}
			break;
		case 119://w
			if (map[p.x - 1][p.y] == 1 || map[p.x - 1][p.y] == 3) {
				map[p.x - 1][p.y] += 1;
				map[p.x][p.y] -= 1;
				p.x -= 1;
			}
			else if (map[p.x - 1][p.y] == 5 && (map[p.x - 2][p.y] == 1 || map[p.x - 2][p.y] == 3))
			{
				if (map[p.x - 2][p.y] == 3) {
					map[p.x - 2][p.y] = 6;
					now_ok++;
				}
				else map[p.x-2][p.y] = 5;
				map[p.x][p.y] = 1;
				map[p.x - 1][p.y] = 2;
				p.x -= 1;
			}
			break;
		case 115://s
			if (map[p.x + 1][p.y] == 1 || map[p.x + 1][p.y] == 3) {
				map[p.x + 1][p.y] += 1;
				map[p.x][p.y] -= 1;
				p.x += 1;
			}
			else if (map[p.x + 1][p.y] == 5 && (map[p.x + 2][p.y] == 1 || map[p.x + 2][p.y] == 3))
			{
				if (map[p.x + 2][p.y] == 3) {
					map[p.x + 2][p.y] = 6;
					now_ok++;
				}
				else map[p.x + 2][p.y] = 5;
				map[p.x][p.y] = 1;
				map[p.x + 1][p.y] = 2;
				p.x += 1;
			}
			break;
		}
		system("cls");
		PrintMap(map);

	} while (now_ok != box);
}