#include <stdio.h>

int main(void)
{
    char name[20]; //�̸��� �Է¹��� ����
    int kor, eng, math; // �� ���� ���� �Է¹��� ����
    int sum; //���� ����
    double avg; //��� ����
    printf("�̸���? ");
    scanf("%s", name);
    printf("���� ����? : ");
    scanf("%d", &kor);
    printf("���� ����? : ");
    scanf("%d", &eng);
    printf("���� ����?");
    scanf("%d", &math);

    sum = kor + eng + math;
    avg = sum / 3.0;

    printf("%s ���� :  %d , ��� %.2f", name, sum, avg);
    return 0;
}