#include <stdio.h>
// #define __int64 int

int main(){
    int n;
    //창영 상덕
    int cy=100, sd=100;
    int tmp1, tmp2;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        if (tmp1 == tmp2) continue;
        else if (tmp1 < tmp2) {
            cy -= tmp2;
        }
        else {
            sd -= tmp1;
        }
    }
    printf("%d\n%d", cy, sd);

    return 0;
}