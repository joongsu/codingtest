#include <iostream> // 백준 - 1991 트리순회 (MAP으로 구현)
#include <map>

using namespace std;

typedef struct{
    char left;
    char right;
}Node;

map<char,Node> m;

void preorder(char cur){

    //if(cur == '.')return; 
    cout << cur;
    if(m[cur].left)
        preorder(m[cur].left);
    if(m[cur].right)
        preorder(m[cur].right);
    
}

int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        char cur,left,right;
        cin >> cur >> left >> right;

        if(left != '.')
            m[cur].left = left;
        if(right != '.')
            m[cur].right = right;
    }
    preorder('A');
}