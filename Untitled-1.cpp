#include <iostream>
#include<climits>
#include<stdlib.h>
#include<time.h>
using namespace std;
int max3(int a,int b, int c){
	int max;
	if (a>b)
		return max=a;
	else if(b>c)
		return max=b;
	else
		return max=c;
}
 
int mss3 (const int* a, int left, int right) 
{ 
	if (left == right) 
	{	if(a[left] > 0)
			return a[left];
		else
			return 0;
	}
	int center = (left + right) / 2;
	int maxLeftSum = mss3(a, left, center);
	int maxRightSum = mss3(a, center + 1, right);
	int rightcs = 0, maxrcs = 0,leftcs = 0,maxlcs = 0;
	for (int i = center; i >= left; i--) 
	{
		leftcs += a[i];
		if (leftcs > maxlcs)
		{
			maxlcs = leftcs;
		}
	}
	for (int i = center + 1; i <= right; i++) 
	{ 
		rightcs += a[i]; 
		if (rightcs > maxrcs)
		{
			maxrcs = rightcs;
		}
	}
	return max3(maxLeftSum,maxRightSum,maxlcs+maxrcs);
}


int maxss3(const int*a,unsigned int n){
	return mss3(a,0,n-1);

}
int main()
{
    int a[1000];
    srand(time(0));
    int upper=999,lower=-999;
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
        a[i]=(rand() % (upper - lower +1)) + lower;
    int max_sum = maxss3(a,999);
    cout << "Maximum sum is " << max_sum<<endl;
	clock_t t;
    t=clock();
    for (int i = 0; i < 99; i++){ 
        maxss3(a, n); 
    } 
    t=clock()-t;
    double tt=((double)t)/CLOCKS_PER_SEC;

    cout<<"Output time taken:";
    printf("%f",tt);
    return 0;
}