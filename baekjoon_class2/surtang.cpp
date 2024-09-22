#include <iostream>

using namespace std;

int dp(int x);
int d[5001];   // global 변수라서 0으로 초기화된 상태
int main(){ // 18 -> 15 , 13    -> 
    int n;
    cin >> n;

    d[3] == d[5] == 1;

    for(int i = 6 ; i <=n ; i++){
        if(d[i-3]){
            d[i] = d[i-3] + 1;
        }

        if(d[i-5]){
            d[i] = d[i] ? min(d[i] , d[i-5] + 1) : d[i-5] + 1;
        }
    }

}
int dp(int x){  //  11 -> 8,6 -> (5,3) , (3,1) -> -2,-4
    if(x < 0 ) return -6000;
    if(x == 3 || x == 5){
        return 1;
    }

    if(d[x] != 0)return d[x];

    return d[x] = min(dp(x-3) + 1, dp(x-5) + 1);
}

// ex) n = 18 -> 18 부터 (15+3) , (13+5) 로 내려가는 방식의 생각과 min(dp(x-3)+1,dp(x-5)+1) 점화식





    // int result = 0;
    // cout << 0 % 5 << endl;
    // while(n >= 0){
    //     if(n % 5 == 0){
    //         result += (n / 5);
    //         cout << result << endl;
    //         return 0;
    //     }
    //     n -= 3;
    //     result++;
    // }
    // cout << -1<< endl;
