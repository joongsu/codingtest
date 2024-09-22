#include <iostream> // 1로 만들기 bfs, dp 1463번
#include <queue>
using namespace std;

int dp[1000001];
int visit[1000001]; // bfs
//int dp(int x,int count);
void bfs(int n);
int main(){
    /*
    X가 3으로 나누어 떨어지면, 3으로 나눈다.
    X가 2로 나누어 떨어지면, 2로 나눈다.
    1을 뺀다.
    */
    // 10 -> 9 -> 3 -> 1    // 2or3 을 만들어야함 2or3의 배수라면 


    int n ;
    cin >> n ;
    dp[1] = 0;

    for(int i = 2 ; i<=n ; i++){
        dp[i] = dp[i-1] + 1;

        if(i % 2 == 0) dp[i] = min(dp[i],dp[i/2] + 1);

        if(i % 3 == 0) dp[i] = min(dp[i],dp[i/3]+1);

    }
    cout << dp[n] << endl;
    // int count = 0;
    // cout << dp(n,count) << '\n';
}

void bfs(int n){
    queue<int> q;
    q.push(n);
    visit[n] = 1;

    while(!q.empty()){
        int cur = q.front();q.pop();

        if(cur % 3 == 0 && visit[cur/3] == 0){  // 방문하지 않았고 3으로 나누어지면
            q.push(cur/3);  // 18 -> 6
            visit[cur/3] = visit[cur] + 1;
        }
        if(cur % 2 == 0 && visit[cur/2] == 0){
            q.push(cur/2);
            visit[cur/2] = visit[cur] + 1;
        }
        if(visit[cur - 1] == 0){
            q.push(cur -1);
            visit[cur -1] = visit[cur] + 1;
        }

    }
}


// 아래와 같이 풀었는데 이러면 시간초과가 난다 그래서 메모이제이션을 적용하여 중복계산을 줄여야 한다.
// int dp(int x,int count){
//     if(x == 1) return count;
//     if(x % 3 == 0)return min(dp(x/3,count + 1),dp(x-1,count +1));
//     if(x % 2 == 0)return min(dp(x/2,count + 1),dp(x-1,count +1));  // (5,1) , (9,1)
//     return dp(x-1,count + 1); // 4 2    // 10 -> 5 -> 4 -> 2 -> 1
// }    