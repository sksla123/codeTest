#include <stdio.h>

int main(){
    long long n, _n;
    scanf("%lld", &n);

    // 한 줄 당 띄어쓰기 개수 n - 1
    // 최대 n개의 줄 출력
    // 첫째 줄이면 별 한개
    
    _n = n;

    for (long long i = 0 ; i < n-1; i++) {
        // for (long long k = 0; k < _n; k++) printf("%lld", _n);
        for (long long k = 0; k < _n; k++) printf(" ");
        if (i != 0) printf("*");
        // for (long long k = _n; k < n; k++) printf("%lld", k);
        for (long long k = _n; k < n; k++) {
            if (k == _n) printf(" ");
            else printf("  ");
        }
        printf("*\n");
        if (_n > 0) _n -= 1;
    }
    for (long long i = 0 ; i < 2*n; i++) {
        printf("*");
    }
    return 0;
}