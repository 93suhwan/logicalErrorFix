// cyan go go go!!!
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
#define RESPA_GOLD ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define popcnt __builtin_popcount
#define all(a) a.begin(),a.end()
#define low_b lower_bound
#define up_b upper_bound
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pii pair<int,int>
#define mii map<int,int>
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define endl '\n'
#define Y second
#define X first
typedef long double ld;
typedef long long ll;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
const ll mod=1e9+7;
const ll inf=1e18;
const ll N=3e5;
const ll col=107;
void fre_open(){freopen("file.in","r",stdin);freopen("file.out","w",stdout);}
ll binpow(ll n,ll k){if(k==0)return 1ll;if(k%2)return binpow(n,k-1)*n;ll kk=binpow(n,k/2);return kk*kk;}
void solve(){
    ll n;
    cin>>n;
    --n;
    if(__gcd(n-3,3ll)==1){
    cout<<3<<' '<<n-3<<' '<<1<<endl;
    return;
    }
    if(n%2!=0){
        cout<<n/2<<' '<<n-(n/2)<<' '<<1<<endl;
        return;
    }
    cout<<n/2-1<<' '<<n/2+1<<' '<<1<<endl;
}
int main() {
    //fre_open();
    RESPA_GOLD;
    ll tt=1;
    cin>>tt;
    while(tt--) solve();
}
