#include <iostream>
#include <stack>

using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t; 

    while(t--){
        stack<int> st;
        string str;
        cin >> str;

        for(int i = 0 ; i < str.size(); i++){
            if(str[i] == '('){
                st.push(0);
            }else if(str[i] == ')'){
                if(!st.empty() && st.top() == 0){
                    st.pop();
                }
            }else{
                st.push(1);
            }
        }

        if (st.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
    }
}