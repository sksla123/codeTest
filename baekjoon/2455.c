#include <stdio.h>

int main() {
    int poff, pon;
    int cur_cnt = 0;
    int recent_cnt = 0;
    int max = 0;

    for (int i = 1; i < 4; i++) {
        scanf("%d %d", &poff, &pon);
        recent_cnt = cur_cnt;

        cur_cnt += pon;
        cur_cnt -= poff;

        if (cur_cnt > max) max = cur_cnt;
    }

    printf("%d", max);
    return 0;
}