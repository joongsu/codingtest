#include <iostream> // 1238 백준 파티 
#include <queue>
#include <vector>
#define INF 100000
using namespace std;

int n,x,m;
vector<pair<int,int>> v[1002];
int dst[1002];
int result;

void fc(int a, int d){
    memset(dst,INF,sizeof(dst));    // dst 를 INF 로 초기화, 사이즈 만큼 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // 최소 거리가 루트로

    pq.push({0,a}); // 현재 a 는 시작노드 
    dst[a] = 0; // 시작 지점의 거리 0 으로 

    while(!pq.empty()){
        int cx = pq.top().second; // 현재 정점
        int cdst = pq.top().first; // 현재 정점까지의 거리 
        pq.pop();

        if(cx == d){ // 현재 정점에 도착했다면
            result = dst[cx]; // 최단 거리 기록
            break;
        }
        for(int i = 0 ; i < v[cx].size(); i++){
            //현재 정점과 이어진 다음 정점들
            int nx = v[cx][i].first;
            int ndst = v[cx][i].second + cdst;

            if(dst[nx] > ndst){ // 최단거리니까
                dst[nx] = ndst;
                pq.push({ndst,nx}); // 최단거리가 갱신되었으니 nx 와 연결된 애들을 봐야함 
            }
        }
    }
}



int main(){
    // 이 도로들은 단방향임 오고가는데 거리 다를수있음 
    // n m x 

    cin >> n >> m >> x;

    int a,b,t;
    int ans1,ans2,ans;
    ans = 0;
    for ( int i = 0 ; i < m ; i++){
        cin >> a >> b >> t;
        v[a].push_back({b,t});  // a -> b , t시간
    }
    for(int i = 1 ; i <= n ; i++){  // 1 ~ n
        fc(i,x);    // i -> 2
        ans1 = result;
        fc(x,i);
        ans2 = result;
        if(ans < ans1 + ans2)
            ans = ans1 + ans2;
    }
}