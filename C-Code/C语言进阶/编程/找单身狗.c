//��� ��ͬΪ0,����Ϊ1
// a^a=0  0^a=a    1^1^3 ==3   1^3^1==3

//������������
// 1.����5��6����һλΪ1 - n
// 2.�Ե�nλΪ��׼����nλΪ1�ķ�һ�飬��һλΪ0��һ��

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};
    int sz = sizeof(arr) / sizeof(arr[0]);
    //�����������
    int i = 0;
    int ret = 0;
    for (i = 0; i < sz; i++)
    {
        ret ^= arr[i];
    }
    // ret����5^6�Ľ������������һ����1
    //����ret�ĵڼ�λΪ1
    int pos = 0;
    for (i = 0; i < 32; i++)
    {
        if ((ret >> i) & 1 == 1)
        {
            pos = i;
            break;
        }
    }
    // ret�ĵ�posλΪ1
    //��arr�����е�ÿ��Ԫ�صĵ�posλΪ1�����������һ��
    int num1 = 0;
    int num2 = 0;
    for (i = 0; i < sz; i++)
    {
        if ((arr[i] >> pos) & 1 == 1)
        {
            num1 ^= arr[i];
        }
        else
        {
            num2 ^= arr[i];
        }
    }
    printf("%d %d", num1, num2);
    return 0;
}