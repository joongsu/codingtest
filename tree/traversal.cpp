#include <iostream> // 백준 1991 - 트리순회

using namespace std;
typedef struct{
    char cur;
    char left, right;       // 기본값이 없어 현재 쓰레기값 
}Node;
Node node[26];  

void preorder(int cur){
    cout << node[cur].cur;
    if(node[cur].left)
        preorder(node[cur].left - 'A');
    if(node[cur].right)
        preorder(node[cur].right - 'A');
}

void inorder(int cur){
    if(node[cur].left)
        inorder(node[cur].left - 'A');
    cout << node[cur].cur;
    if(node[cur].right)
        inorder(node[cur].right - 'A');
}

void postorder(int cur){
    if(node[cur].left)
        postorder(node[cur].left - 'A');
    if(node[cur].right)
        postorder(node[cur].right - 'A');
    cout << node[cur].cur;
}

int main(){
    int n;
    cin >> n ;

    for(int i = 0 ; i < n ; i++){
        char c,cl,cr;   // A B C
        cin >> c >> cl >> cr;
        
        node[c-'A'].cur = c;

        if(cl != '.') node[c-'A'].left = cl;
        if(cr != '.') node[c-'A'].right = cr;
        
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}