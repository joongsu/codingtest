#include <iostream> // 2309 - 일곱난쟁이
#include <algorithm>
using namespace std;

int arr[9],result[7];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum = 0;
    for(int i = 0 ; i < 9 ; i++){
        cin >> arr[i];
        sum += arr[i];
    } 

    for(int a = 0 ; a < 8 ;a++){
        for(int b = a+1; b < 9 ; b++){
            if(sum - (arr[a] + arr[b]) == 100){
                for(int c = 0, i = 0 ; c < 9 ; c++){
                    if(c != a && c != b) result[i++] = arr[c];
                }
            }
        }
    }
    sort(result,result+7);

    for(auto num : result){
        cout << num << '\n';
    }


}