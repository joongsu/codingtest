#include <iostream> // 불! 
#include <algorithm>
#include <queue>

using namespace std;
string board[1002];
int dist1[1002][1002];  // 지훈
int dist2[1002][1002];  // 불
int n,m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
        cin >> board[i];
    for(int i = 0 ; i < n ; i++){
        fill(dist1[i],dist1[i]+m,-1);
        fill(dist2[i],dist2[i]+m,-1);
    }

    queue<pair<int,int>> q1;    // 지훈
    queue<pair<int,int>> q2;    // 불
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == 'J'){
                q1.push({i,j});
                dist1[i][j] = 0;
            } 
            if(board[i][j] == 'F'){
                q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }

    // bfs
    // 불 시간 구하기
    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            // 방문 안했고 갈 수 있는 곳
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q2.push({nx,ny});
        }
    }

    while(!q1.empty()){
        auto cur = q1.front(); q1.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){  // 탈출 성공
                                                        // bfs 는 거리순 기록 , 최초 탈출 시간 출력
                cout << dist1[cur.first][cur.second] + 1 << '\n';
                return 0;
            }

            if(dist1[nx][ny] >= 0||board[nx][ny] == '#') continue;
            if(dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.first][cur.second] + 1)continue;
            // 지훈이가 도착 하는 동시에 불이 번지거나 or 지훈이보다 먼저 불이 번졌을 때 이동 불가
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            q1.push({nx,ny});
        }     
    }

    cout << "IMPOSSIBLE" << '\n';

}