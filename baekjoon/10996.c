#include <stdio.h>
#define __int64 int

int main(){
    int n;
    scanf("%lld", &n);
    
    // pattern을 n번 반복하라
    for (int i = 0; i < n; i++) {
        //pattern 구성
        for (int j = 0; j< n; j++) {
            if (j % 2 == 0) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
        //pattern 구성
        for (int j = 0; j< n; j++) {
            if (j % 2 == 0) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }


    return 0;
}