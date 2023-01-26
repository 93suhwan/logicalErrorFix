#define    ll                long long
#define    dn                double
#define    mp                make_pair
#define    pb                push_back
#define    se                second
#define    fi                first
#define    mod               1000000007
#define    sob(v)            v.begin(),v.end()
#define    sobr(v)           v.rbegin(),v.rend()
#define    same(v)           v.erase(unique(v.begin(),v.end()),v.end())
#define    fr(i,a,b)         for(int i=a;i<=b;++i)
#define    frr(i,a,b)        for(int i=a;i>=b;--i)
#define    pi                acos(-1.00)
#define    inf               1e9
#define    EPS               1e-9
#define    sf(n)             scanf("%d",&n)
#define    sfl(n)            scanf("%lld",&n)
#define    check(n)          cout<<n<<"**CHECK"<<endl
#define    ffix(x)           cout<<fixed<<setprecision(x)
#define    fast              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    ones(mask)        __builtin_popcount(mask)   // count set bit
#define    onesLL(mask)      __builtin_popcountll(mask) // for long long
#define    lzeros(mask)      __builtin_clz(mask)        // no of leading zeros
#define    tzeros(mask)      __builtin_ctz(mask)        // no of trailing zeros


#include<bits/stdc++.h>
#include<string.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<int,vi> pp;
typedef vector<pii> vpii;
typedef pair<pair<int,int>,int> pain;
typedef tree<string,null_type,less<string>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
///X.order_of_key(x)=the number of items in a set that are strictly smaller than x
///*X.find_by_order(k)=returns an iterator to the k-th largest element (counting from zero)

int dr[8]= {-1,0,+1,0,-1,-1,+1,+1};
int dc[8]= {0,+1,0,-1,-1,+1,-1,+1};

int kx[8]= {-1,+1,+1,-1,+2,+2,-2,-2};
int ky[8]= {+2,+2,-2,-2,-1,+1,+1,-1};

const int N=100005;

void solve()
{
    int n;
    ll h;
    sf(n);
    sfl(h);
    ll a[n+1];
    vector<ll>vec;
    fr(i,1,n)sfl(a[i]);
    fr(i,2,n)
    {
        ll x=a[i]-1-a[i-1]+1;
        vec.pb(x);
    }
    ll mx=1e18;
    vec.pb(mx-a[n]+1);
    ///for(auto i:vec)cout<<i<<' ';cout<<endl;
    ll l=1,r=1e18,ans=0;
    while(l<r)
    {
        ll mid=(r-l)/2LL+l;
        ll sum=0;
        for(auto i:vec)
        {
            sum+=min(i,mid);
        }
        if(sum>=h)r=mid-1,ans=mid;
        else l=mid+1;
    }
    ///cout<<l<<' '<<r<<endl;
    for(ll i=r;i>=l;--i)
    {
        ll sum=0;
        for(auto j:vec)
        {
            sum+=min(i,j);
        }
        if(sum>=h)ans=i;
    }
    printf("%lld\n",ans);
}

int main()
{
    int t;
    sf(t);
    while(t--)solve();
}
