#include <stdio.h>

int main(void)
{
    char name[20]; //이름을 입력받을 변수
    int kor, eng, math; // 각 과목 점수 입력받을 변수
    int sum; //총점 변수
    double avg; //평균 변수
    printf("이름은? ");
    scanf("%s", name);
    printf("국어 성적? : ");
    scanf("%d", &kor);
    printf("영어 성적? : ");
    scanf("%d", &eng);
    printf("수학 성적?");
    scanf("%d", &math);

    sum = kor + eng + math;
    avg = sum / 3.0;

    printf("%s 총점 :  %d , 평균 %.2f", name, sum, avg);
    return 0;
}