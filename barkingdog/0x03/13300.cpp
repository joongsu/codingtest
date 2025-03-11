#include <iostream> //방배정
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[2][7];

    for(int i = 0 ; i<2 ; i++)
        fill(arr[i],arr[i]+7,0);

    int n,k;
    cin >> n >> k;

    int s,y;
    for(int i = 0 ; i< n ;i++){
        cin >> s >> y;
        arr[s][y]++;
    }

    int count = 0;
    for(int i = 0 ; i< 2 ; i++)
        for(int j = 1 ; j <= 6 ; j++){
            int a = arr[i][j] / k;
            int b = arr[i][j] % k;
            
            if(arr[i][j] == 0) continue;
            if(b != 0) count += (a + 1);
            else{
                count += a;
            }
        }
    cout << count << '\n';
}