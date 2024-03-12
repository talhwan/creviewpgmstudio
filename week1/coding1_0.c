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



    /* str1의 여유 크기가 str2 문자열을 담을수 있어야 한다.*/
    char str1[10] = "abc";
    char str2[] = "def1111";
    char str3[] = "ghi";
    
    /*strcat*/
    strcat(str1, str2);
    printf("strcat : %s\n", str1);
    
    /*strcat*/
    strncat(str1, str3,2); //2개까지 붙이기
    printf("strncat : %s\n", str1);
}