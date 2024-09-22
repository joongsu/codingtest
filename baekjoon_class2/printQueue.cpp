// 백준 - 1966 프린터큐
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n; cin >> n;
    

    for(int i = 0 ; i < n ; i++){
        int num,idx; cin >> num >> idx; // 문서개수 , 궁금한문서 인덱스
        int value;
        vector<int> v;
        int cnt = 0;
        queue<pair<int,bool>> q;
        for(int j = 0 ; j < num ; j++){
            cin >> value;
            v.push_back(value);
            q.push(make_pair(value,j == idx));
        }
        while(!q.empty()){
            
            pair<int,bool> frontNum = q.front();
            int checkNum = frontNum.first;
            bool check = any_of(v.begin(),v.end(), [checkNum](int p){
                return p >checkNum;
            });
            if(check){
                v.erase(v.begin());
                v.push_back(checkNum);
                q.pop();
                q.push(frontNum);
            }else{
                cnt++;
                q.pop();
                v.erase(v.begin());  
                if(frontNum.second){
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }

}

//가장 앞에있는 문서의 중요도 확인 , 현재 문서보다 중요도가 높은 문서 있으면 가장
//뒤에 재배치 