#include<stdio.h>  // 引入标准输入输出库，提供 printf 等函数

// 程序入口函数
int main(){
    
    int age=19;         // 定义整型变量 age，存储年龄，赋值为 19
    
    float score=92.5;   // 定义单精度浮点型变量 score，存储成绩，赋值为 92.5
   
    char level='A';     // 定义字符型变量 level，存储等级，赋值为 'A'
    
    // 格式化输出：%d 输出整数，%.1f 输出保留一位小数的浮点数，%c 输出字符
    printf("年龄 %d 分数 %.1f 等级 %c\n",age,score,level);
    
    return 0;           // 返回 0，表示程序正常结束
}