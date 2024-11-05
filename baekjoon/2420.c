#include <stdio.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long c = a - b;

    if(c < 0) c = -c;

    printf("%lld", c);

    return 0;
}