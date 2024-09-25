#include <iostream> // 백준 - 바이러스 2606
#include <vector>

using namespace std;
vector<int> graph[101];
bool visit[101];

void dfs(int v){
    
    visit[v] = true;

    for(auto i : graph[v]){
        if(!visit[i])
            dfs(i);
    }
}

int main(){

    int n,m;
    cin >> n >> m;
    int count = 0;
    for(int i = 0; i < m ; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    dfs(1);

    for(int i = 1; i <=n ; i++){
        if(visit[i] == true)
            count++;
    }
    cout << count-1 << '\n';
}
