#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
선언할 구조체
학생 / 충전 / 사용


학생 구조체 선언해봅시다.
저장할 정보는
=> 학번 / 이름 / 연락처 / 충전 횟수 / 사용횟수 / 현재 잔액

충전 구조체도 선언해봅시다.
=> no / 금액

사용 구조체도 선언해봅시다.
=> no / 금액

=====

점검차 실습 내용(3~4주차 천천히 만들어볼 프로그램)

1. 초기설정

1) 개요

C로 만들어보는 HGU페이

* HGU를 사용할 학생에 대한 정보 저장
* 각 학생의 입금 내역에 대해서 저장
* 각 학생의 사용 내역에 대해서 저장

2) 선언할 구조체

a. 학생
학번, 이름, 연락처,  충전 횟수, 사용횟수, 현재 잔액

b. 충전
학생배열의 순번, 금액

c. 사용
학생배열의 순번, 금액

[주의사항]
구조체 내용은 이후 확대기능에 따라 일부 변동 될 수도 있습니다.
각 구조체 배열은 파일에 각각 저장하고 / 불러올 수 있습니다.

바뀐 조건1
- 처음 프로그램을 시작했을때, 파일에 있는 모든 정보를 불러와서 배열에 저장해주세요.
- 배열에 변동사항이 생겼을때 파일에도 저장해주세요.

*/

// 학생 정보를 담아줄 구조체 선언
typedef struct _student {
    char snum[20]; // 학번
    char name[20]; // 이름
    char phone[20]; // 연락처
    int t_input; // 충전 횟수
    int t_expend; // 사용 횟수
    int balance // 잔액
} Student;

void saveStudent(Student *s[], int count){
    FILE *fp;
    fp = fopen("student.txt", "wt");
    int i=0;
    for(i=0;i<count;i++){
        if(s[i] == NULL) continue;
        fprintf(fp, "%s %s %s %d %d %d\n"
        ,s[i]->snum,s[i]->name,s[i]->phone
        ,s[i]->t_input,s[i]->t_expend,s[i]->balance);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}
int loadStudent(Student *s[]){
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("student.txt", "rt");
    for(i=0; i < 100; i++){
        fscanf(fp, "%s", s[i]->snum);
        if(feof(fp)) break;
        fscanf(fp, "%s", s[i]->name);
        fscanf(fp, "%s", s[i]->phone);
        fscanf(fp, "%d", &s[i]->t_input);
        fscanf(fp, "%d", &s[i]->t_expend);
        fscanf(fp, "%d", &s[i]->balance);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}
void printStudentContext(){
    printf("%2s | %10s | %8s | %10s | %10s | %10s | %10s |\n",
        "No", "StudentNum", "Name", "Phone", "Input", "Expend", "Balance"
    );
}
void searchStudentByName(Student *s[], int count){
    int scnt = 0;
    char search[20];
    printf("검색할 이름? ");
    scanf("%s", search);
    printStudentContext();
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;
        if(strstr(s[i]->name, search)){
            printf("%2d | ", i+1);
            readStudent(*s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
int searchStudentBySnum(Student *s[], int count, char search[20]){
    int result_order = -1;
    //printStudentContext();
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;
        if(strstr(s[i]->name, search)){
            printf("%2d | ", i+1);
            readStudent(*s[i]);
            result_order = i;
        }
    }
    //printf("!!!%d", result_order);
    return result_order;
}
/*

*/
int selectMenu(){
    int menu;
    printf("\n*** HGU PAY ***\n");
    printf("1. 학생 목록 조회\n");
    printf("2. 학생 추가\n");
    printf("3. 학생 수정\n");
    printf("4. 학생 삭제\n");
    printf("5. 저장\n");
    printf("6. 불러오기\n");
    printf("7. 학생 검색(이름)\n");
    printf("8. 충전하기\n");
    printf("9. 사용하기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createStudentBackup(Student *s){
        
    printf("Student Num : ");
    scanf("%s", s->snum);

    printf("Name : ");
    scanf("%s", s->name);
    
    printf("Phone : ");
    scanf("%s", s->phone);

    s->t_input = 0;
    s->t_expend = 0;
    s->balance = 0;
    return 1;
}
int beforeCreateStudent(Student *s[], int count){
    int result_int = 0;
    char search[20];
    
    printf("Student Num : ");
    scanf("%s", search);
    //scanf("%s", s_each->name);
    //printf("Student %s", s_each->name);
    
    while(1){
        //break;
        result_int = searchStudentBySnum(s, count, search);
        if(result_int == -1){
            break;
        } else {
            printf("already exist! please input again.");
        }
    }
    
    createStudent(s[count], search);
    return 1;
}
int createStudent(Student *s, char search[20]){

    /*
    printf("Student Num : ");
    scanf("%s", s->snum);
    */
    //s->snum = search;
    //s->snum = "112233";
    
    //strcpy(*s->snum,"112233");
    strcpy_s(s->snum, 20, search);

    printf("Student Name : ");
    scanf("%s", s->name);
    
    printf("Student Phone : ");
    scanf("%s", s->phone);
    
    s->t_input = 0;
    s->t_expend = 0;
    s->balance = 0;
    return 1;
}

void readStudent(Student s){
    printf("%10s | %8s | %10s | %10d | %10d | %10d |\n",
        s.snum, s.name, s.phone, s.t_input, s.t_expend, s.balance
    );
}
void listStudent(Student *s[], int count){
    printStudentContext();
    int i=0;
    for(i=0;i<count;i++){
        if(s[i] == NULL) continue;
        printf("%2d | ", i+1);
        readStudent(*s[i]);
    }
}
int selectStudentByNo(Student *s[], int count){
    int no;
    listStudent(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

int updateStudent(Student *s){
    char title[][20] = {"Kor", "Eng", "Math"};
    int i = 0;
    
    printf("Student Num : ");
    scanf("%s", s->snum);

    printf("Name : ");
    scanf("%s", s->name);
    
    printf("Phone : ");
    scanf("%s", s->phone);

    printf("Student Data Updated!\n");
    return 1;
}


int deleteStudent(Student *s){
    int t_answer;
    printf("your student delete process!!\n");
    printf("Are you sure?(Yes - 1/ No - 0) : ");
    scanf("%d", &t_answer);
    if(t_answer == 1){ 
    } else {
        return 0;
    }

    printf("Student Data Deleted!\n");
    return 1;
}

int main(void)
{
    Student s;
    Student *splist[100];
    int result = 0, count = 0, menu = 0;
    int index = 0; //입력할 데이터 번호
    int temp_t = 0;

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
            listStudent(splist, index);
        } else if(menu == 2) {
            splist[index] = (Student *)malloc(sizeof(Student));
            result = beforeCreateStudent(splist, index);
            
            //result = createStudent(splist[index]);
            if(result > 0){
                count += 1;
                index++;
            }
        } else if(menu == 3) {
            int no = selectStudentByNo(splist, index);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }
            updateStudent(splist[no-1]);
        } else if(menu == 4) {
            int no = selectStudentByNo(splist, index);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }

            result = deleteStudent(splist[no-1]);
            if(result > 0){
                //삭제처리
                if(splist[no-1]) free(splist[no-1]);
                splist[no-1] = NULL;

                count--;
            }
        } else if(menu == 5) {
            saveStudent(splist, index);
        } else if(menu == 6) {
            count = loadStudent(splist);
            //printf(">>>>%d\n", temp_t);
            //count = loadData(splist);
            //index = count;
            index = count;
        } else if(menu == 7) {
            searchStudentByName(splist, index);        
        }
    }
    return 0;
}