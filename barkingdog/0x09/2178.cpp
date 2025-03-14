#include <iostream> // 미로탐색
#include <algorithm>
#include <queue>

using namespace std;

string board[102];
int dist[102][102];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) cin >> board[i];
    for(int i = 0 ; i < n ; i++) fill(dist[i],dist[i]+m,-1);


    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' || dist[nx][ny] >= 0) continue;  // 1 인 애들만 넣음
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1]<< '\n';
}