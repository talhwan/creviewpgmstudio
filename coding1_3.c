#include <stdio.h>

typedef struct _student {
    char name[20];
    int score[3];
} Student;

//합계를 리턴하고 학생 1명 포인터 변수
int inputScore(Student *s){
    char title[][20] = {"국어", "영어", "수학"};
    int sum = 0, i = 0;

    printf("학생의 이름 입력 : ");
    scanf("%s", s->name);

    for(i=0;i<3;i++){
        printf("%s 점수 입력 : ", title[i]);
        scanf("%d", &s->score[i]);
        sum += s->score[i];
    }
    return sum;
}

int main(void)
{
    Student s1;
    int sum;
    double avg;

    sum = inputScore(&s1);
    avg = sum / 3.0; 

    printf("%s 학생의 총점 :  %d , 평균은 %.2f", s1.name, sum, avg);
    return 0;
}