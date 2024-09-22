#include <iostream> //1654
#include <vector>
#include <algorithm>
using namespace std;    // 이분탐색 문제
int main(){
    vector<long long> v;        /// 4 11        802 743 457 539
    int k,n;

    cin >> k >> n;
    for(int i = 0; i < k ; i++){
        long long num;
        cin >> num;
        v.push_back(num);
    }
    auto maxValue = *max_element(v.begin(),v.end());

    long long left = 1;
    long long right = maxValue;
    long long mid;
    long long result = 0;
    while(left <= right){   // 1 ~ maxValue
        mid = (left + right)/2;

        long long sum = 0;


        for(auto &it : v){
            sum += (it/mid);    // 나눈 선의 길이 n과 비교해야함
        }

        if(sum >= n){    // sum이 크다는건 mid를 올려야함

            left  = mid + 1;
            result = max(result,mid);
        }else{
            
            right = mid - 1;
        }

    }
    cout << result << '\n';

}