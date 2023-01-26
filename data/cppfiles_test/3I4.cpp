#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back               
#define mp make_pair         
#define nline "\n"                         
const ll INF_MUL=1e13;                                                           
const ll INF_ADD=1e18;      
#define f first                                       
#define s second                                      
#define pll pair<ll,ll>  
#define vl vector<ll> 
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>          
#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);  
#endif     
void _print(ll x){cerr<<x;}   
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD=998244353;             
const ll MAX=500500;
ll dig(char c){
    ll x=c-'0';
    return x;
}
void solve(){         
    string s; cin>>s;
    ll n=s.size();
    s=" "+s;
    ll ans=0;  
    for(ll j=1;j<=n;j++){
        if(s[j]=='_')
            s[j]='.';
    }
    if(n==1){
        ans+=((s[1]=='0')||(s[1]=='.')||(s[1]=='X'));
        cout<<ans;
        return;
    }  
    for(ll i=0;i<=9;i++){
        string now=s;
        ll options=1,freq=0;
        for(ll j=1;j<=n;j++){
            if(s[j]=='X'){
                freq++;        
                now[j]='0'+i;
            }
            if(now[j]=='.'){    
                if(j>=(n-1))  
                    continue;
                options*=(10-(j==1));
            }
        }      
        debug(options);
        if(s[1]=='0')
            continue;
        for(ll j=0;j<=9;j++){  
            for(ll k=0;k<=9;k++){
                ll rem=j*10+k;
                if(rem%25)
                    continue;
                if((j==0)&&(n==2))
                    continue;
                if((now[n-1]!='.')&&(dig(now[n-1])!=j))
                    continue;
                if((now[n]!='.')&&(dig(now[n])!=k))
                    continue;
                ans+=options;
            }
        }
        if(freq==0)
            break;
    }
    cout<<ans;
    return;                           
}                                               
int main()                                                                    
{                        
    ios_base::sync_with_stdio(false);                          
    cin.tie(NULL);                       
    #ifndef ONLINE_JUDGE               
    freopen("input.txt", "r", stdin);                                           
    freopen("output.txt", "w", stdout);    
    freopen("error.txt", "w", stderr);                        
    #endif        
    ll test_cases=1;                   
    //cin>>test_cases;    
    while(test_cases--){        
        solve();   
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
}  