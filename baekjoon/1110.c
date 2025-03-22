# include <stdio.h>

int main() {
    long long a, b, tmp1, tmp2, cnt = 0;
    scanf("%lld", &b);
    // printf("%lld\n", b);

    tmp1 = b; // 처음에 얻은 값


    while(1) {
        cnt += 1;
        // printf("%lld\n", b);

        a = b / 10; // 10의 자리 값 [2]
        b %= 10; // 1의 자리 값 [6]

        // printf("%lld  %lld\n", a, b);

        tmp2 = b; // 1의 자리 값을 저장 [6]
        b += a;
        // printf("%lld\n", b);
        b %= 10; // [8]


        a = tmp2; // [6]

        // printf("%lld  %lld\n", a, b);

        b = (a * 10) + b;
        if (tmp1 == b) break;
        // if (cnt > 10) break;
    }

    printf("%lld", cnt);     
}