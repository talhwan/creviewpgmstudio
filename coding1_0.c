#include <stdio.h>

int main(void){
    printf("한동대학교 프로그래밍 스튜디오 수업에 오신 학생분들 환영합니다.\n\n");

    char name[20];
    int num;
    printf("이름 : ");
    scanf("%s", name);
    printf("분반 : ");
    scanf("%d", &num);

    printf("%d 분반입니다.\n", num);
    printf("나 %s 하나님과 사람 앞에서 정직하고 성실하게 과제와 테스트를 수행하겠습니다.\n", name);
}