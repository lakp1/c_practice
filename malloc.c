#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("要几个数？");
    if (scanf("%d",&n)!=1 )return 1;
double *arr=(double*)malloc(n*sizeof(double));
if (arr==NULL){
    printf("内存不足\n");
    return 1;
}
double sum=0;
for(int i=0;i<n;i++){
    printf("arr[%d]: %lf ",i,arr[i]);
    scanf("%lf",&arr[i]);
    sum=sum+arr[i];
}
double avg=sum/n;
printf("平均值为：%lf\n",avg);
    free(arr);
    arr=NULL;
    return 0;
}
