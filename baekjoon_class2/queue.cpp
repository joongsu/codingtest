// 백준 10845 큐
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    queue<int> q;
    int n; cin >> n;

    while(n--){
        string str; cin >> str;
        if(str == "push"){
            int value; cin >> value;
            q.push(value);
        }else if(str == "front"){
            if(!q.empty()){
                cout << q.front() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }else if(str == "back"){
            if(!q.empty()){
                cout << q.back() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }else if(str == "pop"){
            if(q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.front()<< '\n';
                q.pop();
            }
        }else if(str == "size"){
            cout << q.size() << '\n';
        }else if(str == "empty"){
            if(q.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }
    }

}