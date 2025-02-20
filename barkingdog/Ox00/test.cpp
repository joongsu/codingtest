#include <iostream> 
#include <vector>
#include <algorithm>

int func1(int N){
    int result = 0;
    
    for(int i = 1 ; i <= N ; i++){
        if(i % 3 == 0 || i % 5 == 0) result += i;
    }
    return result
}

int func2(int N){

}
int main(){
    int test1 = func1(34567);
    cout << test1 << '\n';
}