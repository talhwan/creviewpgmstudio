#include <stdio.h>

int main(void){
    int i = 0, j = 0;
    printf("*\n");
    printf("**\n");
    printf("***\n");
    printf("****\n");
    printf("*****\n");

    for(i=0;i<5;i++){
        for(j=0;j<=i;j++){
            //printf("%d", j);
            printf("*");
            if(j==i){
                printf("\n");
            }
        }
    }
}