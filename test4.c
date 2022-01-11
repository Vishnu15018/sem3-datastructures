// Big O(nlogn) time comlexity
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int m_sub_sum (int* a,int left,int right) {
   int m_l_s , m_r_s,m_l_b_s,m_r_b_s;
   int l_b_s,r_b_s,center,i;

   if(left==right){         
       return a[left];

   }


    center=(left+right)/2;
    m_l_s = m_sub_sum(a,left,center);
    m_r_s = m_sub_sum(a,center+1,right);
    m_l_b_s=0;
    l_b_s=0;
    for( i=center;i>=left;i--){
        l_b_s=l_b_s+a[i];
        if(l_b_s>m_l_b_s){
            m_l_b_s=l_b_s;

        }
    }
        m_r_b_s=0;
        r_b_s=0;
        for( i=center+1;i<=right;i++){
            r_b_s=r_b_s+a[i];
            if(r_b_s>m_r_b_s)
                m_r_b_s = r_b_s;
        }
    int max = m_l_b_s;
	if (m_r_b_s > max ) 
	{
		max = m_r_b_s;
	}
	if (m_l_b_s + m_r_b_s > max) 
	{	
		max =m_l_b_s + m_r_b_s ;
	}
	return max;

}
//main function
int main(){
    double time_spent = 0.0;
    clock_t begin = clock();
        int a[1000],lower=-999,upper=999,x;
x= sizeof(a)/sizeof(int);
srand(time(0));                                                 
    for(int k=0;k<x;k++){
        a[k]=(rand() % (upper - lower +1)) + lower;
    } 

printf("maximum subsequence sum %d",m_sub_sum(a,0, x-1));
     clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", time_spent);

}



