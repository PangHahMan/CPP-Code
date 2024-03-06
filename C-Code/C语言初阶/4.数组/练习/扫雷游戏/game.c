#include"game.h"
//��ʼ������
void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//��ӡ����
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�к�
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//������
void set_mine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EAZY_COUNT;
	while (count)
	{
		int x = rand() % row + 1; //1-9
		int y = rand() % col + 1; //1-9
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


//ͳ����Χ�׺���  �����
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0');
}

//����
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EAZY_COUNT)   //ֻҪwin<  û��������
	{
		printf("������Ҫ�Ų��׵����꣺\n");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y < +col)  //�Ϸ���Χ
		{
			//���걻�Ų��
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')   //������
				{
					printf("���ź�,�㱻ը����\n");
					display_board(show, ROW, COL);
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);  //ͳ����
					show[x][y] = count + '0';  //�ַ�3  ����+�ַ�0  ���Եõ��ַ�����
					display_board(show, ROW, COL);  //����һ�� ����ӡһ��show
					win++;
				}
			}
			else
			{
				printf("�����Ѿ����Ų��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - EAZY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		display_board(show, ROW, COL);
	}
}

/*
9*9
*/