# include <stdio.h>

int main() {
    long long es[3];
    int flag, t1, t2;

    while(1) {
        scanf("%lld %lld %lld", &es[0], &es[1], &es[2]);
        if ((es[0] + es[1] + es[2]) == 0) break;

        int flag = 0;
        for(long long i = 0; i < 3; i++) {
            t1 = (i+1)%3;
            t2 = (i+2)%3;
            if ((es[i] * es[i] + es[t1] * es[t1]) == (es[t2] * es[t2])) {
                flag = 1;
                break;    
            }
        }
        (flag) ? printf("right\n") : printf("wrong\n");
    }

    return 0;
}