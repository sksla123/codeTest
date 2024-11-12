// 문제
// 매일 매일 일곱 난쟁이는 광산으로 일을 하러 간다. 난쟁이가 일을 하는 동안 백설공주는 그들을 위해 저녁 식사를 준비한다. 백설공주는 의자 일곱개, 접시 일곱개, 나이프 일곱개를 준비한다.

// 어느 날 광산에서 아홉 난쟁이가 돌아왔다. (왜 그리고 어떻게 아홉 난쟁이가 돌아왔는지는 아무도 모른다) 아홉 난쟁이는 각각 자신이 백설공주의 일곱 난쟁이라고 우기고 있다.

// 백설공주는 이런 일이 생길 것을 대비해서, 난쟁이가 쓰고 다니는 모자에 100보다 작은 양의 정수를 적어 놓았다. 사실 백설 공주는 공주가 되기 전에 매우 유명한 수학자였다. 따라서, 일곱 난쟁이의 모자에 쓰여 있는 숫자의 합이 100이 되도록 적어 놓았다.

// 아홉 난쟁이의 모자에 쓰여 있는 수가 주어졌을 때, 일곱 난쟁이를 찾는 프로그램을 작성하시오. (아홉 개의 수 중 합이 100이 되는 일곱 개의 수를 찾으시오)

// 입력
// 총 아홉개 줄에 1보다 크거나 같고 99보다 작거나 같은 자연수가 주어진다. 모든 숫자는 서로 다르다. 또, 항상 답이 유일한 경우만 입력으로 주어진다.

// 출력
// 일곱 난쟁이가 쓴 모자에 쓰여 있는 수를 한 줄에 하나씩 출력한다.

#include <stdio.h>

int hasDuplicates(int arr[]) {
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (arr[i] == arr[j]) {
                return 1; // 중복이 있으면 true 반환
            }
        }
    }
    return 0; // 중복이 없으면 false 반환
}

int main() {
    int dwarfs[9];
    int arr[9]; 

    for(int i = 0; i< 9; i++) {
        scanf("%d", &dwarfs[i]);
    }
    
    int _dwarf;

    for(int i = 0; i< 9; i++) {
        arr[0] = i;
        for(int j = 0; j < 9; j++) {
            arr[1] = j;
            for(int k = 0; k < 9; k++) {
                arr[2] = k;
                for(int m = 0; m < 9; m++) {
                    arr[3] = m;
                    for(int n = 0; n < 9; n++) {
                        arr[4] = n;
                        for(int l = 0; l < 9; l++) {
                            arr[5] = l;
                            for(int o = 0; o < 9; o++) {
                                arr[6] = o;

                                if (hasDuplicates(arr)) continue;
                                _dwarf = dwarfs[i] + dwarfs[j] + dwarfs[k] + dwarfs[m] + dwarfs[n] + dwarfs[l] + dwarfs[o];

                                if (_dwarf == 100) {
                                    
                                    printf("%d\n", dwarfs[i]);
                                    printf("%d\n", dwarfs[j]);
                                    printf("%d\n", dwarfs[k]);
                                    printf("%d\n", dwarfs[m]);
                                    printf("%d\n", dwarfs[n]);
                                    printf("%d\n", dwarfs[l]);
                                    printf("%d\n", dwarfs[o]);
                                    
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}

int main() {
    int dwarfs[9];

    for(int i = 0; i< 9; i++) {
        scanf("%d", &dwarfs[i]);
    }
    
    int _dwarfs[9];
    int _dwarf;

    for(int i = 0; i< 9; i++) {
        _dwarfs[i] = dwarfs[i];
    }

    int b1, b2;

    for(int i = 0; i< 9; i++) {
        for(int j = 0; j < 9; j++) {
            b1 = _dwarfs[j];
            _dwarfs[j] = -1;

            for(int k = 0; k < 9; k++) {
                if (j==k) continue;

                b2 = _dwarfs[k];
                _dwarfs[k] = -1;

                _dwarf = 0;
                for(int m=0; m < 9; m++) {
                    if (_dwarfs[m] == -1) continue;

                    _dwarf += _dwarfs[m];
                }

                if (_dwarf == 100) {
                    for(int m=0; m < 9; m++) {
                        if (_dwarfs[m] == -1) continue;

                        printf("%d\n", _dwarfs[m]);
                    }

                    return 0;
                }

                _dwarfs[k] = b2;
            }
            _dwarfs[j] = b1;
        }
    }

    return 0;
}