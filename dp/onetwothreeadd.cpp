#include <iostream> // 백준 - 9095 1,2,3 더하기
#include <vector>

using namespace std;

int d[100000];

int dp(int n){
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(d[n] != 0) return d[n];
    d[n] = dp(n-1) + dp(n-2) + dp(n-3); // 7이라고 치자 그럼  6 5 4
    return d[n];
}

int main(){
    int T;
    cin >> T ;

    for(int i = 0; i < T ; i++){
        int n = 0;
        int count = 0 ;
        cin >> n ;
        fill(d, d + 100000, 0);
        cout << dp(n) << '\n';
    }

}
