#include <stdio.h>

int main(void)
{
    char name[20];
    int kor, eng, math;
    int sum;
    double avg;
    printf("학생의 이름 입력 : ");
    scanf("%s", name);
    printf("국어 점수 입력 : ");
    scanf("%d", &kor);
    printf("영어 점수 입력 : ");
    scanf("%d", &eng);
    printf("수학 점수 입력 : ");
    scanf("%d", &math);

    sum = kor + eng + math;
    avg = sum / 3.0;

    printf("%s 학생의 총점 :  %d , 평균은 %.2f", name, sum, avg);
    return 0;
}