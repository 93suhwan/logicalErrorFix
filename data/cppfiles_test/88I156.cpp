#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long int
#define double long double
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pqi priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) vector<int> a(n+f);for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define printdecimal(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define mod (int)(1e9+7)
#define inf LLONG_MAX
#define OrderedSet tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int exp(int x,int y){int val=1;x=x%mod;while(y>0){if(y&1)val=(val*x)%mod;y=y>>1;x=(x*x)%mod;}return val;}
int modinv(int x){return exp(x,mod-2);}
int add(int a,int b){a%=mod,b%=mod;a=((a+b)%mod+mod)%mod;return a;}
int sub(int a,int b){a%=mod,b%=mod;a=((a-b)%mod+mod)%mod;return a;}
int mul(int a,int b){a%=mod,b%=mod;a=((a*b)%mod+mod)%mod;return a;}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test
    {
        int n;
        cin>>n;
        inp(a,n,0);
        if(n%2==0) cout<<"YES\n";
        else
        {
            vector<pair<int,int>> v;
            for(int i=0;i+1<n;i++)
                if(a[i]>a[i+1]) v.pb({i,i+1});
            sort(all(v));
            if(v.empty()==false && v[0].se<v.back().fi) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}