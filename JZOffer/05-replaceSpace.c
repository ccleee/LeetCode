#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//solution1
char* replaceSpace1(char* s){
    int length=strlen(s);
    int newlength=0;
    int blanklength=0;
    if(length<0||s==NULL){
        return false;
    }
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            blanklength++;
        }
    }
    newlength=length+2*blanklength+1;
    s=(char*)realloc(s,sizeof(char)*newlength);
    //if(s=NULL) return 0;
    s[newlength-1]='\0';
    length-=1;
    newlength-=2;
    while(length>=0&&newlength>=length){
        if(s[length]!=' '){
            s[newlength--]=s[length];
        }
        else{
            s[newlength--]='0';
            s[newlength--]='2';
            s[newlength--]='%';
        }
        length--;
    }
    return s;
}

//solution2
char* replaceSpace2(char* s){
    int len = 0, whitespace = 0;
    for(int i = 0; s[i] != '\0'; ++i) {
        ++len;
        if(s[i] == ' ')
            ++whitespace;
    }
    if(whitespace == 0)
        return s;

    s = (char* )realloc(s, sizeof(char) * (len  + 2 * whitespace + 1));
    //s[len + 2 * whitespace] = '\0';

    int k = len + 2 * whitespace - 1;
    for(int i = len - 1; i >= 0; --i) {
        if(s[i] != ' '){
            s[k--] = s[i];
        }else {
            s[k--] = '0';
            s[k--] = '2';
            s[k--] = '%';
        }
    }
    return s;
}

//my solution
char* replaceSpace3(char* s){
    int length = strlen(s);
    char *r = NULL; 
    //采取可能替换的极端情况最大值，若需优化可先计算空格数
    r = (char*)malloc(sizeof(char)*(3*length)+1);
    if(s==NULL){
        return false;
    }
    int i=0,j=0;
    while(s[i]!='\0'){
        if(s[i]!=' '){
            r[j] = s[i];
            j++;
        }else{
            r[j] = '%';
            r[j+1] = '2';
            r[j+2] = '0';
            j += 3;
        }
        i++;
    }
    r[j] = '\0';//字符串不加结束标志会导致非法访问警告
    return r;
}


/*笔记
时间复杂度：O(n)
空间复杂度：O(n)
优化：可直接从后向前对原字符串进行地址扩充与字符移动（官方解法）
ps：如果要求只能对原字符串进行改动，则采用官方解法，否则常规移动时间复杂度达到O(n²)
一、C/C++ 中 NULL、'\0'、'0' 、0、及空格的区别
1、NULL即空指针。在C中，NULL是指向0的指针，由 #define NULL ((void *)0)定义；在C++中，NULL就是0，由 #define NULL 0 定义。可参见 vs2013 的库文件 string.h。
2、'\0' 是空字符常量，表示字符串的结束，ASCII码值为0。
3、'0'是字符0，ASCII码值为48。
4、0是数字0。
5、空格是可显示字符空格，ASCII 码值为32。

备注：
　　给指针置位为空指针时，应该使用 NULL；
　　给字符串添加结束标志时，应该使用 '\0' 。

二、printf输出%20之类的数字写法：printf("%%20");
三、题目要求实现一个函数，而不是直接标准输出，注意审题。
四、注意最终大小不确定的字符串应手动添加'\0',不然会非法访问越界。
*/

int main(){
    char s[]={"l o v e"};
    replaceSpace(s);
    printf("%s",s);
    //printf("%s",s2);
    //int length=strlen(s);
    //printf("%d",length);
    return 0;
}