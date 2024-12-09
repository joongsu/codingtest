#include <iostream>
#include <vector>
using namespace std;
int n,m;
const int INF = 1000000;
vector<vector<int>> graph;
bool vis[20001];
int d[20001];

int getMinNode(){

    int min = INF;
    int node = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i] && d[i] < min){
            min = d[i];
            node = i;
        }
    }
    return node;
}

void dijkstra(int start){
    for(int i = 1 ; i <=n ; i++){
        d[i] = graph[start][i]; // 현재 시작 노드에서의 거리 d[i] 저장 
    }
    vis[start] = true; // 방문 처리 
    for(int i = 0 ; i < n - 1 ; i++){
        int smallNode = getMinNode(); // 현재의 시작노드 -> 노드 까지의 거리 d 중 최소 선택 
        
        vis[smallNode] = true;  // start를 시작으로 가는 것중 가장 최소라는건 그 외의 노드를 경유하면
                                // d[smallNode] 보다 반드시 크다, 그래서 바로 방문처리 하는거다. 
        for(int j = 1 ; j <= n ; j++){
            if(!vis[j]){
                if(d[smallNode] + graph[smallNode][j]< d[j]){
                    d[j] = d[smallNode] + graph[smallNode][j];
                }
            }
        }
        

    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n >> m;
    graph.resize(n + 1, vector<int>(n + 1, INF)); //INF 로 초기화
    int start;
    cin >> start;

    for(int i = 0 ; i < m ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w; // 각 간선의 가중치 저장 
    }
    dijkstra(start); // 시작 노드로 스타트 
    d[start] = 0;
    for(int i = 1 ; i <= n ; i++){
        if (d[i] == INF) {
            cout << "INF" << '\n';  
        } else {
            cout << d[i] << '\n';  
        }
    }

}