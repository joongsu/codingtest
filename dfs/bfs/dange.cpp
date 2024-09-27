#include <iostream> // 2667 - 백준 단지붙이기
#include <vector>
#include <algorithm>

using namespace std;
int graph[26][26];
int visit[26][26];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<int> cnt;
int countValue = 0;
int bound;
void dfs(int y,int x){
    
    visit[y][x] = 1;
    countValue++;
    
    for(int i = 0 ; i<4 ; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if( ny < 0 || nx < 0 || ny >=bound || nx >= bound) continue;
        if(visit[ny][nx] == 0 && graph[ny][nx] == 1 )
                dfs(ny,nx);
    }


}
int main(){
    int n ;
    cin >> n;
    bound = n;
    string str;
    for(int i = 0 ; i<n ; i++){
        cin >> str;
        for(int j = 0 ; j < n ; j++){
            graph[i][j] = str.at(j) - '0';
        }
    }

    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            if(visit[i][j] == 0 && graph[i][j] == 1){
                countValue = 0;
                dfs(i,j);
                cnt.push_back(countValue);
            }
        }
    sort(cnt.begin(),cnt.end());
    
    cout << cnt.size() << '\n';
    for(auto &it : cnt){
        cout<<it<<'\n';
    }


}