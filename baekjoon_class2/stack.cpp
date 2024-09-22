// 백준 1974
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    stack<int> s;
    vector<char> answer;
    int n; cin >> n;
    int value = 1;
    s.push(0);
    for(int i = 0 ; i< n ; i++){
        int num; cin >> num;
        if(!s.empty() && s.top() == num){
            s.pop();
            answer.push_back('-');
        }else if(value <= num){
            while(s.top() != num){
                s.push(value++);
                answer.push_back('+');
            }
            s.pop();
            answer.push_back('-');
        }else if(!s.empty() &&s.top() > num){
            cout << "NO";
            return 0;
        }
    }
    for(auto x : answer){
        cout << x << '\n';
    }
}
