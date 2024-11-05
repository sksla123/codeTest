#include <stdio.h>

int main(){
    long long n;
    scanf("%d", &n);

    for(long long i=0; i < n; i++){
        for(long long j = n-i; j > 1; j--){
            printf(" ");
        }

        for(long long j = 0; j <= i; j++){
            if (j == 0) printf("*");
            else printf("**");
        }

        printf("\n");
    }

    return 0;
}