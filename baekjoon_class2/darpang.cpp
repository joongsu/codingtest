#include <iostream> // 2869 - 달팽이는 올라가고 싶다.

using namespace std;
int main(){
    int a,v,b;
    
    cin >> a >> b >> v;
    
    int during = (v-a) / (a-b); // 5 2 , 2.xx

    if((v-a)%(a-b) == 0){   // v-a 까지 도달한 경우
        during += 1;
    }else{                  // v-a 까지 도달하지 못하여 v-a 까지 하루가 더 필요한 경우
        during += 2;
    }
    cout << during;
    
}