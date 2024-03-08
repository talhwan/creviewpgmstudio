#include <stdio.h>

int main(void){
    /*
    char name[20];
    int num;

    printf("이름 : ");
    scanf("%s", name);
    printf("분반 : ");
    scanf("%d", &num);

    printf("%d 분반입니다.\n", num);
   */
  int target_num = 0;
  int target_next = 0;
  int target_2num = 0;
    int i=0, j=0;

    printf("gogo : ");
    scanf("%d", &target_num);

    target_2num = target_num * 2;
    for(i=0 ; i<target_2num ;i++){
        if(i<target_num){
            target_next = i;
        } else {
            target_next = target_2num -i -2;
        }
        for(j=0; j<=target_next ;j++){
            printf("%d", (i+1));
            /*
            if(j==i){
                printf("\n");    
            }
            */
        } 
        printf("\n");  
    }

}