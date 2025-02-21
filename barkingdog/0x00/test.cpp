#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;
int func1(int N){
    int result = 0;
    
    for(int i = 1 ; i <= N ; i++){
        if(i % 3 == 0 || i % 5 == 0) result += i;
    }
    return result;
}

int func2(int arr[], int N){

    for(int i = 0; i < N ; i++){
        for(int j = i+1; j < N; j++){
            if(arr[i] + arr[j] == 100) return 1;
        }
    }
    return 0;
}

int func3(int N){   // 제곱수 문제 , i 는 루트 N 까지 올라갈테니 시간복잡도는 루트 N
    for(int i = 1 ; i * i <= N ; i++){
        if(i*i == N) return 1;
    }
    return 0;
}

int func4(int N){
    int k = 1;
    while(2 * k <= N) k *= 2;
    return k;
}

int main(){
    int test1 = func1(34567);
    cout << test1 << '\n';
}