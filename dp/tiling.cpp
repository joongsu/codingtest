#include <iostream> // 2 x n 타일링 11726 - 백준

using namespace std;

int main(){
    // n = 1  , 1   n = 2 , 2   n = 3 , 3  n = 4 5 ,    // 1 1 2 3 5    n >= 2 , v[n] = v[n-1] + v[n-2]

    long long v[1001] = {0};    

    int n;
    cin >> n;

    int result = 0 ;
    v[0] = 1;
    v[1] = 1;

    if(n >=2){
        for(int i = 2 ; i<=n ; i++){
            v[i] = (v[i-1] + v[i-2]) % 10007;
        }
    }

    cout << v[n] << '\n';
    
}

// 문제에서 나머지를 구하라고 주어지면 중간에 오버플로우 연산이 있다고 생각하자. 그리노 다 더하고 나머지를 하는 것과 
// 나눈 나머지와 v[i-1] 더해서 나머지를 구하는 것과 전부 다 값은 똑같다.