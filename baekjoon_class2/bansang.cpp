//백준 2775 부녀회장이 될테야
#include <iostream>
using namespace std;

int result(int k , int n);

int main(){

    int T;
    cin >> T;
    int k,n;    // 1 3 , 2 3 
    
    for(int i = 0 ; i < T ; i++){
        cin >> k ;
        cin >> n ;
        int resolve = result(k,n);
        cout << resolve << endl;
    }

}
int result(int k , int n){
    if(n == 1){
        return 1;
    }else if(k == 0){
        return n;
    }
    else{
        return result(k,n-1) + result(k-1,n);
    }
}
