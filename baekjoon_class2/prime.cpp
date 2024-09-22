// 백준 1874 에라토스테네스의 체 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<int> v(m+1,0);
    v[1] = 1;
    for(int i = 2 ; i*i <= m ; i++){
        if(v[i] == 0){
            for(int j = 2 ; i*j <= m ; j++){
                v[i*j] = 1;
            }
        }
    }
    for(int k = n ; k <= m ; k++)
        if(v[k] == 0)
            cout << k <<'\n';
    return 0;
}

// for(int i = 2 ; i*i <= m ; i++){
//         if(v[i] == 0){
//             for(int j = i * i ; j <= m ; j += i){
//                 v[j] = 1;
//             }
//         }
//     }
