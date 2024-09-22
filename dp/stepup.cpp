#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> step(n);
    vector<int> dp(n,0);

    for(int i= 0 ; i < n ; i++) cin >> step[i];

    dp[0] = step[0];
    dp[1] = step[0] + step[1]; // 0 1 (2 못밟음) , 1
    dp[2] = max(step[0]+step[2],step[1]+step[2]);  //  0-2 , 1-2
    
    for(int i = 3 ; i <n ; i++){    // 2-3,1-3
        dp[i] = max(dp[i-2]+step[i],dp[i-3]+step[i-1]+step[i]);
    }
    //n번 계단의 경우 n-2번 계단 까지의 최대 + n번 계단 or n-3번 계단 최대 + n-1계단 + n계단 

    cout << dp[n-1] << '\n';


}