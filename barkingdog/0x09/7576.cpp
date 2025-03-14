#include <iostream> // 토마토
#include <queue>
#include <algorithm>

using namespace std;
int box[1002][1002];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int vis[1002][1002];
int dist[1002][1002];
int main(){ // 1 : 익은 토마토 , 0 : 익지 않은 토마토 , -1: 들어있지 않음
            // 출력 : 0 -> 저장될때부터 모두 익어있음 , -1 -> 모두 익지 못하는 상황 , 최소 날짜
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int count = 0 ;
    cin >> m >> n;

    queue<pair<int,int>> q;
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) q.push({i,j});
        }
    
    int day = 0;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        vis[cur.first][cur.second] = 1;


        for(int i = 0 ; i< 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(box[nx][ny] != 0 || vis[nx][ny] == 1) continue;
            // 방문 x , 익지않은 토마토
            vis[nx][ny] = 1;
            q.push({nx,ny});
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            day = dist[nx][ny];
        }
    }
    
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(box[i][j] == 0 && vis[i][j] == 0){
                count++;
            }
        }
    }    
    if(count != 0){
        cout << -1 << '\n';
    }else{
        cout << day << '\n';
    }
        
}