#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[4];
    char b[4];
    scanf("%s %s", a, b);

    char tmp_a, tmp_b;
    
    tmp_a = a[2];
    a[2] = a[0];
    a[0] = tmp_a;
    
    tmp_b = b[2];
    b[2] = b[0];
    b[0] = tmp_b;

    int _a, _b, res;
    _a = atoi(a);
    _b = atoi(b);

    res = (_a > _b) ? _a : _b;
    // printf("%s %s\n", a, b);
    printf("%d", res);

    return 0;
}