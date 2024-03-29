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

추가 조건1
- 처음 프로그램을 시작했을때, 파일에 있는 모든 정보를 불러와서 배열에 저장해주세요.
- 배열에 변동사항이 생겼을때 파일에도 저장해주세요.

추가 조건2
- 학생 정보를 추가하는 경우 학번이 중복되었을 때, 다시 학번을 입력하게 해주세요.


*/
//===============

// 학생 정보를 담아줄 구조체 선언
typedef struct _student {
    char snum[20]; // 학번
    char name[20]; // 이름
    char phone[20]; // 연락처
    int t_input; // 충전 횟수
    int t_expend; // 사용 횟수
    int balance; // 잔액
} Student;
// 입금 
typedef struct _input {
    int snumno;
    int amount;
} Input;
// 출금
typedef struct _expend {
    int snumno;
    int amount;
} Expend;

int beforeCreateInput(Student *s[], int student_count, Input *p);
int createInput(Input *p, int result_int, Student *s[]);
void saveInput(Input *p[], int count);
void printInputContext();
void readInput(Input s);
void listInput(Input *s[], int count);

int beforeCreateExpend(Student *s[], int student_count, Expend *p);
int createExpend(Expend *p, int result_int, Student *s[]);
void saveExpend(Expend *p[], int count);
void printExpendContext();
void readExpend(Expend s);
void listExpend(Expend *s[], int count);

void saveStudent(Student *s[], int count);
int loadStudent(Student *s[]);
void printStudentContext();
void searchStudentByName(Student *s[], int count);
int searchStudentBySnum(Student *s[], int count, char search[20]);
int beforeCreateStudent(Student *s[], int count);
int createStudent(Student *s, char search[20]);
void readStudent(Student s);
void listStudent(Student *s[], int count);
int selectStudentByNo(Student *s[], int count);
int updateStudent(Student *s);
int deleteStudent(Student *s);

