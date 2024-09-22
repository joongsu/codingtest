// 백준 1920 수찾기
#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main(){
    // binary_search() 사용해도 됨
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int> s;
    vector<int> v1;
    vector<int> v2;
    int n ,m;
    cin >> n;
    int a;
    for(int i = 0 ; i < n ; i++){
        cin >> a;
        s.insert(a); // 균형 이진트리로 구현되어있음 , 오름차순 
    }
    cin >> m;
    for(int j = 0 ; j < m ; j++){
        cin >> a;
        if(s.find(a) != s.end()){
            cout << 1 <<'\n';
        }else{
            cout << 0 << '\n';
        }
    }
    return 0;
}