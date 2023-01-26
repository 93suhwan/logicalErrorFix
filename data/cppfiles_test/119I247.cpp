#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    int s = 0;

    for(int& i : a){
        cin >> i;
        s += i;
    }

    if(s % n == 0){
        cout << 0 << '\n';
    }
    else cout << 1 << '\n';
    
}

int main(){
    int ttt;
    cin >> ttt;
    while (ttt--){
        
    }
    
    return 0;
}