#include <bits/stdc++.h>
#define ll long long
#define double long double
#define pb push_back
#define endl '\n'
#define er erase
#define sz size
#define in insert
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define INF LONG_LONG_MAX
using namespace std;

int N=3e5+11;

vector<ll> t(N*4, 0);
vector<ll> a(N);
vector<ll> dif;

void build(int v, int l, int r)
{
    if(l==r)
    {
        t[v]=dif[l];
        return;
    }
    else
    {
        int mid=(l+r)/2;
        build(2*v, l, mid);
        build(2*v+1, mid+1, r);
        t[v]=__gcd(t[2*v], t[2*v+1]);
    }
}

ll ask(int v, int tl, int tr, int l, int r)
{
    if(tr<l || tl>r || l>r) return 0;
    if(l==r) return t[v];
    if(tl>=l && tr<=r) return t[v];
    int mid=(tl+tr)/2;
    return __gcd( ask(2*v, tl, mid, l, min(r, mid)) , ask(2*v+1, mid+1, tr, max(l, mid+1), r) );
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        dif.clear();
        for(int i=0;i<n-1;i++)
            dif.pb(abs(a[i+1]-a[i]));
        build(1, 0, n-2);
        ll ans=1;
        for(int i=0;i<=n-2;i++)
        {
            int x=i, y=n-1;
            while(x<y)
            {
                int mid=(x+y)/2;
                if(ask(1, 0, n-2, i, mid)==1){y=mid;}else{x=mid+1;}
            }
            ans=max(ans,(ll)x-i+1);
        }
        cout<<ans<<endl;
    }

    return 0;
}
