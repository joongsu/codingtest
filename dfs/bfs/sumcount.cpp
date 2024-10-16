#include <iostream> // 백준 - 4963 섬의 개수
#include <cstring>
#include <vector>
using namespace std;
int graph[50][50];
int visited[50][50];
int dy[] = {-1,-1,0,1,1,1,0,-1}; // 12시부터 시계방향
int dx[] = {0,1,1,1,0,-1,-1,-1};
int counted = 0;
int width;
int height;
vector<int> result;
void dfs(int y,int x){
    if(visited[y][x] == 1) return;
    visited[y][x] = 1;
    for(int i = 0 ; i < 8 ; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || nx < 0 || nx >= width || ny >= height) continue;

        if(visited[ny][nx] != 1 && graph[ny][nx] == 1){
            dfs(ny,nx);
        }
    }
}
int main(){

    int w = -1;
    int h = -1;
    

    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0)break;
        width = w;
        height = h;

        for(int i = 0 ; i < h; i++){
            for(int j = 0 ; j < w; j++){
                int a;
                cin >> a;
                graph[i][j] = a;
            }
        }

        for(int k = 0 ; k < h ; k++){
            for(int l = 0; l < w ; l++){
                if(graph[k][l] == 1 && visited[k][l] != 1){
                    dfs(k,l);
                    counted++;
                }
            }
        }
        result.push_back(counted);
        counted = 0;

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
    }

    for(auto &it : result)
        cout << it << '\n';
}