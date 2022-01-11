#include<stdio.h>
#include<stdlib.h>
int main(){
    int x;
    int* p=malloc(6*sizeof(int));
    printf("ENTER TH ELEMENTS OF AN DYNAMIC ARRAY");
    for(int i=0; i<6;i++){
        scanf("%d",(p+i));
    }
    p=realloc(p,2*sizeof(int));
    p[6]=1000;
    p[7]=399;
    for(int i=0; i<8;i++){
        printf("array elemnts %d\n",*(p+i));
    }

    free(p);

    printf("%d\n",p);
    


}