#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   
    int n,count,count1;
    printf("Enter the No of days:\n");
    scanf("%d",&n);
    printf("Enter the timings in the format HH.MM \n");
    // This inp array is to take the timings of the person 
    float inp[n]; 
    for(int i=0;i<n;i++){
        scanf("%f",inp+i);
    }
    count1=sizeof(inp)/sizeof(float);
    /* b array consists of boarding times of shuttle service*/
    /* d consists of departure times of shuttle services*/
    float b[5]={9.30,9.40,10.00,10.15,10.30},d[5]={9.40,9.50,10.00,10.25,10.40};
    count=sizeof(b)/sizeof(float);
    for (int  i = 0; i < count1; i++)
    {    int c=0;
         for (int j = 0; j < count; j++)
         {  
             if(inp[i]<=b[j]){
                 printf("\nFor %d day the best bus No is = %d ",i+1,j+1);
                 c=c+1;
                 break;
             }
         }
         if(c==0){
            printf("\nFor %d day the best bus No is = %d ",i+1,-1);
         }
         
    }
    


}