#include<stdio.h>
int findRepeatNumber_1(int* nums, int numsSize){
    int i,temp=0,result=0;
    if(nums==NULL||numsSize<=0){
        return 0;
    }
    for(i=0;i<numsSize;i++){
        if (nums[i]<0||nums[i]>numsSize-1){
            return 0;
        }
        
        if(nums[i]!=i){
        //第一个在散列位的数没有意义，不能证明重复
        /*    if(nums[i]==nums[i+1]){
                result=nums[i];
            }
        }
        else{*/
            //如果数字不在散列位
            temp=nums[i];
            if(nums[temp]==nums[i]){
            //且散列位已有相同数字,找到重复数字
                result=nums[i];
            }
            else{
            //散列位没有相同数字，将数字存入散列位，继续循环
            nums[i]=nums[temp];
            nums[temp]=temp;
            }
        }
    }
    return result;
}

int findRepeatNumber_2(int* nums, int numsSize){
    int i,result=0;
    //int *nums_t;
    int nums_t[numsSize];
    for(i=0;i<numsSize;i++){
        //数组初始化为-1，表明未存入相应数字
        nums_t[i] = -1;
    }
    for(i=0;i<numsSize;i++){
        //遍历存入哈希散列
        if(nums_t[nums[i]] == -1){
            //为-1说明此处数字只出现一次
            nums_t[nums[i]] = nums[i];
        }else{
            //不为-1说明此处数字已存入，发现重复数字
            result = nums[i];
        }
    }
    return result;
}

/*笔记
一、
line3:int *nums_t报错：
Line 7: Char 19: runtime error: store to null pointer of type 'int' (solution.c)

在调用函数时，如果返回值如果是一个常量则没问题。如果返回值若为指针则可能会出现该错误，假如返回的指针地址指向函数内的局部变量，在函数退出时，该变量的存储空间会被销毁，此时去访问该地址就会出现这个错误。

解决办法有以下三种:

    1.返回的指针使用malloc分配空间
    2.将该变量使用static修饰 static修饰的内部变量作用域不变 但是声明周期延长到程序结束 即该变量在函数退出后仍然存在
    3.使用全局变量

二、
方法1：空间复杂度：
方法2空间复杂度多了一个转换数组，时间复杂度多了一次转换数组的初始化；未判断输入数据的合法性；
*/

int main() {
    int i,numsSize,nums[10000];
    scanf("%d",&numsSize);
    for(i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    printf("%d",findRepeatNumber(nums,numsSize));
    return 0;
}

