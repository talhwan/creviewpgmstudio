#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 학생 정보를 담아줄 구조체 선언
typedef struct _student {
    char snum[20]; //학번
    char name[20]; //이름
    int score[3]; //성적 3개
} Student;

void saveData(Student *s[], int count){
    FILE *fp;
    fp = fopen("student2.txt", "wt");
    int i=0;
    for(i=0;i<count;i++){
        if(s[i] == NULL) continue;
        fprintf(fp, "%s %s %d %d %d\n"
        ,s[i]->snum,s[i]->name,s[i]->score[0],s[i]->score[1],s[i]->score[2]);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}
int loadData(Student *s[]){
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("student2.txt", "rt");
    for(i=0; i < 100; i++){
        fscanf(fp, "%s", s[i]->snum);
        if(feof(fp)) break;
        fscanf(fp, "%s", s[i]->name);
        fscanf(fp, "%d", &s[i]->score[0]);
        fscanf(fp, "%d", &s[i]->score[1]);
        fscanf(fp, "%d", &s[i]->score[2]);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}
void searchName(Student *s[], int count){
    int scnt = 0;
    char search[20];
    printf("검색할 이름? ");
    scanf("%s", search);
    printf("%2s | %10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
        "No", "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
    );
    for(int i =0; i <count ; i++){
        if(s[i] == NULL) continue;
        if(strstr(s[i]->name, search)){
            printf("%2d | ", i+1);
            readScore(*s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 불러오기\n");
    printf("7. 이름 검색\n");
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
    /*
    printf("%10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
        "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
        );
    */
    int sum = 0, i=0;
    double avg;
    for(i=0;i<3;i++){
        sum += s.score[i];
        //printf("%4d %4d\n", sum, s.score[i]);
    }
    avg = sum / 3.0;
    printf("%10s | %8s | %4d | %4d | %4d | %5d | %5.1f\n",
    s.snum, s.name, s.score[0], s.score[1], s.score[2], sum, avg
    );
}
void listScore2(Student *s[], int count){
    printf("%2s | %10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
        "No", "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
        );
    int sum = 0, i=0;
    double avg;
    for(i=0;i<count;i++){
        if(s[i] == NULL) continue;
        printf("%2d | ", i+1);
        readScore(*s[i]);
    }
}
int selectData2(Student *s[], int count){
    int no;
    listScore2(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
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

    printf("Student Score Deleted!\n");
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
            listScore2(splist, index);
        } else if(menu == 2) {
            splist[index] = (Student *)malloc(sizeof(Student));
            result = createScore(splist[index]);
            if(result > 0){
                count += 1;
                index++;
            }
        } else if(menu == 3) {
            int no = selectData2(splist, index);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }
            updateScore(splist[no-1]);
        } else if(menu == 4) {
            int no = selectData2(splist, index);
            if(no == 0){
            printf("=> 취소됨!\n");
            continue;
            }

            result = deleteScore(splist[no-1]);
            if(result > 0){
                //삭제처리
                if(splist[no-1]) free(splist[no-1]);
                splist[no-1] = NULL;

                count--;
            }
        } else if(menu == 5) {
            saveData(splist, index);
        } else if(menu == 6) {
            count = loadData(splist);
            //printf(">>>>%d\n", temp_t);
            //count = loadData(splist);
            //index = count;
            index = count;
        } else if(menu == 7) {
            searchName(splist, index);        
        }
    }
    return 0;
}