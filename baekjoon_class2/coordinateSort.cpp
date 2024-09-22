// 백준 11650 좌표정렬 , 11651
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct coordinate{
//     int x;
//     int y;
// };
// bool compare(coordinate a,coordinate b){
//     if(a.x == b.x){
//         return a.y < b.y; // 오름차순
//     }else{
//         return a.x < b.x; // 오름차순
//     }
// }
int main(){
    int n; cin >> n;
    // coordinate arr[100001];
    // for(int i = 0 ; i < n ; i++){
    //     cin >> arr[i].x >> arr[i].y;
    // }
    // sort(arr,arr+n,compare);

    // for(int j = 0 ; j < n ; j++){
    //     cout << arr[j].x << " "<< arr[j].y << '\n';
    // }
    // return 0;

    vector<pair<int,int>> v; // vector<vector<int>> arr(n , vector<int> (2,0)) 이러고 arr[i][0], arr[i][1]접근
    int x,y;
    v.reserve(n);
    for(int i = 0 ; i< n ; i++){
        cin >> x >> y ;
        v.emplace_back(pair(x,y));
    }
    sort(v.begin(),v.end());
    for(auto &it : v){
        cout << it.first <<" "<<it.second << '\n';
    }
}