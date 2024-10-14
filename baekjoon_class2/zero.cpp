#include <iostream> // 제로 - 10773
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        if(a == 0){
            v.pop_back();
            continue;
        }
        v.push_back(a);
    }
    int sum = 0;
    for(auto &it : v){
        sum += it;
    }
    cout << sum;

}