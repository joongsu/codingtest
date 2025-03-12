#include <iostream> //그림
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int board[502][502];
bool vis[502][502];

int n,m;

int dx[4] = {-1,0,1,0}; // 12시부터 시계방향
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i< n; i++)
        for(int j = 0 ; j < m; j++)
            cin >> board[i][j];
    int count = 0;
    int maxArea = 0;

    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ; j< m ; j++){
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            count++;
            queue<pair<int,int>> q;
            vis[i][j] = 1;
            q.push({i,j});
            
            int area = 0;
            while(!q.empty()){
                pair<int,int> cur = q.front(); q.pop();
                area++;
                for(int i =0 ; i<4 ; i++){
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != 1 || vis[nx][ny] != 0) continue;
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
            maxArea = max(maxArea,area);
        }
    }
    cout << count << '\n' << maxArea;
}