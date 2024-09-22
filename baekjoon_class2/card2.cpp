// 백준 - 2164 카드2
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n;
int main(){
    int i;
    cin >> n;

    for(i = 1 ; i<= n; i++)
        q.push(i);
    while(q.size() != 1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}