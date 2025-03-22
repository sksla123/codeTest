// 문제
//  
// $1$단계 과일은 체리, 
// $N$단계 과일은 수박이다.

//  
// $i$단계 과일 
// $2$개를 소모하여 
// $i+1$단계 과일 
// $1$개를 만들 수 있다. 
// $(1 \leq i \leq N-1)$ 

//  
// $K$개의 체리로 최대 몇 개의 수박을 만들 수 있는지 구해보자!

// 입력
// 첫 번째 줄에 정수 
// $N$과 
// $K$가 공백을 사이에 두고 주어진다. 
// $(2 \leq N \leq 30; 1 \leq K \leq 10^9)$ 

// 출력
// 첫 번째 줄에 만들 수 있는 수박의 최대 개수를 출력한다.

#include <stdio.h>

int main(){
    int n, m, wm;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n-1; i++) {
        m /= 2;
    }

    printf("%d", m);

    return 0;
}