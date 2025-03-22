#include <stdio.h>
int main() {
    long long t;
    scanf("%lld", &t);
    
    for(long long i = 0; i < t; i++) {
        printf("%lld\n", i + 1);
    }

    return 0;
}
