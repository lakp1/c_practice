#include <stdio.h>
int main(){
    int n;
    printf("要几个学生？");
    scanf("%d",&n);
    typedef struct student
    {
        char name[100];
        double score;
    }S;
    S stuArr[n];
    for(int i=0;i<n;i++){
    printf("请输入第%d个学生的名字和分数:",i+1);
    scanf("%s %lf",stuArr[i].name,&stuArr[i].score);
    printf("名字：%s 分数：%lf\n",stuArr[i].name,stuArr[i].score);
    }
    return 0;
}