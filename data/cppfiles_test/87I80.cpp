  /*EKeshwar JHoDE*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define M                1000000007
#define ff               first
#define ss               second
#define lup(i,a,b)       for(ll i=a;i<=b;i++)
#define lupp(i,a,b)      for(ll i=b;i>=a;i--)
#define vi               vector<ll>
#define g1(a,b)          __gcd(a,b)
#define bp(a)            __builtin_popcountll(a)
#define mp               make_pair
#define pb               push_back
#define vp               vector<pair<ll,ll> >
#define pr               pair<ll,ll>
#define ix               INT_MAX
#define in               INT_MIN
#define inf              1e18
#define st               string
#define se               set<ll>
#define vec              vector<vector<ll> >
#define all(a)           a.begin(),a.end()
#define so(a,n)          sort(a,a+n)
#define so1(a,n)         sort(a,a+n,greater<ll>())
#define mn(a,b,c)        min(a,min(b,c))
#define mx(a,b,c)        max(a,max(b,c))
#define sp(x)            fixed<<setprecision(x)
#define pq               priority_queue<ll>
#define pq1              priority_queue<ll,vi,greater<ll>>
#define mie(a,n)         *min_element(a,a+n)
#define mix(a,n)         *max_element(a,a+n)
#define pi               M_PI
#define ld               long double
#define sz(x)            (ll)x.size()
#define o_set            tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
ll c_p(ll a,ll n){
    ll ans=1;
    a%=M;
    if(a==0){
        return a;
    }
    while(n>0){
        if(n&1){
            ans=(ans*a)%M;
        }
        n=n>>1;
        a=(a*a)%M;
    }
    return ans;
}
void sieve_b(ll *b,ll max1){
    for(ll i=3;i<=max1;i+=2){
        b[i]=1;
    }
    for(ll i=3;i<=max1;i+=2){
        if(b[i]==1){
            for(ll j=i*i;j<=max1;j+=i){
                b[j]=0;
            }
        }
    }
    b[0]=b[1]=0;
    b[2]=1;
}
bool compare(const pair<ll,st>& x, const pair<ll,st>& y ){

    return (x.ff>y.ff);

}
ll mod_add(ll a,ll b){
    ll ans;
    ans=((a%M) + (b%M))%M;
    return (ans%M);
}
ll mod_m(ll a,ll b){
    ll ans;
    ans=((a%M)*(b%M))%M;
    return (ans%M);
}
ll mod_s(ll a,ll b){
    ll ans;
    ans=((a%M)-(b%M)+M)%M;
    return ans;
}
ll fun(ll x){
    return c_p(x,M-2);
}
bool dec_check(ld a,ld b){
    ll a1=1e-9;
    if(abs(a-b)<a1){
        return true;
    }
    return false;
}
ll count_d(ll n){
    ll c = 0;
    for(ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if(n / i == i){
                c++;
            }
            else{
                c+=2;
            }
        }
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*ll max1=2000000;
    ll b[max1]{0};
    sieve_b(b,max1);
    vi v;
    lup(i,0,max1){
        if(b[i]==1){
            v.push_back(i);
        }
    }*/
    // cout<<v.size()<<'\n';
    /*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
    ll t;
    t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        lup(i,0,n-1){
            cin>>a[i];
        }
        ll ans=0;
        vi a1;
        lup(i,0,n-1){
            if(i==0 && a[i]>i+1){
                ans+=(a[i]-1);
                a[i]=max((i+1),a[i]);
            }
            else if(a[i]>(i+1)){
                ans+=(a[i]-(a[i-1]+1));
                a[i]=max((i+1),a[i]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}




























