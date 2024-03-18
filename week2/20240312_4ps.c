#include <stdio.h>

/*
// 학생의 정보를 받을 구조체(Student)를 선언해보세요.
학번, 이름
국어, 영어, 수학 점수 (100점 만점)

1. 성적을 입력하는 함수(createScore)를 만들기
파라미터는 Student / 리턴은 int로(성공은 1 / 실패는 0)
* 100점 만점 기준으로 입력받을려고 해서, 
0점 이하거나 100점 이상이거나 하는 경우에는 입력을 취소
혹시 실수로 잘못 입력했을 경우, 다시 입력을 계속 받아봅시다!

2. 성적을 조회하는 함수(readScore)를 만들기
파라미터는 Student / 리턴은 int로 (성공은 1 / 실패는 0)

3. 성적을 수정하는 함수(updateScore)를 만들기
학번 이름도 수정할수 있도록 하겠습니다!
파라미터는 Student / 리턴은 int로 (성공은 1 / 실패는 0)

4. 성적을 삭제하는 함수(deleteScore)를 만들기
점수만 -1 로 모두 변경해보겠습니다!!
파라미터는 Student / 리턴은 int로 (성공은 1 / 실패는 0)
==> 삭제 정말 할껀지 확인하기
삭제 정말 하시겠습니까? (그렇다면 1을 눌러주세요!)

메인함수에서 어떤 기능 사용할지 물어보고 진행하는 프로그램 만들기
조회 수정 삭제 는 등록후에만 가능하도록!!

+ 구조체 안에 데이터가 있는지 없는지 여부 확인할 수 있도록 생각해보기

구조체로 선언한 Student를 배열로 선언해서,
여러개의 데이터를 입력해보세요!

*/

//구조체 선언
typedef struct _student {
    char snum[20]; //학번
    char name[20]; //이름
    int score[3]; //성적 3개
} Student;
//

int selectMenu(){
    int menu;
    printf("\n*** 점수 입력 프로그램 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createScore(Student *s){
    char title[][20] = {"Kor", "Eng", "Math"};
    int i = 0;
    
    printf("Student Num : ");
    scanf("%s", s->snum);

    printf("Name : ");
    scanf("%s", s->name);

    for(i=0;i<3;i++){
        printf("%s score : ", title[i]);
        scanf("%d", &s->score[i]);
        /*
        if(s->score[i] < 0 || s->score[i] > 100){
            printf("입력오류");
            return 0;
        } 
        */
        while(1){
            if(s->score[i] < 0 || s->score[i] > 100){
                printf("Score shoule be 0~100!! input again\n");
                printf("%s score : ", title[i]);
                scanf("%d", &s->score[i]);
            } else {
                break;
            }
        }
    }
    return 1;
}

int readScore(Student s){
    printf("%10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
    "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
    );

    int sum = 0, i=0;
    double avg;
    for(i=0;i<3;i++){
        sum += s.score[i];
    }
    avg = sum / 3.0;
    printf("%10s | %8s | %4d | %4d | %4d | %5d | %5.1f\n",
    s.snum, s.name, s.score[0], s.score[1], s.score[2], sum, avg
    );
    return 1;
}

int updateScore(Student *s){
    int result_val = 0;

    printf("Student DATA UPDATE!!\n");
    result_val = createScore(s);
    if(result_val > 0){
        printf("===Student DATA UPDATED===\n");
    }
    return 1;
}

int deleteScore(Student *s){
    int i=0;
    int t_answer;

    printf("your score delete process!!\n");
    printf("Are you sure?(Yes - 1/ No - 0) : ");
    scanf("%d", &t_answer);
    if(t_answer == 1){ 
    } else {
        return 0;
    }

    //strcpy_s(s->snum, 20, ""); //이전에 정의된 문자배열을 초기화 하는 과정
    //strcpy_s(s->name, 20, "");
    for(i=0;i<3;i++){
        s->score[i] = -1;
    }
    printf("===Student DATA Deleted===\n");
    return 1;
}


int main(void){
    Student s;
    int menu = 0, result = 0, count = 0;

    while(1){
        menu = selectMenu();
        if(menu == 0) {
            //종료!
            break;
        }

        if(menu == 1 || menu ==3 || menu == 4) {
            //조회, 수정, 삭제
            if(count == 0) {
                //자료가 없을때는 입력만 가능!
                printf("NO DATA!!\n");
                continue;
            }
        }
        
        if(menu == 1){
            readScore(s);
        } else if(menu == 2) {
            result = createScore(&s);
            if(result > 0){
                count = 1;
            }
        } else if(menu == 3) {
            result = updateScore(&s);
        } else if(menu == 4) {
            result = deleteScore(&s);
            if(result > 0){
                count = 0;
            }
        }
    }
    return 0;
}