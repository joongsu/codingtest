#include <iostream> // 해싱 - 15829
#include <unordered_map>
#include <math.h>

using namespace std;
// 타입과 범위를 생각하며 초과할 것 같은 부분은 계속해서 나머지 연산 해주는게
// 포인트임

int M = 1234567891;
int main(){
    int n;
    string s;
    unordered_map<char,int> map;

    cin >> n;
    cin >> s;
    long long hash = 0;
    int value = 1;
    for(char c = 'a' ; c <= 'z' ; c++){
        map[c] = value;
        value++;
    }
    long long r = 1;
    for(int i = 0 ; i<n ; i++){
        int num = map[s[i]];
        hash += (num * r) % M;
        r = (r*31) % M;
    }
    cout << hash%M << '\n';
}