#include <stdio.h>

int main(void){
    int int_a; //���� ��� ����
    char char_a[20]; //���ڿ� ��� ����

    // �̸��� �й��� �Է¹ް�,
    // �ѵ����б� ���α׷��� ��Ʃ��� ������ ���� 
    // �л��е� ȯ���մϴ�.
    // ���� ''�йݿ��� �����ϰ� �ֽ��ϴ�.
    
    /*
    printf("�̸���?");
    scanf("%s", char_a);
    printf("�й���?");
    scanf("%d", &int_a);

    printf("%d �й��Դϴ�.\n", int_a);
    printf("�� %s �ϳ��԰� ��� �տ��� �����ϰ� �����ϰ� ������ �׽�Ʈ�� �����ϰڽ��ϴ�.\n", char_a);
    
    printf("*\n");
    printf("**\n");
    printf("***\n");
    printf("****\n");
    printf("*****\n");
    */

   int i=0, j=0;
   int target_i=0; //�󸶳� ������ �����ϴ� ����(�Է¹ޱ�)
   int target_2i=0; //������ ���� ����
   int target_way=0; //������ ���� ����

   printf("�󸶳�??");
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