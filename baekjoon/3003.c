// 체스는 총 16개의 피스를 사용하며, 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개로 구성되어 있다.

#include <stdio.h>
// #define __int64 int

int main(){
    int king, queen, look, bishop, knight, pawn;

    scanf("%d %d %d %d %d %d", &king, &queen, &look, &bishop, &knight, &pawn);
    // printf("%d %d %d %d %d %d\n", king, queen, look, bishop, knight, pawn);
    
    printf("%d ", 1-king);
    printf("%d ", 1-queen);
    printf("%d ", 2-look);
    printf("%d ", 2-bishop);
    printf("%d ", 2-knight);
    printf("%d ", 8-pawn);

    return 0;
}