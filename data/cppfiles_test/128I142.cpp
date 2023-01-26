#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define It it=se.begin();it!=se.end();it++
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define all(x) begin(x),end(x)
#define unmap unordered_map
#define pii pair<int,int>
#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vi vector<int>
#define ld long double
#define ll long long
#define pb push_back
#define sh short int
#define mid (l+r)/2
#define S second
#define F first
#define sqr 708
using namespace std;
const ll inf = 1e18;
const ll mod = 998244353;
const ld pai=acos(-1);
ll n;
void solve(){
    cin>>n;
    for(ll i=1;i*i<=n;i++){
        if(n%i != 0) continue;
        ll c = n/i;
        if(c < 6) continue;
        c--;
        if(c%2){
            cout<<(c/2)*i<<" "<<((c/2)+1)*i<<" "<<i<<endl;
            return;
        }
        else{
            cout<<((c/2)-1)*i<<" "<<((c/2)+1)*i<<" "<<i<<endl;
            return;
        }
    }
}
int main(){
    int t = 0;
    fast,cin>>t;
    while(t--) solve();
}
