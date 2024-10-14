#include <iostream> // 벌집 - 2292

using namespace std;

int main(){

    //1 6 12 18 
    // 2~7 -> 6개
    // 8~19 -> 12개
    // 20 ~37 -> 18개
    int n;
    cin >> n;
    int w = 1;
    int i = 1;
    int base = 1;
    int result = 1;
    int max = 1;
    while(true){
        if(n == 1)break;
        base += (w);
        max += (6 * i);
        if(base <= n && n <= max){
            result += i;
            break;
        }
        w = (6*i);
        i++;
    }
    /*
    int cnt = 0;
    int a = 1;
    while(n > a+6 * cnt){
        a += 6 * cnt;
        cnt++;
    }
    cout << cnt + 1;
    */
    
    cout << result;
}