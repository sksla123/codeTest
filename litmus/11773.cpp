#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, M;
    unordered_map<int, bool> numberMap;
    
    // 입력 받기
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numberMap[num] = true;
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        
        // map에서 검색 수행 및 결과 출력
        cout << (numberMap[target] ? 1 : 0) << "\n";
    }
    
    return 0;
}