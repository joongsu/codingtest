#include <iostream> // 숫자의 개수

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int t = a*b*c;
    int result[10] = {};

    while(t>0){ // 자릿수 별로 계산
        result[t%10]++;
        t/=10;
    }

    for(auto r : result){
        cout << r << '\n';
    }

}