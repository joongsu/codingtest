#include <iostream> // 토마토 다른 코드
#include <queue>
#include <algorithm>

using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    cin >> n >> m;

    queue<pair<int,int>> q;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                q.push({i,j});  // 익은 토마토 위치
            if(board[i][j] == 0)
                dist[i][j] = -1;    //익지 않은 토마토
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 )continue; // 아래로는 익지않은 토마토만 내려옴 + 방문 여부까지
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans , dist[i][j]);
        }
    }

}