#include <stdio.h>

int main(){
    long long n;
    scanf("%lld", &n);

    for(long long i=0; i < n; i++){
        if (i == 0) continue;
        for(long long j = 0; j < i; j++){
            printf("*");
        }
        for(long long j = n-i; j > 0; j--){
            printf("  ");
        }
        for(long long j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(long long i=0; i < n; i++) {
        printf("**");
    }
    printf("\n");

    for(long long i=0; i < n; i++){
        for(long long j = n-i; j > 1; j--){
            printf("*");
        }

        for(long long j = 0; j <= i; j++){
            printf("  ");
        }

        for(long long j = n-i; j > 1; j--){
            printf("*");
        }

        printf("\n");
    }

    return 0;
}