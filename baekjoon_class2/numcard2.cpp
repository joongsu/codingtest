// 백준 - 10816 숫자카드2
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

map<int,int> m;
int main()
{
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n , num;
    cin >> n;

    for(int i = 0; i < n ;i++){
        cin >> num;
        m[num]++;
    }
    int x;
    cin >> x;
    for(int i = 0 ; i < x ; i++){
        cin >> num;
        cout << m[num] << " ";
    }
    // vector<int> v1(n);
    // unordered_map<int,int> freq_map;

    // for(int i = 0 ;i <n ; i++){
    //     cin >> v1[i];
    //     freq_map[v1[i]]++; // 각 정수가 몇번 나왔는지에 대한 빈도수
    // }

    // cin >> m;
    // vector<int> v2(m);

    // for (int i = 0; i < m; i++) {
    //     cin >> v2[i];
    // }

    // for(int i = 0 ; i<m ;i++){
    //     if(freq_map.find(v2[i]) != freq_map.end()){
    //         cout << freq_map[v2[i]] << " ";
            
    //     }else{
    //         cout << 0 << " ";
    //     }
    // }
    

}
// 벡터 방식 시간초과 - find와 erase 의 잦은 사용으로 인해서 O(N) ,벡터에서 요소를 찾고 지우는 방식 비효율
// int n, m;
//     cin >> n;

//     vector<int> v1(n);

//     v1.reserve(n);
//     for (int i = 0; i < n; i++)
//         cin >> v1[i];
//      // -10 -10 2 3 3 6 7 10 10 10
//     cin >> m;
//     vector<int> v2(m);

//     for (int i = 0; i < m; i++)
//         cin >> v2[i];
//      // -10 -5 2 3 4 5 9 10

//     while(m--){
//         int count = 0;
//         auto iter2 = v2.begin();
//         auto iter1 = find(v1.begin(),v1.end(),*iter2);
//         while(iter1 != v1.end()){
//             count +=1;
//             v1.erase(iter1);
//             iter1 = find(v1.begin(),v1.end(),*iter2);
//         }
//         v2.erase(iter2);
//         cout << count <<" ";
//     }
//     if(v2.size() != 0)
//     {
//         for(int i = 0 ; i < v2.size() ; i++){
//             cout << 0 << " ";
//         }
//     }