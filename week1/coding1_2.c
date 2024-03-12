#include <stdio.h>

int main(void)
{
    char name[20]; // 이름(입력)
    char title[][20] = {"Kor", "Eng", "Math"}; // 과목 목록
    int score[3], sum = 0, i = 0; // 각 점수(입력), 총점
    double avg; // 평균

    printf("Name : ");
    scanf("%s", name);
    
    for(i=0;i<3;i++){
        printf("%s score? : ", title[i]);
        scanf("%d", &score[i]);
        sum += score[i];
    }
    avg = sum / 3.0;

    printf("%s total score :  %d , avg :  %.2f", name, sum, avg);
    return 0;
}