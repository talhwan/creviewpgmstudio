#include <stdio.h>

int main(void)
{
    char name[20];
    char title[][20] = {"Kor", "Eng", "Math"};
    int score[3], sum = 0, i = 0;
    double avg;

    printf("Name : ");
    scanf("%s", name);

    for(i=0;i<3;i++){
        printf("%s score? : ", title[i]);
        scanf("%d", &score[i]);
        sum += score[i];
    }
    avg = sum / 3.0;

    printf("%s total score :  %d , avg :  %.2f", name, sum, avg);
    return 0;
}