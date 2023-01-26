#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <math.h>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()
#define lb lower_bound
#define ub upper_bound
#define gcd(x,y) __gcd(x,y);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define os tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define ins insert
#define pii pair<int,int>
#define vc vector
#define vi vector<int>
#define vii vector<pii>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a,b) for(int i=a; i>b; i--)
#define Rep(i,a,b) for(int i=a; i<=b; i++)
#define Rev(i,a,b) for(int i=a; i>=b; i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define seea(a,x,y) or(int i=x; i<y; i++){cin >> a[i];}
#define seev(v,n) for(int i=0; i<n; i++){int x; cin >>x; v.pb(x);}
#define PI 3.141592653589793238462643383279502884L

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll rd(){
    ll x;
    cin >> x;
    return x;
}


const ll md = 1e9+7;

ll fastpow(ll a, ll b, ll MD){
    ll res =1;
 
    while(b>0){
        if(b&1)
            res = (res*a)%MD;
        a = (a*a)%MD;
        b>>=1;
    }
 
    return res;
}
 


void solve(){

    int n =rd();
    // cout << 3*fastpow(2,fastpow(2,n+1,md-1),md)/8 << endl;
    if(n==1){
        cout << 6 <<endl;
        return;
    }
    ll res =6;
    ll res2 =1;
    for(ll i=0; i<(1<<n-2); i++){
        res = (res*16)%md;
    }
    res/=4;
    for(ll i=0; i<(1<<n-2); i++){
        res2 = (res2*16)%md;
    }
    res2/=4;
    res =(res*res2)%md;
    cout <<res;

    return;
}


int main(){    
    IOS;
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);

    // int t =rd();
    // while(t--){
        solve();
    // }

 return 0;
}


