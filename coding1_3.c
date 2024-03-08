#include <stdio.h>

// 학생 정보를 담아줄 구조체 선언
typedef struct _student {
    char name[20]; //이름
    int score[3]; //성적 3개
} Student;

// 총점을 계산해 주는 함수 선언
int inputScore(Student *s){
    char title[][20] = {"Kor", "Eng", "Math"};
    int sum = 0, i = 0;

    printf("Name : ");
    scanf("%s", s->name);

    for(i=0;i<3;i++){
        printf("%s score : ", title[i]);
        scanf("%d", &s->score[i]);
        sum = sum + s->score[i];
        //sum += s->score[i];
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

    printf("%s total score :  %d , avg : %.2f", s1.name, sum, avg);
    return 0;
}