#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
 
#define F first
#define S second
#define FAST    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vil;
typedef vector<pair<int,int>> pi;
 
void init_code(){
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
 
//------------------ Start --------------------//




void op(){  
    
    string s, t; cin>>s>>t;

    sort(s.begin(), s.end());

    int cnt = 0;

    for(int i=0; i<min(3, (int)s.size()); i++){
        if(s[i] == t[i]) cnt++;
    }

    if(cnt == 3) swap(s[1], s[2]);

    cout<<s;
}   
 
 
 
int main(){
 
    FAST;
 
    init_code();
 
    int t; cin>>t;
 
    for(int i=0; i<t; i++){
        op();
        cout<<"\n";
    }
}