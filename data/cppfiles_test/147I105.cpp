#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define endl '\n'

#define MOD 1000000007

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    string s;
    cin>> s;
    int n = s.length(), x = 2;
    vector<int>vc(n);
    vc[0] = 1;

    for(int i = 1; i < n; i += 1){
        if(s[i - 1] == 'E') vc[i] = vc[i  - 1];
        else vc[i] = x++;
    }

    // for(int X: vc)  cout<< X<< " ";
    // cout<< endl;
    bool no = 1;
    if(s[n - 1] == 'E'){
        if(s[0] != s[n - 1]){
            no = 1;
            if(n > 2 && s[n - 2] == 'N') no = 0;
        }
        else no = 0;
    }
    else if(s[n - 1] == 'N' && vc[0] == vc[n - 1]){
        no = 1;
    }
    else no = 0;

    no?cout<< "NO\n": cout<<"YES\n";
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t = 1;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}