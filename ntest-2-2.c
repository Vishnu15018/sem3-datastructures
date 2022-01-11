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
    int bus[n];
    for(int i=0;i<n;i++){
        scanf("%f",inp+i);
    }
    count1=sizeof(inp)/sizeof(float);
        /* b array consists of boarding times of shuttle service*/
    /* d consists of departure times of shuttle services*/
    // arr array represents the journey time 
    float b[5]={9.30,9.40,10.00,10.15,10.30},d[5]={9.40,9.50,10.00,10.25,10.40};
    float arr[5]={2.00,1.45,1.35,2.05,2.00};
    count=sizeof(b)/sizeof(float);
    for (int  i = 0; i < count1; i++)
    {    int c=0;
         for (int j = 0; j < count; j++)
         {  
             if(inp[i]<=b[j]){
                 
                 c=c+1;
                 bus[i]=j+1;
                 break;
             }
         }
         if(c==0){
            
            bus[i]= -1;
         }
         
    }
    
    for (int i = 0; i < count1; i++)
    {   int y=0,z=0;
        int x=bus[i];
        for(int j=0;j<1;j++){
            if(bus[i]!= -1){
                y=d[x] - d[x-1];
                z=arr[x] - arr[x-1];
                if(bus[i]==count){
                    printf("For %d day the best bus No is = %d \n",i+1,bus[i]);
                    break;
                }
                
                else if(y>=z){
                        printf("For %d day the best bus No is = %d \n",i+1,bus[i]);
                        break;
                    }
                else{
                    printf("For %d day the best bus No is = %d \n",i+1,bus[i]+1);
                    break;
                }
                
            }
            else{
                printf("For %d day the best bus No is = %d \n",i+1,-1);
                break;
            }
        
        }
    }
    

}