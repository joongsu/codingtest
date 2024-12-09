#include <iostream>
#include <vector>
#include <queue>
#define INF 100001
using namespace std;

vector<pair<int,int>> v[1002];
int n,m,x;
int result;
int dst[1002];
void dj(int a,int d){
    memset(dst,INF,sizeof(dst));
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    // 첫번째 인자인 거리 기준으로 내림차순 정렬이 된다.

    pq.push({0,a});
    dst[a] = 0;

    while(!pq.empty()){
        int cx = pq.top().second;
        int cd = pq.top().first;
        pq.pop();
        if(cx == d){
            result = dst[cx];
            break;
        }
        for(int i = 0 ; i< v[cx].size(); i++){
            int nx = v[cx][i].first;
            int nd = v[cx][i].second + cd;

            if(dst[nx] > nd){
                dst[nx] = nd;
                pq.push({nd,nx});
            }
        }
    }
}
int main(){
    priority_queue<int,vector<int>> pqq;

    cin >> n >> m >> x;

    int ans1,ans2,ans;
    ans = 0;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;

        cin >> a >> b >> c;

        v[a].push_back({b,c});
    }

    for(int i = 1; i<=n ; i++){
        dj(i,x);
        ans1 = result;
        dj(x,i);
        ans2 = result;
        cout << ans1 << " "<< ans2 << '\n';
        //pqq.push(ans1+ans2);
    }
    //cout << pqq.top();
}