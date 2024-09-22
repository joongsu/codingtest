#include <iostream> // 백준 2748

using namespace std;

//int dp(int x);    // 재귀로 구현하면 시간초과

long long d[92];    // 범위 초과로 인해서 long long 타입
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n;
    cin >> n;
    d[0] = 0;
    d[1] = 1;

    for(int i = 2 ; i<= n ;i++){
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[n] << '\n';
    

    //cout << dp(n) << '\n';
}

// int dp(int x){
//     if(x == 0)return 0;
//     if(x == 1)return 1;

//     return dp(x-1) + dp(x-2);
// }
