#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, tmp, res = 0;
    scanf("%d", &n);
    
    char *str = (char*) malloc(sizeof(char)*n);
    scanf("%s", str);

    for(int i = 0; i < n; i++) {
        tmp = str[i];
        // printf("%d\n", tmp);
        res += tmp - 48;
    }
    printf("%d", res);

    free(str);

    return 0;
}