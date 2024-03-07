#include <stdio.h>

int main(void)
{
    char name[20];
    char title[][20] = {"국어", "영어", "수학"};
    int score[3], sum = 0, i = 0;
    double avg;

    printf("학생의 이름 입력 : ");
    scanf("%s", name);

    for(i=0;i<3;i++){
        printf("%s 점수 입력 : ", title[i]);
        scanf("%d", &score[i]);
        sum += score[i];
    }
    avg = sum / 3.0;

    printf("%s 학생의 총점 :  %d , 평균은 %.2f", name, sum, avg);
    return 0;
}