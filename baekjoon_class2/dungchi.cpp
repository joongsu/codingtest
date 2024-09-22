#include <iostream>
#include <vector>

using namespace std;

int main(){ // 자신 보다 더 큰 덩치의 사람이 k 명이면 그 사람의 덩치 등수는 k + 1이다
    int n;
    cin >> n;
    vector<pair<int,int>> v;

    for(int i = 0 ;i < n ; i++){
        int x,y;
        cin >> x >> y;
        v.emplace_back(x,y);
    }
    vector<pair<int,int>> copy = v;
    
    for(auto &p : v){
        int count = 0;
        for(auto iter = copy.begin() ; iter != copy.end(); iter++){
            if(p.first < (*iter).first && p.second < (*iter).second){
                count++;
            }
        }
        cout << count+1 << ' ';    
    }


}