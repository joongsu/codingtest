#include <iostream> // 백준 - 31561 시계탑
#include <iomanip>
using namespace std;
int main(){
    int m ;
    cin >> m;
    double result;

    if(m <= 30){
        result = m/2.0;
    }else{
        result = 15 + (m-30) * 3 /2.0;
    }
    cout << fixed << setprecision(1)<< result;
}