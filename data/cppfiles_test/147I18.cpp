#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define ll long long
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fs first
#define sd second
#define rept(x,n) for(int i=x;i<n;i++)
#define rrept(n,x) for(int i=n-1;i>=x;i--)
#define all(v) v.begin(),v.end()
#define mpit map<int,int>::iterator
#define stit set<int,int>::iterator
#define quit queue<int,int>::iterator
#define maxt(a,b,c) max(a,max(b,c))
#define mint(a,b,c) min(a,min(b,c))
#define rsort(v) sort(v.rbegin(),v.rend())
#define pb push_back
#define printarr(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
#define printvec(v) for(int i = 0;i<v.size();i++)cout<<v[i]<<" ";cout<<"\n";
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(),order_of_key();
ll power(ll a,ll b){ll res = 1;while(b){if(b&1)res*=a;a*=a;b/=2;}return res;}
ll powerwithmod(ll a,ll b,ll mod){ll res = 1;while(b){if(b&1)res*=a;res%=mod;a*=a;a%=mod;b/=2;}return res;}
void sieve(vector<ll>&prime,ll n){ll candidate[n+1]={0};candidate[0]=1;candidate[1]=1;candidate[2]=0;
for(ll i = 4;i<=n;i+=2)candidate[i]=1;for(ll i = 3;i*i<=n;i+=2){if(candidate[i]==0){
for(ll j = i*i;j<=n;j+=i){candidate[j] = 1;}}}for(ll i = 2;i<=n;i++){if(candidate[i]==0)prime.pb(i);}}
ll first_value(vector<ll>&v,ll first,ll last,ll val){ll ans = -1;while(first<=last){
ll mid=first+((last-first)/2);if(v[mid]>=val){ans = mid;last = mid-1;}else first = mid+1;}return ans;}
ll last_value(vector<ll>&v,ll first,ll last,ll val){ll ans = -1;while(first<=last){
ll mid=first+((last-first)/2);if(v[mid]<=val){ans = mid;first = mid+1;}else last = mid-1;}return ans;}
/*---------------------------------------------------------------------------------------------------*/
void solve()
{
    string s;
    cin>>s;
    for(ll i = 0;i<s.length()-1;i++)
    {
        if(s[i] == 'N')
        {
            cout<<"YES\n";
            return;
        }
    }
    if(s[s.length()-1] == 'N')
    cout<<"NO\n";
    else
        cout<<"YES\n";
}
signed main()
{
    speed;
    int t=1;
    cin>>t;
    while(t--)
    {
         solve();
    }
    return 0;
}
