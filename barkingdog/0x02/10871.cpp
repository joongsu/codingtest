#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n,x;
    cin >> n >> x;
    int a;
    while(n-- > 0){
        cin >> a;
        if(a < x) cout << a << " ";
    }

}