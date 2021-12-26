#include <stdio.h>
void way(char ciphertext[300]);
void list(char ciphertext[300]);
void Error(int num);
char get_new_dict(char ciphertext[300]);
int count;
char dict[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //规则可变
int dict_length = sizeof(dict) - 1 ;
int main(void){
    char ciphertext[300];
    printf("[*]enter text:");
    scanf("%s",ciphertext);
    printf("[*]choose the encode way\n1:set a time \n2:list the situation\nchoose:");
    int choose;
    scanf("%d",&choose);
    switch (choose) {
        case 1: way(ciphertext); break;
        case 2: list(ciphertext); break;
        default:
            printf("[-]Error!");
            break;
    }
}
//固定位移
void way(char ciphertext[300]) {
    int times;
    char result[300];
    printf("[*]enter times: ");
    scanf("%d",&times);
    int j = 0 ;int i = 0 ;
    while (ciphertext[i]){
        while(ciphertext[i] != dict[j] ){
            j++;            //获取到位置
        }
        ciphertext[i] = dict[(j+times)%dict_length];    //考虑超出字典范围的情况
        i++;
    }
    printf("[+]result:");
    printf(ciphertext);
}
//遍历解密
void list(char ciphertext[300]) {
    int LTimes;
    int time = 1;
    printf("[*]enter the biggest times :");
    scanf("%d", &LTimes);
    for (; time <= LTimes; time++) {
        int j = 0;
        int i = 0;
        while (ciphertext[i]) {
            while (ciphertext[i] != dict[j]) {
                j++;            //获取到位置
            }
            ciphertext[i] = dict[(j + time) % dict_length];    //考虑超出字典范围的情况
            i++;
        }
        printf("[+]the result of the  %d time : ", time);
        printf(ciphertext);
        printf("\n");
    };
}
