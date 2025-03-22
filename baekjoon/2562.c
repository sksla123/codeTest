#include <stdio.h>
// #define __int64 int

int main(){
    int nums[9];

    for (int i = 0; i < 9; i++) {
        scanf("%d", &nums[i]);
    }

    int max = 0;
    int pos = -1;
    for (int i = 0; i < 9; i++) {
        if (nums[i] > max) {
            max = nums[i];
            pos = i+1;
        }
    }
    printf("%d\n%d", max, pos);

    return 0;
}