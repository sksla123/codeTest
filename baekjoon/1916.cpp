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

// #include <iostream>
// #include <vector>
// #include <queue>

// #define MAP_MAX 1010
// #define INF 101010

// using namespace std;

// // node로 이루어진 map 구성
// int node[MAP_MAX][MAP_MAX];

// // 우선순위 큐를 통한 다익스트라 알고리즘 구현 (min_heap)
// // 비용에 음수를 넣을 경우, max_heap으로도 min_heap 구성이 가능
// priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > pq;

// // 최단거리 테이블(시작 노드에서부터의 최단거리 테이블)
// int value[1005];

// int main(){
// 	int n,m;
// 	int u,v,w;
// 	int start,end;
	
//     // 도시 개수 및 버스 개수 입력
//     // 도시 개수 -> 맵의 크기 지정
//     // 버스 개수 -> 입력 반복문 생성 (엣지 갯수 지정)
//     cin >> n >> m;
	
//     // 지정된 도시 개수만큼 초기화
//     // 도시 지도 생성 (초기화 1)
// 	for(int i = 1; i <= n; i++) {
// 		for(int j = 1; j <= n; j++) node[i][j] = INF;
//     }
	
//     // 자기 도시 방문 값 부여 (초기화 2)
// 	for(int i = 1; i<=n; i++){ 
// 		node[i][i] = 0;
// 		value[i] = INF;
// 	}
	
//     // 도시 방문 비용 입력 (초기화 3)
// 	for(int i = 0; i < m; i++){ // 버스 개수만큼 입력 받음
// 		cin >> u >> v >> w;
//         // 노드에 저장된 값보다 더 작은 값이 주어진다면 재초기화
//         if(w < node[u][v]) node[u][v] = w;
// 	}
	
//     // 구하고자하는 출발도시, 도착도시 입력
//     cin >> start >> end;	
    
//     // 다익스트라 알고리즘
//     // 다익스트라를 위한 초기화
// 	value[start] = 0; // 시작노드에서 시작노드로 이동하는 최단비용 == 0
// 	pq.push(make_pair(0, start)); // 시작 노드에서 시작노드로 이동하는 비용을 가지고 pq에 집어넣음 (다익스트라 시작점 부여)
    
//     // 우선순위 큐를 사용하는 이유
//     // 리스트 탐색으로 하는 경우 단점
//     // 1. 탐색 시간의 증가
//     // 2. 방문 테이블을 통해 해당 노드가 탐색 가능한지 여부를 나타내야함
//     // 우선순위 큐는 heap구조를 통해 빠르게 탐색 가능하고, queue에 없는 노드는 탐색하지 않음.
//     // 시작도시로부터 이동비용이 제일 작은 도시를 시작 점으로 하는 모든 도착 도시를 확인한 후
//     // 시작도시로부터 경유지를 통해 도착 도시로 이동하는 비용이 기존의 값보다 더 작을 때 업데이트할 수 있음.
// 	while(!pq.empty()){
// 		int cost = pq.top().first; // 경유지까지의 이동 비용
// 		int way_point = pq.top().second; // 경유지 후보
// 		pq.pop(); // queue 제거
		
//         // 노드 업데이트
//         // 그래프 순환 (인접 노드 확인)
// 		for(int i=1;i<=n;i++){			
//             // i = 인접 도시
// 			int _cost = node[way_point][i]; // 경유지와 인접한 도시까지 이동 비용
			
//             // 이동 불가능한 노드일 때 스킵
// 			if( _cost == INF ) continue;
			
//             // 새로운 이동 비용
//             int new_cost = _cost + cost;
//             // 새로 얻게된 이동 비용이 기존의 이동 비용보다 적다면, 해당 값을 최단 거리 테이블에 업데이트하고, 해당 값을 다시 다익스트라 탐색을 위해 PQ에 넣기
// 			if( new_cost < value[i] ){
// 				value[i] = new_cost;
// 				pq.push(make_pair(new_cost, i));
// 			}
// 		}
// 	}
	
//     // 이동 비용 출력
// 	cout << value[end];

// 	return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAP_MAX 1010
#define INF 101010

using namespace std;

int cost_table[MAP_MAX]; // 출발도시로부터 각 도시까지 최소 비용 테이블
vector<pair<int, int>> city_graph[MAP_MAX]; // [출발도시] <도착도시, 비용>으로 이루어진 도시 그래프

// 다익스트라 알고리즘
void dijkstra(int start){
    // 우선순위 큐 (min_heap(최소 힙)) -> 더 작은 값이 우선순위가 높음
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    
    // pair 구조 == <비용, 도착도시>
    pq.push(make_pair(0, start)); // 출발도시에서 출발도시로 이동하는 비용 == 0, 다익스트라를 위한 우선순위 큐의 초기 값
    cost_table[start] = 0; // 출발 도시에서 출발도시로 이동 하는 비용 = 0
    while (!pq.empty())
    {
        int cost = pq.top().first; // 출발도시에서 현재도시까지 비용
        int x = pq.top().second; // 현재도시
        pq.pop();
        
        // 현 도시까지 비용이 이미 기록된 비용보다 크면 pass
        if (cost_table[x] < cost) 
            continue;
        
        // x 도시와 이어진 도시들 검사
        for (int i = 0; i < city_graph[x].size(); i++){
            int nx = city_graph[x][i].first; // 다음 도시 
            int ncost = cost + city_graph[x][i].second; // 다음 도시까지 비용
 
            // 기록되어진 비용보다 지금 비용이 더 작다면
            // 큐에 넣어줌 
            if (vis[nx] > ncost){ 
                pq.push(make_pair(ncost, nx));
                vis[nx] = ncost; // 비용 다시 기록
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    
    v[0].push_back(make_pair(0, 0));
    memset(vis, 98765432, sizeof(vis)); // 모든 비용 최대로 
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    int st, dt; // 출발 도시, 도착 도시
    cin >> st >> dt;
    fc(st); 
    cout << vis[dt]; // dt 도시의 비용 출력
    return 0;
}
