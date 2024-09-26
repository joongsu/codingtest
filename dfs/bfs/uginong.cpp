#include <iostream> // 1012 유기농배추
#include <vector>
#include <algorithm>
using namespace std;
int graph[50][50];
int visit[50][50];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int countValue;
vector<int> v;
int boundX;
int boundY;
void dfs(int y, int x){
    visit[y][x] = 1;
    
    for(int i = 0 ; i< 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || nx >= boundX || ny >= boundY) continue;
        if(visit[ny][nx] == 0 && graph[ny][nx] == 1)
            dfs(ny,nx);
    }

}
int main(){
    int T;
    cin >> T ;
    int m,n,k;
    for(int t = 0 ; t < T ; t++){
        cin >> m >> n >> k;
        boundX = m;
        boundY = n;
        for(int i = 0 ; i < k ; i++){
            int x,y;
            cin >> x >> y;
            graph[y][x] = 1;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(graph[i][j] == 1 && visit[i][j] == 0){
                    dfs(i,j);
                    countValue++;
                }
            }
        }
        v.push_back(countValue);
        countValue = 0;
        for(int i = 0 ; i < n ; i++){
            fill(visit[i],visit[i] + m , 0);
            fill(graph[i],graph[i] + m , 0);
        }
    }
    for(auto &it : v)
        cout << it << '\n';
}