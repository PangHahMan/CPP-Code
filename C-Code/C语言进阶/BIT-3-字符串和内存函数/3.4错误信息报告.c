#include <stdio.h>
#include <string.h>
#include <errno.h>
// strerror
// char * strerror ( int errnum );
//�Ѵ�����ת���ɴ�����Ϣ
/*
int main()
{
    //strerror�Ĵ�����
    //c�����п⺯�������ʱ��Ĵ�����
    printf("%s\n",strerror(0));  //No error
    printf("%s\n",strerror(1));  //Operation not permitted
    printf("%s\n",strerror(2));  //No such file or directory
    printf("%s\n",strerror(3));  //No such process
    printf("%s\n",strerror(4));  //Interrupted function call
    return 0;
}
*/

/*
int main()
{
    //�������¼��������ı�����
    //errno -  #include<errno.h>  C�����ṩ��ȫ�ֵĴ������
    FILE* pf = fopen("test.txt","r");
    if(pf==NULL)
    {
        perror("fopen");   //perror = printf+strerror    ��ӡfopen: No such file or directory
        //��ӡ����Ȼ��error�����д������Ӧ�Ĵ�����Ϣ
        printf("%s\n",strerror(errno)); //������2������
        return 1;
    }
    //���ļ�
    fclose(pf);
    pf=NULL;
    return 0;
}
*/
