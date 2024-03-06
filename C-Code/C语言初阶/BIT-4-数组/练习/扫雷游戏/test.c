#include"game.h"
/*
test.c  ɨ����Ϸ�Ĳ����߼�
game.h  ��Ϸ����������
game.c  ��Ϸ������ʵ��
*/


/*  ��Ϸ�߼�
 9*9������  ��Ҫ 11*11������  ��ֹ����Խ��
2�����̣�һ���Ų��úõ��� ��һ�����Ų�ĵط�
1.���������飬һ������mine������Ų��úõ��׵���Ϣ��
����һ������show����Ų�������׵���Ϣ
2.mine�����ʼ��Ϊ'0'�������׵�ʱ�򣬸ĳ�'1'
show�����ʼ��Ϊ��*�����Ų��׺󣬾���λ�ø�Ϊ�����ַ����确3��
*/

void menu()
{
	printf("            1.play           \n");
	printf("            0.exit           \n");
}

void game()
{
	//���������������Ϣ
	char mine[ROWS][COLS] = { 0 };  //ROWS ��ֹ����Խ��
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	//mine��ʼ��Ϊȫ��0��
	//show��ʼ��Ϊȫ��*��
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//��ӡ����
	//display_board(mine, ROW, COL);  //��ӡֻ��Ҫ��ӡROW COL  ����ҪROWS 
	//display_board(show, ROW, COL); 
	//������
	set_mine(mine, ROW, COL);
	//display_board(mine, ROW, COL);   //�����׵�λ��
	display_board(show, ROW, COL);
	//����
    find_mine(mine, show, ROW, COL);   //mine����ŵ�show������
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}