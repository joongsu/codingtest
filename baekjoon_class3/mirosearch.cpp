#include <iostream> // 백준 - 2178 미로탐색
#include <queue>
using namespace std;
char map[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int visited[101][101];
int dis[101][101];
int n,m;
void bfs(int start_x,int start_y){
    queue<pair<int,int>> q;
    q.push(make_pair(start_x,start_y));
    visited[start_y][start_x] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)continue;

            if(map[next_y][next_x] == '0'||visited[next_y][next_x] == 1) continue;

            visited[next_y][next_x] = 1;
            q.push(make_pair(next_x,next_y));
            dis[next_y][next_x] = dis[y][x]+1;
        }
    }

}

int main(){

    cin >> n >> m;

    for(int i = 0 ; i < n ; i ++){
        cin >> map[i];
    }
    

    bfs(0,0);
    cout << dis[n-1][m-1]+1<<endl;
}