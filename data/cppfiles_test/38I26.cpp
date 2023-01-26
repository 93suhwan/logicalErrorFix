#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> ve;
#define int ll
#define pb push_back
#define f first
#define s second
#define in(a) ll a;cin>>a
#define cs set <ll>
#define cm multiset <ll>
#define lp(i,n) for(i=0;i<n;i++)
#define dec(n) cout<<fixed<<setprecision(12)<<n
#define NO cout<<"NO"
#define YES cout<<"YES"
#define pow bpow
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
#define psh(x,y) graph[x].pb(y),graph[y].pb(x)
#define endl '\n'
#define bug(x) cerr<<#x<<" is: "<<x<<endl
#define inp(v) for (auto &i : v) cin >> i;




ull gcd(ull a ,ull b)
{
   return b?gcd(b,a%b):0;
}

ull lcm(ull a,ull b){
    return (a*b)/(gcd(a,b));
}

ull bpow(ull a,ull b){
    if(b==0) return 1;
    else if(b%2) return a*bpow(a,b/2)*bpow(a,b/2);
    else return bpow(a,b/2)*bpow(a,b/2);
}
void solve();
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    solve();
}

void solve()
{
    in(n); 
    in(m);
    char a[n][m];
    ll i,j;
    lp(i,n) lp(j,m) cin>>a[i][j];
    ll ct[m]={0}; 
    lp(i,n) lp(j,m){
        if(i==0 || j==0) continue;
        else{
            if(a[i-1][j]=='X' && a[i][j-1]=='X'){
                ct[j]++;
                a[i][j]='X';
            }
        }
    }
    ll pre[m+1]={0};
    for(i=1;i<m;i++) ct[i]+=ct[i-1];
    in(z);
    lp(i,z){
        in(a);
        in(b);
        if(ct[b-1]-ct[a-1]) NO;
        else YES;
        cout<<endl;
    }




}