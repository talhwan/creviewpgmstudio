#include <stdio.h>

int main(void){
    printf("�ѵ����б� ���α׷��� ��Ʃ��� ������ ���� �л��е� ȯ���մϴ�.\n\n");

    char name[20];
    int num;
    printf("�̸� : ");
    scanf("%s", name);
    printf("�й� : ");
    scanf("%d", &num);

    printf("%d �й��Դϴ�.\n", num);
    printf("�� %s �ϳ��԰� ��� �տ��� �����ϰ� �����ϰ� ������ �׽�Ʈ�� �����ϰڽ��ϴ�.\n", name);
}