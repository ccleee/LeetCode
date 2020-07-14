#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//列尾比较+每列比较
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i,row=0,col=*matrixColSize-1,ret=false;
    //异常处理
    if(matrix==NULL||matrixSize<=0){
        return false;
    }
    while((col>=0)&&(row<matrixSize)){
        if(target>matrix[row][col]){
            row++;
        }
        else if(target<matrix[row][col]){
            col--;
        }
        else{
            return true;
        }
    }
    return false;
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize - 1,col = 0;
    //异常处理
    if(matrix == NULL || matrixSize == 0){
        return false;
    }
    //只要查找范围在矩阵内，就不断查找
    while(row >= 0 && col <= *matrixColSize - 1){
        //列头比较+每列比较
        if(target < matrix[row][col]){
            row--;           
        }
        else if(target > matrix[row][col]){
            col++;
        } 
        else{
            return true;
        }
    }
    return false;
}

/*笔记
1.如果想节约时间复杂度，一定不能一个一个比，从右上角或左下角开始判断，
这样无论目标数字大于或小于当前位置的矩阵元素，行、列的移动方向只有一个；
因为右上角、左下角的数字唯一可以移动的两个方向，要么都比该数字大，要么都比该数字小，想要准确判断会产生多余的分支；
但左上角和右下角可以移动的方向都只有一个结果，无法做出准确判断。
2.每列或每行是一定要逐个比较的，因为只有同列或同行的大小关系是确定的，所以采用右上角或左下角作为比较点，可以根据目标数字与当前数字的大小关系率先判断出行或列，而不是两个都不确定。
*/