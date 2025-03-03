#include <iostream> // 윷놀이
using namespace std;

string res = "DCBAE";

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input,result;

    for(int i = 0 ; i < 3 ; i++){
        result = 0;
        for(int j = 0 ; j < 4 ; j++){
            cin >> input;
            result += input;
        }
        cout << res[result] << '\n';
    }

    // int a[4];
    
    // for(int i = 0 ; i < 3 ; i++){
    //     int count = 0;
    //     cin >> a[0] >> a[1] >> a[2] >> a[3];
    //     for(int j = 0 ; j < 4 ; j++){
    //         if(a[j] == 1) count++;
    //     }
    //     if(count == 1) cout << 'C';
    //     else if(count == 2) cout <<'B';
    //     else if(count == 3) cout << 'A';
    //     else if(count == 4) cout << 'E';
    //     else cout << 'D';
    //     cout << '\n';
    // }
}
