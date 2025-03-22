#include <stdio.h>

int main(){
    long long n;
    scanf("%d", &n);

    for(long long i =0; i< n; i++){
        for (long long j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}