#include <stdio.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    if(a>b) printf(">");
    else if (a<b)
    {
        printf("<");
    }
    else {
        printf("==");
    }
    
    return 0;
}