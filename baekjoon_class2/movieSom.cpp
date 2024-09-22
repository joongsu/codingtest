// 백준 - 1436 영화감독 숌
#include <iostream>

using namespace std;
int main(){
    int n; cin >> n;

    int num = 665;
    int cnt = 0;

    while(true){
        num ++;
        int tmp = num;
        while(tmp >= 666){
            if(tmp % 1000 == 666){
                cnt ++;
                break;
            }
            tmp /= 10;
        }
        if(n == cnt){
            cout << num;
            break;
        }
    } 
}
