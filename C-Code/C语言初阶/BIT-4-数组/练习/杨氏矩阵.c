#include <stdio.h>
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);   ���ܼ򵥵ı�������

void find_num_in_young(int arr[3][3], int k, int *px, int *py)
{
    int i = 0;
    int j = *py - 1; // c=3  j=2
    int flag = 0;
    while (i <= *px - 1 && j >= 0)
    {
        //��һ�������е����ұߺ�k�ж�
        if (arr[i][j] < k) //���Ͻ��±�
        {
            i++;
        }
        else if (arr[i][j] > k)
        {
            j--;
        }
        else
        {
            flag = 1;
            *px = i;
            *py = j;
            break;
        }
    }
    if (flag == 0)
    {
        *px = -1;
        *py = -1;
    }
}

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 0;
    scanf("%d", &k); //����Ҫ���ҵ�����
    //��������
    int x = 3;
    int y = 3;
    find_num_in_young(arr, k, &x, &y);
    if (x == -1 && y == -1)
        printf("�Ҳ���\n");
    else
        printf("�ҵ��ˣ��±��ǣ�%d %d", x, y);
    return 0;
}

/*
1 2 3
4 5 6
7 8 9
*/
//������7