#include <iostream> //개수 세기

using namespace std;

int arr[101];
int num[203];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,v ;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        num[arr[i]+100]++;  // -100 -> 0 이다
    }
    cin >> v;

    cout << num[v+100] << '\n';
}