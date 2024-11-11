#include <stdio.h>
// #define __int64 int

int main(){
    int n, tmp;
    scanf("%d", &n);

    int max = -10000001;
    int min = 10000001;

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (max < tmp) max = tmp;
        if (min > tmp) min = tmp;
    }

    printf("%d %d", min, max);

    return 0;
}