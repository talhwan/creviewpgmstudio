#include <stdio.h>

typedef struct _student {
    char name[20];
    int score[3];
} Student;

//�հ踦 �����ϰ� �л� 1�� ������ ����
int inputScore(Student *s){
    char title[][20] = {"����", "����", "����"};
    int sum = 0, i = 0;

    printf("�л��� �̸� �Է� : ");
    scanf("%s", s->name);

    for(i=0;i<3;i++){
        printf("%s ���� �Է� : ", title[i]);
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

    printf("%s �л��� ���� :  %d , ����� %.2f", s1.name, sum, avg);
    return 0;
}