#include <iostream> // 10989 - 수 정렬하기3
#include <map>
using namespace std;

// map은 내부 구조가 이진검색트리라서 자동 정렬이 된다는 점을 이용한 문제.
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    map<int,int> map;

    int n;
    vector<int> v;
    cin >> n;

    for(int i = 0; i < n ; i++){
        int num;
        cin >> num;

        map[num]++;
    }

    for(auto &pair : map){
        for(int i = 0 ; i< pair.second ; i++){
            cout << pair.first<< '\n';
        }
    }
}