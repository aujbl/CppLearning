#include<stdio.h>
int main(){

    int c;
    int i=0;
    while((c=getchar())!=EOF){
        if(c=='\n'){
            i++;
        }
        printf("%d \n",i);
    }
    printf("pressed eof. \n");
}