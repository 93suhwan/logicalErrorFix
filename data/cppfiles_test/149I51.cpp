#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> os;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
bool DEBUG = 1;
#define log2(x) ((x==0)? 0:63 - __builtin_clzll(x))
#define pb push_back
#define deb(x) if(DEBUG) cout<<#x<<" " <<x<<"\n";
#define ms(x, y) memset(x, y, sizeof x)
#define popcount __builtin_popcount
#define all(v) v.begin(), v.end()

const int inf=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
inline ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b);}
template<typename... T> void deb2(T&&... args){ if(DEBUG) ((cout<<args<<" "), ...); if(DEBUG) cout<<"\n";}

const ll mod = 1e9+7;
struct tri{
    ll x,y,z;
    bool operator<(const tri &one)const{
        if(x==one.x) return y<one.y;
        return x<one.x;
    }//pqs are backwards
};
ll fpow(ll a, ll b){ //can potentially overflow here if a is too big; you can mod a before putting it in
    if (b == 0) return 1;
    ll res = fpow(a, b / 2)%mod;
    if (b % 2) return ((res * res)%mod * a)%mod;
    else return (res * res)%mod;
}

const int maxn = 2e3+10;
int n,k;
ll x;
void solve(){
    //is it like that oly question? recursively find the num of letters, by grouping the remaining?
        //what to do if k is too big?
        //can we instead do it backwards? like mod it by k^1, k^2 ... k^3 etc etc
        //then instead of multiplying, we can do it by division??
    //to handle _ba == b_a, we can group chunks of asterisks tgt
        //we can make 0...num in group * k
        //xk+1
    //take the value %(xk+1)
    //divide by xk+1 as we progress the group? from back to front
    cin>>n>>k>>x;
    string s; cin>>s;
    vector<int> v;
    int cnt =0;
    for(int i =0; i<n; i++){
        if(s[i] =='a'){
            if(cnt){
                v.pb(k*cnt+1);//number of possible asterisks
            }
            v.pb(0);//0 is a
            cnt =0;
        }
        else{
            if(s[i] == '*'){
                cnt++;
            }
        }
    }
    if(cnt) v.pb(k*cnt+1);
//    for(int e: v){
//        cout<<e<<" ";
//    }
//    cout<<"\n";
    reverse(all(v));
    string ans ="";
    for(int e: v){
        if(e ==0){
            ans+='a'; continue;
        }
        if(x==0) continue;
        int rem = x%e;
        if(rem == 0) rem = e;
        for(int i =0; i<rem-1; i++) ans+='b';
        x/=e;
    }
    reverse(all(ans));
    cout<<ans<<"\n";
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) solve();

}
