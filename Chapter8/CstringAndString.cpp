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
    char *str = "Danny";    //string 的类型是const char*   存储在静态数据区
    const char *addition = "Andy";
    printf("str=%s\n",str);
    printf("str=%d\n",str);
    printf("&Danny=%d\n",&("Danny"));
    printf("addition=%s\n",addition);

    /*
    strcat(str,addition);   //error "Danny"保存在内存数据段中，不可更改
    */
    
    char src[20] = "Danny"; //存储在栈区
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