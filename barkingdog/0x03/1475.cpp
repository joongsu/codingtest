#include <iostream> // 방번호

using namespace std;
int freq[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    int k,result;
    while(n > 0){
        freq[n % 10]++;
        n/=10;
    }

    for(int i = 0 ; i < 10; i++){
        if(i == 6 || i == 9) continue;
        ans = max(ans,freq[i]);
    }
        //freq[6] + freq[9]를 올림한 값이 필요한 세트 수
    ans = max(ans,(freq[6] + freq[9] + 1)/ 2);

    cout << ans;

}