//===============
int beforeCreateInput(Student *s[], int student_count, Input *p){
    int result_int = 0;
    char search[20];

    while(1){
        printf("Student Num : ");
        scanf("%s", search);

        result_int = searchStudentBySnum(s, student_count, search);
        if(result_int == -1){
            printf("no data.\n");
        } else {
            break;
        }
    }
    result_int = createInput(p, result_int, s);
    return result_int;

}
int createInput(Input *p, int result_int, Student *s[]){

    //readStudent(*s[result_int]);
    p->snumno = result_int;
    printf("Amount : ");
    scanf("%d", &p->amount);

    s[result_int]->t_input = s[result_int]->t_input + 1;
    s[result_int]->balance = s[result_int]->balance + p->amount;

    return 1;
}
void saveInput(Input *p[], int count){
    FILE *fp;
    fp = fopen("input.txt", "wt");
//
    int i=0;
    for(i=0;i<count;i++){
        if(p[i] == NULL) continue;
        fprintf(fp, "%d %d\n"
        ,p[i]->snumno, p[i]->amount);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}
void printInputContext(){
    printf("%10s | %10s |\n",
        "No", "Amount"
    );
}
void readInput(Input s){
    printf("%10d | %10d |\n",
        s.snumno, s.amount
    );
}
void listInput(Input *s[], int count){
    printInputContext();
    int i=0;
    for(i=0;i<count;i++){
        if(s[i] == NULL) continue;
        readInput(*s[i]);
    }
}

//===============
int beforeCreateExpend(Student *s[], int student_count, Expend *p){
    int result_int = 0;
    char search[20];

    while(1){
        printf("Student Num : ");
        scanf("%s", search);

        result_int = searchStudentBySnum(s, student_count, search);
        if(result_int == -1){
            printf("no data.\n");
        } else {
            break;
        }
    }
    result_int = createExpend(p, result_int, s);
    return result_int;

}
int createExpend(Expend *p, int result_int, Student *s[]){

    //readStudent(*s[result_int]);
    p->snumno = result_int;
    printf("Amount : ");
    scanf("%d", &p->amount);

    s[result_int]->t_expend = s[result_int]->t_expend + 1;
    s[result_int]->balance = s[result_int]->balance - p->amount;

    return 1;
}
void saveExpend(Expend *p[], int count){
    FILE *fp;
    fp = fopen("expend.txt", "wt");
//
    int i=0;
    for(i=0;i<count;i++){
        if(p[i] == NULL) continue;
        fprintf(fp, "%d %d\n"
        ,p[i]->snumno, p[i]->amount);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}
void printExpendContext(){
    printf("%10s | %10s |\n",
        "No", "Amount"
    );
}
void readExpend(Expend s){
    printf("%10d | %10d |\n",
        s.snumno, s.amount
    );
}
void listExpend(Expend *s[], int count){
    printExpendContext();
    int i=0;
    for(i=0;i<count;i++){
        if(s[i] == NULL) continue;
        readExpend(*s[i]);
    }
}
//===============

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
    int i = 0;
    FILE *fp;
    fp = fopen("student.txt", "rt");
    if(fp == NULL){ 
        printf("파일이 존재하지 않아..미안해!!\n");
        return 0; 
    }
    for(i=0; i < 100; i++){
        //printf("%d!0000:\n", i);
        fscanf(fp, "%s", s[i]->snum);
        //printf("%d!00i00:\n", i);
        if(feof(fp)) break;
        //printf("%d!00ii00:\n", i);
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
    /*
    printf("5. 저장\n");
    printf("6. 불러오기\n");
    */
    printf("5. 학생 정보 저장\n");
    printf("6. 학생 정보 불러오기\n");

    printf("7. 학생 검색(이름)\n");
    
    printf("110. 충전 내역 조회\n");
    printf("120. 충전하기\n");
    printf("150. 충전내역 저장\n");

    
    printf("210. 사용 내역 조회\n");
    printf("220. 사용하기\n");
    printf("250. 사용내역 저장\n");
    
    //printf("102. 사용하기\n");

    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int beforeCreateStudent(Student *s[], int count){
    int result_int = 0;
    char search[20];
        
    while(1){
        printf("Student Num : ");
        scanf("%s", search);

        result_int = searchStudentBySnum(s, count, search);
        if(result_int == -1){
            break;
        } else {
            printf("already exist! please input again.\n");
        }
    }
    
    result_int = createStudent(s[count], search);
    return result_int;
}
int createStudent(Student *s, char search[20]){
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
    //공용
    int menu = 0, result = 0;

    //학생
    Student *splist[100];
    int student_count[2] = {0,0}; //count, index

    //입금
    Input *iplist[100];
    int input_count[2] = {0,0}; //count, index
    //출금
    Expend *eplist[100];
    int expend_count[2] = {0,0}; //count, index

    //일단 불러오기
    /*
    student_count[0] = loadStudent(splist);
    student_count[1] = student_count[0];
    */
    

    while(1){
        menu = selectMenu();
        if(menu == 0) {
            //종료!
            break;
        }
        if(menu == 1 || menu ==3 || menu == 4) {
            //조회, 수정, 삭제
            if(student_count[0] == 0) {
                //자료가 없을때는 입력만 가능!
                continue;
            }
        }
        
        if(menu == 1){
            listStudent(splist, student_count[1]);
        } else if(menu == 2) {
            splist[student_count[1]] = (Student *)malloc(sizeof(Student));
            result = beforeCreateStudent(splist, student_count[1]);
            if(result > 0){
                student_count[0] += 1;
                student_count[1]++;                
                //saveStudent(splist, student_count[1]);                
            }
        } else if(menu == 3) {
            int no = selectStudentByNo(splist, student_count[1]);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }
            result = updateStudent(splist[no-1]);
            if(result > 0){
                //saveStudent(splist, student_count[1]);
            }
        } else if(menu == 4) {
            int no = selectStudentByNo(splist, student_count[1]);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }

            result = deleteStudent(splist[no-1]);
            if(result > 0){
                //삭제처리
                if(splist[no-1]) free(splist[no-1]);
                splist[no-1] = NULL;
                student_count[0]--;
            }
        } else if(menu == 5) {
            //
            saveStudent(splist, student_count[1]);
        } else if(menu == 6) {
            student_count[0] = loadStudent(splist);
            student_count[1] = student_count[0];
        } else if(menu == 7) {
            searchStudentByName(splist, student_count[1]);   

        } else if(menu == 110) {
            listInput(iplist, input_count[1]);
        } else if(menu == 120) {
            //입금하기
            iplist[input_count[1]] = (Input *)malloc(sizeof(Input));

            result = beforeCreateInput(splist, student_count[1], iplist[input_count[1]]);
            if(result > 0){
                input_count[0] += 1;
                input_count[1]++;
                //saveInput(iplist, input_count[1]);
            } 
        } else if(menu == 150) {
            saveInput(iplist, input_count[1]);

        } else if(menu == 210) {
            listExpend(iplist, expend_count[1]);
        } else if(menu == 220) {
            //출금하기
            eplist[expend_count[1]] = (Expend *)malloc(sizeof(Expend));

            result = beforeCreateExpend(splist, student_count[1], eplist[expend_count[1]]);
            if(result > 0){
                expend_count[0] += 1;
                expend_count[1]++;
                //saveExpend(iplist, expend_count[1]);
            } 
        } else if(menu == 250) {
            saveExpend(eplist, expend_count[1]);


        }
    }
    return 0;
}