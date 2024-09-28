#include <iostream> // 백준 - 11724 연결 요소의 개수
#include <vector>
using namespace std;
vector<int> graph[1001];
int visit[1001];
int count = 0;

void dfs(int x){
    if(visit[x] == 1)return;
    visit[x] = 1;

    for(auto &x : graph[x] ){
        if(visit[x] != 1)
            dfs(x);
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1 ; i<= n ; i++){
        if(visit[i] == 0){
            dfs(i);
            count++;
        }
    }
    cout << count;
}