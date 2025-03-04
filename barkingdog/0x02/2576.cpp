#include <iostream> // 홀수
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x,count = 0;
    int min = 100;
    int sum = 0;
    
    for(int i = 0 ; i < 7 ;i++){
        cin >> x ;

        if(x & 1){
            count++;
            sum += x;

            if(x < min){
                min = x;
            }
        }
    }

    if(count > 0) cout << sum <<'\n' << min;
    else cout << -1;
}
