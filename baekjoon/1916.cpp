// #include <iostream>
// #include <algorithm>

// #define ARR_MAX 1010
// #define INF 101010

// using namespace std;

// // 도시 지도
// int city_map[ARR_MAX][ARR_MAX];
// char visited_map[ARR_MAX][ARR_MAX] = {1,};

// // s 도시에서 출발하는 이동 가격이 가장 적은 목적지를 찾는 함수
// int get_min_arrival(int s, int N) {
//     int min_arrival = -1;
//     int min_cost = INF;
    
//     for (int i = 1; i < N; i++) {
//         if(i == s) {
//             visited_map[s][i] = 1;
//         }
        
//         if(visited_map[s][i] == 1) continue;
        
//         int _c = city_map[s][i];
        
//         if (_c < min_cost) {
//             min_arrival = i;
//             min_cost = _c;
//         }
//     }
//     // 방문 내용 기록
//     if(min_arrival != -1) visited_map[s][min_arrival] = 1;
//     return min_arrival;
// }

// // 도시에서 도시로 이동하는 최단 비용을 업데이트함
// void update_node(int s, int _s, int N) {
//     int stopover_cost = city_map[s][_s];
//     for (int i = 1; i <= N; i++){
//         if (i == s) continue;
//         int new_c = stopover_cost + city_map[_s][i];
//         if(new_c < city_map[s][i]) city_map[s][i] = new_c; 
//     }
// }

// int main() {
//     // 도시의 개수(도시 지도 크기 제한 값)
//     int N;
//     // 버스의 개수(반복문의 제한 값)
//     int M;

//     cin >> N >> M;

//     // 도시 지도 초기화
//     fill(&city_map[0][0], &city_map[0][0] + ARR_MAX * ARR_MAX, INF);

//     // 방문 여부 지도 초기화
//     for(int i = 1; i <= N; i++) {
//         fill(&visited_map[i][1], &visited_map[i][N], 0);
//     }

//     // 도시 지도 채우기
//     for(int i = 0; i < M; i ++) {
//         int s; // 시작 도시
//         int e; // 도착 도시
//         int c; // 이동 비용

//         cin >> s >> e >> c;
//         if (c < city_map[s][e]) {
//             city_map[s][e] = c;
//         }
//     }

//     // 도시 지도 최소값 업데이트(다익스트라 알고리즘)
//     for(int i = 1; i <= N; i ++) {
//         city_map[i][i] = 0;
//         // cout << "start_node: " << i << '\n';
//         while(true){
//             int min_arrival = get_min_arrival(i, N);
//             // cout << "updated city: " << min_arrival << "\n";
//             if (min_arrival == -1) break;
//             update_node(i, min_arrival, N);
//         }
//     }
//     // cout << "end" << '\n';

//     // 시작 도시
//     int s;
//     // 도착 도시
//     int e;
    
//     cin >> s >> e;
//     cout << city_map[s][e];

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

#define MAP_MAX 1010
#define INF 101010

using namespace std;

// node로 이루어진 map 구성
int node[MAP_MAX][MAP_MAX];

// 우선순위 큐를 통한 다익스트라 알고리즘 구현 (min_heap)
// 비용에 음수를 넣을 경우, max_heap으로도 min_heap 구성이 가능.
priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > pq;

// 최단거리 테이블(시작 노드에서부터의 최단거리 테이블)
int value[1005];

int main(){
	int n,m;
	int u,v,w;
	int start,end;
	
    // 도시 개수 및 버스 개수 입력
    // 도시 개수 -> 맵의 크기 지정
    // 버스 개수 -> 입력 반복문 생성 (엣지 갯수 지정)
    cin >> n >> m;
	
    // 지정된 도시 개수만큼 초기화
    // 도시 지도 생성 (초기화 1)
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) node[i][j] = INF;
    }
	
    // 자기 도시 방문 값 부여 (초기화 2)
	for(int i = 1; i<=n; i++){ 
		node[i][i] = 0;
		value[i] = INF;
	}
	
    // 도시 방문 비용 입력 (초기화 3)
	for(int i = 0; i < m; i++){ // 버스 개수만큼 입력 받음
		cin >> u >> v >> w;
        // 노드에 저장된 값보다 더 작은 값이 주어진다면 재초기화
        if(w < node[u][v]) node[u][v] = w;
	}
	
    // 구하고자하는 출발도시, 도착도시 입력
    cin >> start >> end;	
    
    // 다익스트라 알고리즘
	value[start] = 0;
	pq.push(make_pair(0, start)); // 시작 노드에서 시작노드로 이동하는 비용
    
    // 우선순위 큐를 사용하는 이유
    // 리스트 탐색으로 하는 경우 단점
    // 1. 탐색 시간의 증가
    // 2. 방문 테이블을 통해 해당 노드가 탐색 가능한지 여부를 나타내야함
    // 우선순위 큐는 heap구조를 통해 빠르게 탐색 가능하고, queue에 없는 노드는 탐색하지 않음.
	while(!pq.empty()){
		int x = pq.top().first; // 현재 노드까지의 이동 비용
		int U = pq.top().second; // 현재 노드
		pq.pop(); // queue 제거
		
        // 노드 업데이트
        // 그래프 순환 (인접 노드 확인)
		for(int i=1;i<=n;i++){			
			int V = i; // 인접 도시
			int W = node[U][i]; // 현재 노드와 인접한 도시까지 이동 비용
			
            // 이동 불가능한 노드일 때 스킵
			if( W == INF ) continue;
			
            // 새로운 이동 비용
            int new_x = x + W;
            // 새로 얻게된 이동 비용이 기존의 이동 비용보다 적다면, 해당 값을 최단 거리 테이블에 업데이트하고, 해당 값을 다시 다익스트라 탐색을 위해 PQ에 넣기
			if( new_x < value[V] ){
				value[V] = new_x;
				pq.push(make_pair(new_x, V));
			}
		}
	}
	
    // 이동 비용 출력
	cout << value[end];

	return 0;
}