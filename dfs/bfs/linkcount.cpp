#include <iostream> // 백준 - 11724 연결 요소의 개수
#include <vector>
using namespace std;
vector<int> graph[1001];
int visited[1001];
int counted = 0;

void dfs(int x){
    if(visited[x] == 1)return;
    visited[x] = 1;

    for(auto &x : graph[x] ){
        if(visited[x] != 1)
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
        if(visited[i] == 0){
            dfs(i);
            counted++;
        }
    }
    cout << counted;
}