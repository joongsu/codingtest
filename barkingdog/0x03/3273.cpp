#include <iostream> // 두 수의 합
#include <algorithm>

using namespace std;
int arr[2000001];
int num[100000];
int x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    cin >> x;

    for(int i = 0 ; i < n ; i++){
        if(x-num[i] > 0 && arr[x-num[i]]){
            count++;
            continue;
        }
        arr[num[i]]++;
    }
    cout << count;
}