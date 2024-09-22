// 백준 - 11866 요세푸스 문제
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,k;
queue<int> q;

int main()
{
    int i;
    cin >> n >> k;

    for(i = 1 ; i<= n ; i++)
        q.push(i);
    cout << "<";
    while(q.size() != 0){
        for(i = 1 ; i< k ; i++){
            q.push(q.front());
            q.pop();    // 맨 앞에 있던 원소 삭제
        }
        cout << q.front();
        if(q.size() != 1)
            cout << ", ";
        q.pop();
    }
    // 벡터로 풀기
    // vector<int> v;
    // int n, k;
    // cin >> n >> k;
    // k -= 1;
    // int idx = 0;
    // v.reserve(n);
    // for (int i = 0; i < n; i++)
    // {
    //     v.push_back(i + 1);
    // }

    // cout << "<" ;
    // while (!v.empty())
    // {
    //         idx = (idx + k) % v.size();
    //         cout << v[idx];
    //         if(v.size() != 1)
    //             cout << ", ";
    //         v.erase(v.begin() + idx);

    // }
    cout <<">";
    // return 0;
}

// 7 3 -> 1 2 3 4 5 6 7  -> 1 2 4 5 6 7 -> 1 2 4 5 7 - > 1 4 5 7 -> 1 4 5 -> 1 4
//        0 1 2 3 4 5 6
// 2 -> 4 ->