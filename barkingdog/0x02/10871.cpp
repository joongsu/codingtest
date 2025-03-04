#include <iostream>

using namespace std;
// 10871 - x보다 작은 수 
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