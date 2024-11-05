#include <stdio.h>

int main() {
    long long t;
    scanf("%lld", &t);
    
    long long r = 1;
    if (t!=0) {
        for(long long i = 1; i <= t; i++) {
            r *= i;
        }
    }
    printf("%lld", r);

    return 0;
}
