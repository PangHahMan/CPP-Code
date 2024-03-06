#include"game.h"
//��ʼ�����̺���
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//���̺���ʵ��(��̬ʵ��)
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//---|---|---
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//�������
void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������壺>\n");
	while (1)
	{
		printf("������Ҫ��������꣺>");
		scanf_s(" %d %d", &x, &y);
		//����ĺϷ���
		//�����Ƿ�ռ��
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] != ' ')  //��������1��ʼ�������0��ʼ
			{
				printf("���걻ռ�ã�����������\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				display_board(board, ROW, COL);   //ÿ���������̣���ӡһ������
				break;
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}
}

//��������(�������)
void computer_move(char board[ROW][COL], int row, int col)
{
	while(1)
	{ 
		int x = rand() % row;   //0-2
		int y = rand() % col;   //0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			printf("�������壺>\n");
			display_board(board, ROW, COL);   //ÿ���������̣���ӡһ������
			break;
		}
	}
}

//�ж�ƽ�ֺ���-����������˷���1�����򷵻�0
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//�ж���Ϸ״̬
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	//�жϺ���
	for (i = 0; i < row; i++)
	{
		count = 0;    //ÿѭ��һ�� ��ʼ��countΪ0
		for (j = 0; j < col; j++)
		{
			if (board[i][0] == board[i][j] && board[i][0] != ' ')
				count++;
			if (count >= row)
				return board[i][0];
		}
	}
	//�ж�����
	for (j = 0; j < col; j++)
	{
		count = 0;    //ÿѭ��һ�� ��ʼ��countΪ0
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == board[0][j] && board[0][j] != ' ')
			{
				count++;
				if (count >= row)
					return board[0][j];
			}
		}
	}
	

	//�ж϶Խ���1
	count = 0;    //�Խ��ߵ��ж��Ǵ�ȫ�ֿ�ʼ ����Ҫ��������
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == j)
			{
				if (board[1][1] == board[i][j] && board[1][1] != ' ')
				{
					count++;
					if (count >= row)
						return board[1][1];
				}
			}
		}
	}
	
	//�ж϶Խ���2
	count = 0;   //�Խ��ߵ��ж��Ǵ�ȫ�ֿ�ʼ ����Ҫ��������
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((i + j + 1) == row)
			{
				if (board[1][1] == board[i][j] && board[1][1] != ' ')
				{
					count++;
					if (count >= row)
						return board[1][1];
				}
			}
		}
	}
	
	//�ж�ƽ��
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}

	return 'C';
}