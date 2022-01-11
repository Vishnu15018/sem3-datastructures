#include<stdio.h>
int main(){
    int a[]={1,-2,3,-1,6,-3,4},x;
    int ovallsum,maxsum,max;
    ovallsum=a[0];
    x= sizeof(a)/sizeof(int);
    
    for (int  i = 0; i < x; i++)
    {    maxsum=0;
        /* code */
        for (int j = i; j <x; j++)
        {  
            /* code */
            maxsum=maxsum + a[j];
            if(maxsum >= ovallsum){
                ovallsum=maxsum;
            }
        }
        
    }
    printf("The maximum value of subsequence is =%d",ovallsum);

    return 0;
}