#include <stdio.h>
int main() {
    long long t;
    scanf("%lld", &t);
    long long a, b;
    for(long long i = 0; i < t; i++) {
        
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a+b);
    }

    return 0;
}
