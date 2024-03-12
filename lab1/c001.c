#include <stdio.h>

int main(void){
    int t=0, i=0, j=0; // 반복문을 위한 변수
    int size; // 출력할 줄에 대한 부분
    int blank1, blank2; //*을 찍어야 하는 포인트를 기록하는데 사용

    printf("얼마나??");
    scanf("%d", &size);
    for(t=0;t<4;t++){
        blank1 = 0;
        blank2 = size * 2 - 1;
        for(i=0;i<size;i++){
            for(j=0;j<size*2;j++){
                if(t==0){
                    if(j==blank1 || j==blank2){
                    printf("*");
                    } else {
                        printf(" ");
                    }
                } else if(t==1){
                    printf("*");
                } else if(t==4){
                    printf("*");
                } else {
                    if(j>=blank1 && j<=blank2){
                    printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("\n");
            blank1++;
            blank2--;
            if(t==3){
                break;
            }
        }  
    } 
}