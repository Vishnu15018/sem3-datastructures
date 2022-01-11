#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{     
    int m1,m2,this_sum,x,c=0;
    printf("ENTER THE UPPER AND LOWER LIMITS :\n");
    scanf("%d %d",&m1,&m2);
    int n=0;
    printf("Enter the no of elements of an array:\n");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
   // x=sizeof(a)/sizeof(int);
   printf("Enter the elements of an array:\n");
    for(int  k = 0; k < n; k++)
    {   int b=0;
        scanf("%d",&b);
        if(b>0){
            a[k]=b;
        }
        else{
            k--;
        }

    }
    
    for (int i = 0; i < n; i++)
    {
         this_sum=0;   
         for (int j= i; j < n; j++)
         {
             this_sum+=a[j];
             if(this_sum>=m1 && this_sum<=m2){
                 if(i!=j){
                     c=c+1;
                     printf("\n The Indices l=%d ,r=%d",i,j);
                 
                 }
             }

         }
         
    }
    printf("\n The no of indices pairs [l,r] is = %d",c);

    
}