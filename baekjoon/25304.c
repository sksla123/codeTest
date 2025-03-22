# include <stdio.h>

int main() {
    long long x, n, a, b, t;
    scanf("%lld", &x);
    scanf("%lld", &n);

    t = 0;

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld",&a, &b);
        t += (a * b);
    }

    (x == t) ? printf("Yes") : printf("No");
}