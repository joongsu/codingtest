#include <iostream> // 숨바꼭질 
#include <queue>
#include <algorithm>
using namespace std;

int dist[100002];
int n,k;    // n 수빈이 위치, k동생 위치
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    

    fill(dist,dist+100002,-1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    
    while(dist[k] == -1){
        auto cur = q.front(); q.pop();

        for(int nxt : {cur-1,cur+1,cur * 2}){
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    cout << dist[k] << '\n';

}