#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int aver(const vector<int>& v);
int midNum(const vector<int>& v);
int mode(const vector<int>& v);
int range(const vector<int>& v);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n ;
    vector<int> v;
    for(int i = 0 ; i< n ; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    cout << aver(v)<< '\n';
    cout << midNum(v) << '\n';
    cout << mode(v) << '\n';
    cout << range(v) << '\n';
    
}

int aver(const vector<int>& v){
    double aver = 0;
    for(auto &it : v){
        aver += it;
    }
    
    return round(aver/v.size()) + 0.0; 
}
int midNum(const vector<int>& v){
    vector<int> copyVector = v;
    int index = v.size()/2;
    
    sort(copyVector.begin(),copyVector.end());
    return copyVector.at(index);
}

int mode(const vector<int>& v){
    unordered_map<int,int> frequency;
    vector<int> modes;
    int max = 0;
    
    for(auto &it : v){
        frequency[it]++;
        if(frequency[it] > max){
            max = frequency[it];
        }
    }

    for(auto &pair : frequency){
        if(pair.second == max){
            modes.push_back(pair.first);
        }
    }

    if(modes.size() == 1){
        return modes[0];
    }
    sort(modes.begin(),modes.end());

    return modes[1];
}
int range(const vector<int>& v){
        if(v.size() == 1)
            return 0;
    vector<int> copyVector = v;
    sort(copyVector.begin(),copyVector.end());
    int first = copyVector.front();
    int last = copyVector.back();
    
    return last - first;
}

