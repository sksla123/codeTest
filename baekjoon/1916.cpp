#include <iostream>
#include <algorithm>

#define ARR_MAX 1010
#define INF 101010

using namespace std;

// 도시 지도
int city_map[ARR_MAX][ARR_MAX];
char visited_map[ARR_MAX][ARR_MAX] = {0,};


// s 도시에서 출발하는 이동 가격이 가장 적은 목적지를 찾는 함수
int get_min_arrival(int s, int N) {
    int min_arrival = -1;
    int min_cost = INF;
    for (int i = s+1; i < N; i++) {
        if(visited_map[s][i] == 1) continue;
        int _c = city_map[s][i];
        if (_c < min_cost) {
            min_arrival = i;
            min_cost = _c;
        }
    }
    if(min_arrival != -1) visited_map[s][min_arrival] = 1;
    return min_arrival;
}

// 도시에서 도시로 이동하는 최단 비용을 업데이트함
void update_node(int s, int _s, int N) {
    int stopover_cost = city_map[s][_s];
    for (int i = _s + 1; i <= N; i++){
        int new_c = stopover_cost + city_map[_s][i];
        if(new_c < city_map[s][i]) city_map[s][i] = new_c; 
    }
}

int main() {
    // 도시의 개수(도시 지도 크기 제한 값)
    int N;
    // 버스의 개수(반복문의 제한 값)
    int M;

    cin >> N >> M;

    // 도시 지도 초기화
    fill(&city_map[0][0], &city_map[ARR_MAX][ARR_MAX], INF);

    // 방문 지도 초기화
    for(int i = 1; i <= N; i++) {
        fill(&visited_map[i][0], &visited_map[i][i], 1);
    }

    // 도시 지도 채우기
    for(int i = 0; i < M; i ++) {
        int s; // 시작 도시
        int e; // 도착 도시
        int c; // 이동 비용

        cin >> s >> e >> c;
        city_map[s][e] = c;
    }

    // 도시 지도 최소값 업데이트(다익스트라 알고리즘)
    for(int i = 1; i <= N; i ++) {
        city_map[i][i] = 0;
        // cout << "start_node: " << i << '\n';
        while(true){
            int min_arrival = get_min_arrival(i, N);
            // cout << "updated city: " << min_arrival << "\n";
            if (min_arrival == -1) break;
            update_node(i, min_arrival, N);
        }
    }
    // cout << "end" << '\n';

    // 시작 도시
    int s;
    // 도착 도시
    int e;
    
    cin >> s >> e;
    cout << city_map[s][e];

    return 0;
}