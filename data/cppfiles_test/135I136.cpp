
#include <bits/stdc++.h>

using namespace std;

void solve(){  
    
    int n,k;
    
    cin >> n >> k;
    
    vector<int> v(n,0);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int done[n]{0};
    sort( v.begin(), v.end() );
    
    int score = 0;
    int h = 0;
    int j = v.size();
    j--;
    for(int i=0; i<k; i++){
        int add = v[j-2]/v[j];
        done[j] =1;
        done[j-2] = 1;
        score += add;

        h++;
        
        if(h == 2){
            j -= 3;
            h=0;
        }else{
                j--;
        }
    }
    
    for(int i=j; i >=0; i--){
        if(done[i] != 1){
            score += v[i];
        }
    }
    
    cout << score << "\n";
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t; cin >> _t;
    while(_t--)solve();
}

