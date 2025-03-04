#include <iostream> // 숫자

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a,b;

    cin >> a >> b;

    if(a > b){
        cout << a - b - 1 << '\n';

        for(long long c = b + 1; c < a ; c++){
            cout << c << ' ';
        }
    }else if (a < b){
        cout << b - a - 1 << '\n';

        for(long long c = a + 1; c < b ; c++){
            cout << c << ' ';
        }
    }else{
        cout << 0;
    }
}