/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
// 이 곳에 생각 정리와 코드 구현
    int i=0;
    int return_val = 0;
    for(i=0;i<5;i++){
        if(persons[i] < 2){
            return_val =  (i + 1);
            persons[i]++;
            break;
        }
    }
    return return_val;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
    // 이 곳에 생각 정리와 코드 구현
    char room_name[10][20] = {""};
    int room_count[10] = {0}; 
    int i=0;
    
    i=0;
    printf("남학생 명단 (%d명)\n", mc);
    for(i=0;i<mc;i++){
        printf("%d. %s [%d호]\n", (i+1), mn[i], mr[i]);
        if(room_count[mr[i]-101] > 0){
            strcat(room_name[mr[i]-101], " ");
        }
        strcat(room_name[mr[i]-101], mn[i]);
        room_count[mr[i]-101]++;
    }
    printf("\n", mc);
    
    i=0;
    printf("여학생 명단 (%d명)\n", wc);
    for(i=0;i<wc;i++){
        printf("%d. %s [%d호]\n", (i+1), wn[i], wr[i]);
        if(room_count[wr[i]-201 + 5] > 0){
            strcat(room_name[wr[i]-201 + 5], " ");
        }
        strcat(room_name[wr[i]-201 + 5], wn[i]);
        room_count[wr[i]-201 + 5]++;
    }
    printf("\n", mc);

    printf("호실별 배정 명단\n");
    for(i=0;i<10;i++){
        int room_num = (i+101);
        if(i>4){
            room_num = (i+201 -5);
        }
        printf("%d호 : %s\n", room_num, room_name[i]);
    }
}