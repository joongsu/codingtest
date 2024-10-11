#include <iostream> // 배부 문제 - 27110
#include <vector>

using namespace std;
int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i< 3; i++){
        int a = 0;
        cin >> a;
        v.push_back(a);
    }
    int sum = 0 ;
    for(auto &it : v){
        if(it <= n){
            sum += it;
        }else{
            sum += n;
        }
    }

    cout << sum ;
}