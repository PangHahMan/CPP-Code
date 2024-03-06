#include"game.h"
#include<stdlib.h>
#include<time.h>
//test.c ������������Ϸ
//game.h  ��������Ϸ�ĺ�������
//game.c  ��Ϸ������ʵ��
void menu()
{
	printf("                   \n");
	printf("      1.play       \n");
	printf("      0.exit       \n");
	printf("                   \n");
}

void game()
{
	char ret;
	//���ݵĴ洢��Ҫһ��3*3�Ķ�ά����
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ӡ����
	display_board(board, ROW, COL);
	
	while (1)
	{
		//�������
		player_move(board, ROW, COL);
		//�ж���Ϸ״̬
		ret = is_win(board, ROW, COL);
		if (ret != 'C')  //���return C ����Ϸ���� ���������������ж�
			break;
		//��������
		computer_move(board, ROW, COL);
		//�ж���Ϸ״̬
		ret = is_win(board, ROW, COL);
		if (ret != 'C')  //���return C ����Ϸ���� ���������������ж�
			break;
	}
	if (ret == '*')
		printf("���Ӯ\n");
	
	else if (ret == '#')
		printf("����Ӯ\n");
	
	else if (ret == 'Q')
		printf("ƽ��\n");
}
//4��״̬�ж�
//���Ӯ - *
//����Ӯ - #
//ƽ���� - 'Q'
//��Ϸ���� - 'C'
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
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
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}