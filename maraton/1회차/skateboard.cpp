#include <iostream> // 28417 - 스케이트보드
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v;
    vector<int> sumv;
    for(int i = 0; i < n ; i ++){
        int sum = 0;
        for(int j = 0; j < 7 ; j++){
            int a = 0;
            cin >> a;
            v.push_back(a);
        }
        sum += (v[0] > v[1]) ? v[0] :  v[1];
        v.erase(v.begin(),v.begin()+2);
        sort(v.begin(),v.end(),greater<int>());
        sum+= (v[0]+v[1]);
        sumv.push_back(sum);
        v.clear();
    }
    sort(sumv.begin(),sumv.end(),greater<int>());
    cout << sumv[0];

}
// 단순 배열을 사용하면 더 간단하게 풀 수 있다.