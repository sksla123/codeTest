// #include <stdio.h>

// int main() {
//     int n, n0, n1, n2, n3, n4, n5, n6, clap_cnt=0;
//     scanf("%d", &n);

//     for (int i = 0; i <= n; i++) {
//         // printf("%d", clap_cnt);
//         n6 = i / 1000000;
//         n5 = i / 100000;
//         n4 = i / 10000;
//         n3 = i / 1000;
//         n2 = i / 100;
//         n1 = i / 10;
//         n0 = i % 10;

//         // printf("%d %d %d %d %d %d\n", n1, n2, n3, n4, n5, n6);
//         if ((n0 != 0) && (n0 % 3 == 0)) clap_cnt += 1;
//         if ((n1 != 0) && (n1 % 3 == 0)) clap_cnt += 1;
//         if ((n2 != 0) && (n2 % 3 == 0)) clap_cnt += 1;
//         if ((n3 != 0) && (n3 % 3 == 0)) clap_cnt += 1;
//         if ((n4 != 0) && (n4 % 3 == 0)) clap_cnt += 1;
//         if ((n5 != 0) && (n5 % 3 == 0)) clap_cnt += 1;
//         if ((n6 != 0) && (n6 % 3 == 0)) clap_cnt += 1;
//     }

//     printf("%d", clap_cnt);
//     return 0;
// }

#include <stdio.h>

int count_claps(int n) {
    int claps = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && digit % 3 == 0) {
            claps++;
        }
        n /= 10;
    }
    return claps;
}

int main() {
    int n;
    scanf("%d", &n);

    int total_claps = 0;
    for (int i = 1; i <= n; i++) {
        total_claps += count_claps(i);
    }

    printf("%d", total_claps);
    return 0;
}