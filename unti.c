#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>
int main(){
    double time_spent = 0.0;
    clock_t begin = clock();

    for (int i = 0; i <= 1000000; i++);
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;      /*to evaluate executioin time*/
 
    printf("\nThe elapsed time is %f seconds", time_spent);
}