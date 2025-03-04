#include <iostream> // 핸드폰 요금
#include <cmath>
using namespace std;

int arr[20], n;

int main(){

    int sumM = 0, sumY = 0;
    cin >> n ;

    for(int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ;i++){
        sumY += (arr[i] / 30 + 1) * 10;
        sumM += (arr[i] / 60 + 1) * 15;
    }

    if(sumY < sumM){
        cout << 'Y' << ' ' << sumY;
    }else if(sumY > sumM){
        cout << 'M' << ' '<< sumM;
    }else{
        cout << "Y M "<< sumM;
    }

}