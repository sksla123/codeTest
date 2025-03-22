#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char str[1010];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        printf("%c", str[0]);
        printf("%c", str[strlen(str)-1]);
        printf("\n");
    }
    return 0;
}