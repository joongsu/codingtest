// 백준 - 1018 체스 다시 칠하기
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Wboard[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};
string Bboard[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int cntWB(int x , int y);
int cntBB(int x , int y);
string board[50];


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >>m; // 10 13
    cin.ignore();


    for (int i = 0; i < n; i++)
        getline(cin, board[i]);
    int minValue = 65;
    for(int i = 0 ; i + 8 <= n ; i++){
        for(int j = 0 ; j + 8 <= m ; j++){
            int tmp = min(cntWB(i,j),cntBB(i,j));
            if(tmp < minValue) minValue = tmp;
        }
    }
    cout << minValue;
}

int cntWB(int x , int y){
    int cnt = 0;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(board[x+i][y+j] != Wboard[i][j]) cnt++;
        }
    }
    return cnt;
}
int cntBB(int x , int y){
    int cnt = 0;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(board[x+i][y+j] != Bboard[i][j]) cnt++;
        }
    }
    return cnt;
}
