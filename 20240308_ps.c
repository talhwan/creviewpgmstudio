#include <stdio.h>

int main(void){
    int int_a; //정수 담는 변수
    char char_a[20]; //문자열 담는 변수

    // 이름과 분반을 입력받고,
    // 한동대학교 프로그래밍 스튜디오 수업에 오신 
    // 학생분들 환영합니다.
    // 저는 ''분반에서 공부하고 있습니다.
    
    /*
    printf("이름은?");
    scanf("%s", char_a);
    printf("분반은?");
    scanf("%d", &int_a);

    printf("%d 분반입니다.\n", int_a);
    printf("나 %s 하나님과 사람 앞에서 정직하고 성실하게 과제와 테스트를 수행하겠습니다.\n", char_a);
    
    printf("*\n");
    printf("**\n");
    printf("***\n");
    printf("****\n");
    printf("*****\n");
    */

   int i=0, j=0;
   int target_i=0; //얼마나 찍을지 결정하는 변수(입력받기)
   int target_2i=0; //연산을 위한 변수
   int target_way=0; //연산을 위한 변수

   printf("얼마나??");
   scanf("%d", &target_i);
    target_2i = target_i*2 -1;
    for(i=0;i<target_2i;i++){
        //printf("*");
        if(i>=target_i){
            target_way = target_2i -i -1;
        } else {
            target_way = i;
        }
        for(j=0;j<=target_way;j++){            
            printf("%d", (i+1));            
            //if(i==j){printf("\n");}
        }
        //
        printf("\n");
    }


    for(i=0;i<target_i;i++){
        //printf("*");
        for(j=0;j<=i;j++){
            printf("%d", (i+1));
            //if(i==j){printf("\n");}
        }
        //
        printf("\n");
    }
}