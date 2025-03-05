#include <iostream> // 알파벳 개수

using namespace std;
int result[26];
int main(){
    string s;
    cin >> s;

    for(auto c : s){
        result[c-'a']++;
    }

    for(auto k : result){
        cout << k << ' ';
    }
}