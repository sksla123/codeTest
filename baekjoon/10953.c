#include <stdio.h>
#include <string.h>

int main(){
    int n, tmp1, tmp2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d, %d", &tmp1, &tmp2);
        printf("%d\n", tmp1 + tmp2);
    }
    return 0;
}