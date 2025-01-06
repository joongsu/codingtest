#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int x){
    visited[x] = true;
    cout << x << ' ';

    for(int i = 0 ; i < graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }

}

void bfs(int start){
    queue<int> q;

    q.push(start);  
    visited[start] = true;

    while(!q.empty()){
        int x = q.front();  
        q.pop();
        cout << x << ' ';

        for(auto i : graph[x]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){ 
    int n,m,v;

    cin >> n >> m >> v;

    for(int i = 0 ; i< m ; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1 ; i <=n ; i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    dfs(v);
    fill(begin(visit),end(visit),false);
    cout << '\n';
    bfs(v);

}