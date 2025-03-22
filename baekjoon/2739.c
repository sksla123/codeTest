#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    
    for (int i = 1; i <= 9; i++ ) {
        printf("%lld * %lld = %lld\n", n , i, n * i);
    }

    return 0;
}
