#include <stdio.h>
#include <string.h>
#include <iostream>

char *returnStr()
{
    char *p="abcd";
    return p;
}

char *returnStr2()
{
    char p[]="abcd";
    return p;
}
int main()
{
    char *str = "Danny";    //string ��������const char*   �洢�ھ�̬������
    const char *addition = "Andy";
    printf("str=%s\n",str);
    printf("str=%d\n",str);
    printf("&Danny=%d\n",&("Danny"));
    printf("addition=%s\n",addition);

    /*
    strcat(str,addition);   //error "Danny"�������ڴ����ݶ��У����ɸ���
    */
    
    char src[20] = "Danny"; //�洢��ջ��
    strcat(src,addition);
    printf("str=%s\n",src);


    char str1[] = "abcd";
    char str2[] = "abcd";

    const char *str3 = "abcd";
    const char *str4 = "abcd";
    std::cout<<(str1 == str2)<<std::endl;
    std::cout<<(str3 == str4)<<std::endl;

    char *str5 = returnStr();
    printf("str5=%s\n",str5);

    char *str6= returnStr2();
    printf("str6=%s\n",str6);
    return 0;
}