#include <stdio.h>
#include <string.h>

int main(){
    char str[1010];
    scanf("%s", str);
    int tmp;
    for(int i = 0; i < strlen(str); i++) {
        tmp = str[i];
        if (64 < tmp && tmp < 91) {
            tmp += 32;
        }
        else if (96 < tmp && tmp < 123) {
            tmp -= 32;
        }
        str[i] = tmp;
    }
    printf("%s", str);

    return 0;
}