#include <stdio.h>

int main(void)
{
    char name[20];
    int kor, eng, math;
    int sum;
    double avg;
    printf("�л��� �̸� �Է� : ");
    scanf("%s", name);
    printf("���� ���� �Է� : ");
    scanf("%d", &kor);
    printf("���� ���� �Է� : ");
    scanf("%d", &eng);
    printf("���� ���� �Է� : ");
    scanf("%d", &math);

    sum = kor + eng + math;
    avg = sum / 3.0;

    printf("%s �л��� ���� :  %d , ����� %.2f", name, sum, avg);
    return 0;
}