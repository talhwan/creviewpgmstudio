#include <stdio.h>

int main(void)
{
    char name[20];
    char title[][20] = {"����", "����", "����"};
    int score[3], sum = 0, i = 0;
    double avg;

    printf("�л��� �̸� �Է� : ");
    scanf("%s", name);

    for(i=0;i<3;i++){
        printf("%s ���� �Է� : ", title[i]);
        scanf("%d", &score[i]);
        sum += score[i];
    }
    avg = sum / 3.0;

    printf("%s �л��� ���� :  %d , ����� %.2f", name, sum, avg);
    return 0;
}