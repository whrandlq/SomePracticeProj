/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。

 */

#include <iostream>
#include <stdio.h>

using namespace std;

void replaceSpace(char *str, int length) {
    if(str == NULL)
        return ;

    int CountOfBlanks = 0;
    int Originallength = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        Originallength++;
        if(str[i] == ' ')
            ++CountOfBlanks;
    }

    int len = Originallength + 2 * CountOfBlanks;  //因为 %20 比 空格 多两个字符
    if(len + 1 > length)
        return ;

    char *pStr1 = str + Originallength; //复制结束符‘\0’
    char *pStr2 = str + len;
    while(pStr1 < pStr2) {
        if(*pStr1 == ' ') {
            *pStr2-- = '0';
            *pStr2-- = '2';
            *pStr2-- = '%';
        } else {
            *pStr2-- = *pStr1;
        }
        --pStr1;
    }
}

int main(int argc, char const *argv[]) {
    //Test
    char p[] = "AA BB CC ";
    printf("替换前：%s\n", p);
    replaceSpace(p, 50);
    printf("替换后：%s\n", p);

    return 0;
}