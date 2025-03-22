// 증가 수식 현 변의 길이 *2 - 1

#include <stdio.h>

int main(){
    int cur_side = 2;
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        cur_side = (cur_side * 2) - 1;
    }

    printf("%d", (cur_side * cur_side));

    return 0;
}