// 백준 - 4153 직각삼각형
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    vector<int> v(3,-1);
    int max = 0;
    while(true){
        cin >> v[0] >> v[1] >> v[2] ;
        
        if(count(v.begin(),v.end(),0) == 3)
            break;

        sort(v.begin(),v.end()); // 큰 값을 가장 뒤로 

        if(pow(v[2],2) == (pow(v[0],2) + pow(v[1],2))){
            cout << "right" << '\n';
        }else{
            cout << "wrong" << '\n';
        }
    }
}
