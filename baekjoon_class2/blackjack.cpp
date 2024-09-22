// 백준 - 2789 블랙잭
#include <vector>
#include <iostream>

using namespace std;
int card[100];
int N, M;
int compare(int a, int b){
    if(a <=M && a > b){
        return a;
    }else{
        return b;
    }
}
int search(vector<int>& v,int count, int max){

    if(count == 0){ // 재귀 탈출을 위한 조건
        return compare(card[v[0]] + card[v[1]] + card[v[2]],max);
    }
    int first = v.empty() ? 0 : v.back() + 1; // 전체를 보기위한 인덱스 작업 

    for(int i =  first ; i < N ; i++){
        v.push_back(i); // 넣고
        max = search(v,count - 1 , max); // 함수 들어간뒤
        v.pop_back(); // 제거 
    }
    return max;
}
int main(){
    cin >> N >> M ;
    vector<int> picked;
    int max = 0;
    for(int i = 0 ; i < N ; i++)
        cin >> card[i];

    cout << search(picked,3,max);

}