#include<stdio.h>
#define ROW 5
#define COL 5
//��ʼ�����̺�������
void Initboard(char board[ROW][COL], int row, int col);

//��ӡ���̺�������
void display_board(char board[ROW][COL], int row, int col);

//������庯������
void player_move(char board[ROW][COL], int row, int col);

//�������庯������
void computer_move(char board[ROW][COL], int row, int col);

//�ж���Ϸ״̬
char is_win(char board[ROW][COL], int row, int col);