// Big O(n) time comlexity
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
int main(){

    int m1,m2,a[15]={1,2,3,4,5,6,7,8,9,10,11,12,13},sum,x,l=0,r=0,c=0;
    printf("ENTER THE UPPER AND LOWER LIMITS :\n");
    scanf("%d %d",&m1,&m2);

sum=0;
x= sizeof(a)/sizeof(int);

for(int j = 0; j < x; j++)
{
     sum+=a[j];
     if(sum>=m1 && sum<=m2){
           l=0;
           r=j;
           printf("\n The [l,r] pairs are l=%d , r=%d",l,r);
           c=c+1;
           }
    else if(sum>m2){
        l=l+1;
        sum=0;
    }
    

}

printf("\nThe no of indices pairs [l,r] is = %d",c);


}