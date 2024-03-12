#include <stdio.h>

int main(void){
    int i=0, j=0; // 반복문을 위한 변수
    int person[4][3]; 
    int sum[3] = {0,0,0}; //총합,여자,남자
    float ratio[3] = {0.0,0.0,0.0};; //총합,여자,남자

    for(i=0;i<4;i++){
        if(i==0){
            printf("Check room (Men)\n");
        } else if(i==2){
            printf("Check room (Women)\n");
        }
        for(j=0;j<3;j++){
            printf("Room #%d0%d >", (i+1), (j+1));
            scanf("%d", &person[i][j]);

            if(person[i][j] > 4){
               person[i][j] = 4; 
            }

            if(i<2){
                //남자
                sum[2] += person[i][j];
            } else {
                //여자
                sum[1] += person[i][j];
            }
            sum[0] += person[i][j];
            /*
            */
        }
    }
    ratio[2] = (100 * sum[2]) / 24.0;
    ratio[1] = (100 * sum[1]) / 24.0;
    ratio[0] = (100 * sum[0]) / 48.0;

    printf("Men : %d/24 (%.1f %%)\n", sum[2], ratio[2]);
    printf("Women : %d/24 (%.1f %%)\n", sum[1], ratio[1]);
    printf("Total : %d/48 (%.1f %%)\n", sum[0], ratio[0]);
    /*
    */
}