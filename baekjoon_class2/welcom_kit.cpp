// 백준 - 30802 웰컴키트
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> v(6,0);
    int t,p;

    for(int i = 0 ; i < 6 ;i++)
        cin >> v[i];
    cin >> t >> p ;

    int tcnt = 0;

    for(auto it : v){
        int num = ceil((double)it/t);
        tcnt += num;
    }
    int pen = n / p;
    int add = n % p;

    cout << tcnt << '\n';
    cout << pen << " " << add ;


}