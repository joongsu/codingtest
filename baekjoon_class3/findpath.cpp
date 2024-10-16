#include <iostream> // 11403 - 경로찾기
                    // 인접행렬로 풀었지만 bfs가 더 직관적이고
                    // 좋은거 같다.

using namespace std;
int graph[100][100];
int visited[100][100];
int res[100][100];
int n;
void dfs(int x,int y){
    visited[x][y] = 1;
    res[x][y] = 1;
    for(int i = 0 ; i < n; i ++){
        if(graph[y][i] == 1 && !visited[x][i] ){
            dfs(x,i);
        }
    }

}
int main(){

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j ++){
            int a;
            cin >> a;
            graph[i][j] = a;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j ++){         
            if(graph[i][j] == 1 && visited[i][j] == 0)
                dfs(i,j);
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j ++){
            cout << res[i][j]<< ' ';
        }
        cout << '\n';
    }
    
}

/*
#include <iostream>
#include <queue>
using namespace std;
int graph[100][100];
int res[100][100];
int main(){

    int n; cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        int vis[100];
        fill(vis,vis+100,0);

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int cur = q.front();q.pop();

            for(int nx = 0 ; nx < n ; nx++){
                if(graph[cur][nx] == 0 || !vis[nx])continue;

                q.push(nx);
                vis[nx] = 1;
            }
        }

        for(int j = 0 ; j < n ; j ++)res[i][j] = vis[j];
    }

}
*/