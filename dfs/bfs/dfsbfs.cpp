#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visit[1001];

void dfs(int x){
    visit[x] = true;
    cout << x << ' ';

    for(int i = 0 ; i < graph[x].size(); i++){
        int y = graph[x][i];
        if(!visit[y]) dfs(y);
    }
}

void bfs(int start){
    queue<int> q;

    q.push(start);  
    visit[start] = true;

    while(!q.empty()){
        int x = q.front();  
        q.pop();
        cout << x << ' ';

        for(int i = 0 ; i< graph[x].size() ; i++){  
            int y = graph[x][i];
            if(!visit[y]){
                q.push(y);
                visit[y] = true;
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
    for(int i = 0 ; i <n ; i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    dfs(v);
    fill(begin(visit),end(visit),false);
    cout << '\n';
    bfs(v);

}