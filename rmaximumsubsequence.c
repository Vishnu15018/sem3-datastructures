// Big O(n^3) code fo rmaximum subsequence

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    double time_spent = 0.0;
    clock_t begin = clock();
    int a[1000],upper=999,lower=-999,x,best_i,best_j;
    x= sizeof(a)/sizeof(int);
    int ovallsum,maxsum,max;
    srand(time(0));
    for(int k=0;k<x;k++){
        a[k]=(rand() % (upper - lower +1)) + lower;
    }
    
     ovallsum=a[0];
     best_i=0;
     best_j=0;

    for (int  i = 0; i < x; i++)
    {    
        /* code */
        for (int j = i; j <x; j++)
        {   maxsum=0;
            for (int k = i;k<=j;k++){
                maxsum=maxsum + a[k];
            }
            
            if(maxsum >= ovallsum){
                ovallsum=maxsum;
                best_i=i;
                best_j=j;
            }
        }
        
    }
    printf("The maximum value of subsequence is =%d",ovallsum);
     clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", time_spent);
    return 0;

}