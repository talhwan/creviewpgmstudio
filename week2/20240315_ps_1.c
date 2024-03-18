#include <stdio.h>
#include <string.h>

/*
!! 20240315
여러개의 정보를 입력할 수 있도록 구성해보세요.
배열변수로 도전!!
전체 리스트를 보는 함수(listScore)도 만들어보세요!!

수정 해보겠습니다.
먼저, 전체 조회해서 그 중에 번호를 입력받겠습니다.
해당 번호에 해당하는 정보를 수정해주세요!
삭제까지 잘 진행해주셨습니다!

하지만.. 1~100 번 이외의 번호를 입력해도 되어서 잘못 입력하면 에러가 나는군요
그리고 이미 지워진 번호를 입력해도 진행이 됩니다.

이것에 대해 대비해주세요!
*/

// 학생 정보를 담아줄 구조체 선언
typedef struct _student {
    char snum[20]; //학번
    char name[20]; //이름
    int score[3]; //성적 3개
} Student;

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
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
    }
    return 1;
}

void readScore(Student s){
    int sum = 0, i=0;
    double avg;
    for(i=0;i<3;i++){
        sum += s.score[i];
    }
    avg = sum / 3.0;
    printf("%10s | %8s | %4d | %4d | %4d | %5d | %5.1f\n",
    s.snum, s.name, s.score[0], s.score[1], s.score[2], sum, avg
    );
}
void listScore(Student *s, int count){
    printf("%2s | %10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
        "No", "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
    );
    int sum = 0, i=0;
    double avg;
    for(i=0;i<count;i++){
        if(s[i].score[0] == -1) continue;
        printf("%2d | ", (i+1));
        readScore(s[i]);
    }
}
int selectData(Student *s, int count){
    int no;
    listScore(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    if(no > count || no < 0){
        printf("There is no data you selected.\n");
        no = 0;
    }
    return no;
}

int updateScore(Student *s){
    char title[][20] = {"Kor", "Eng", "Math"};
    int i = 0;
    
    printf("Student Num : ");
    scanf("%s", s->snum);

    printf("Name : ");
    scanf("%s", s->name);

    for(i=0;i<3;i++){
        printf("%s score : ", title[i]);
        scanf("%d", &s->score[i]);
    }
    printf("Student Data Updated!\n");
    return 1;
}


int deleteScore(Student *s){
    int t_answer;
    printf("your score delete process!!\n");
    printf("Are you sure?(Yes - 1/ No - 0) : ");
    scanf("%d", &t_answer);
    if(t_answer == 1){ 
    } else {
        return 0;
    }
    
    if(s->score[0] == -1){
        printf("ALREADY DELETED!!\n");
        return 0;
    }

    int i=0;
    //strcpy_s(s->snum, 20, ""); //이전에 정의된 문자배열을 초기화 하는 과정
    //strcpy_s(s->name, 20, "");
    for(i=0;i<3;i++){
        s->score[i] = -1;
    }
    printf("Student Score Deleted!\n");
    return 1;
}

int main(void)
{
    //Student s; //단일 데이터 때 사용한 변수
    Student slist[100]; //다중 데이터 때 사용한 변수(100개 까지만 됩니다.)
    
    int result = 0, count = 0, menu = 0;
    int index = 0; //입력할 데이터 번호

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
                continue;
            }
        }
        
        if(menu == 1){
            //readScore(s);
            listScore(slist, index);
        } else if(menu == 2) {
            /*
            count += createScore(&slist[index++]);
            */
            result = createScore(&slist[index]);
            if(result > 0){
                count++;
                index++;
            } 
        } else if(menu == 3) {
            int no = selectData(slist, index);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }
            updateScore(&slist[no-1]);
        } else if(menu == 4) {

            int no = selectData(slist, index);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }

            result = deleteScore(&slist[no-1]);
            if(result > 0){
                count--;
            }
        }
    }
    return 0;
}