#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define umap unordered_map
#define uset unordered_set
#define forz(i, n) for (ll i = 0; i < n; i++)
#define fore(i, m, n) for (ll i = m; i <= n; i++)
#define forr(i, n, m) for (ll i = n; i >= m; i--)
#define itor(it,x) for(auto it=x.begin();it!=x.end();it++)
#define itor2(it,x) for(auto it=x->begin();it!=x->end();it++)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define deci(n) fixed << setprecision(n)
#define setbits(n) __builtin_popcountll(n)
#define zrobits(n) __builtin_ctzll(n)
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define gcd __gcd
#define raunak ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define pv(v) forz(qaz,v.size()) cout<<v[qaz]<<" "; cout<<endl;
#define pa(arr,n) forz(qaz,n) cout<<arr[qaz]<<" "; cout<<endl;

#define oset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll po(ll a,ll b,ll m){
    ll res=1;
    while(b>0){
        if(b&1) res=((res%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return res;
}
ll modi(ll a,ll m){
    return po(a,m-2,m);
}
ll lcm(ll a, ll b){ 
    return (a*b)/(gcd(a, b));
}

/////////////////////(^_^)/////////////////////(^_^)/////////////////////(^_^)/////////////////////
void bins(vector<ll>& a,ll l,ll r,ll& ans,ll x){
    if(l>r) return;
    ll m=(l+r)/2;
    if(a[m]<x){
        ans=m;
        bins(a,m+1,r,ans,x);
    }
    else bins(a,l,m-1,ans,x);
}
void bins2(vector<ll>& a,ll l,ll r,ll& ans,ll x){
    if(l>r) return;
    ll m=(l+r)/2;
    if(a[m]>x){
        ans=m;
        bins2(a,l,m-1,ans,x);        
    }
    else bins2(a,m+1,r,ans,x);
}
ll fun(map<ll,vector<ll>>& mx,map<ll,vector<ll>>& my,vector<ll>& x,vector<ll>& y,vector<ll>& ax,vector<ll>& ay){
    ll n=x.size();
    ll m=y.size();
    ll ans=0;
    itor(it,mx){
        vector<ll> v=it->S;
        forz(i,v.size()){
            if(my.count(v[i])) continue;
            ll y1=-1;
            ll y2=-1;
            bins(y,0,m-1,y1,v[i]);
            bins2(y,0,m-1,y2,v[i]);
            //p2(y1,y2);
            //pv(v);

            ll yy1=ay.size();
            ll yy2=-1;
            bins(ay,0,ay.size()-1,yy1,y2);
            bins2(ay,0,ay.size()-1,yy2,y1);
            ans+=yy2-yy1+1;

            yy1=v.size();
            yy2=-1;
            bins(v,0,v.size()-1,yy1,y2);
            bins2(v,0,v.size()-1,yy2,y1);
            ans-=yy2-yy1+1;
            p1(ans);
        }
    }
    return ans;

}
int main(){
    raunak;
    ll T=1;
    cin>>T;
    while(T--){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> x(n);
        vector<ll> y(m);
        map<ll,vector<ll>> mx;
        map<ll,vector<ll>> my;
        
        forz(i,n){
            ll t;
            cin>>t;
            x[i]=t;
            vector<ll> v;
            mx[t]=v;
        }
        forz(i,m){
            ll t;
            cin>>t;
            y[i]=t;
            vector<ll> v;
            my[t]=v;
        }
        sort(all(x));
        sort(all(y));

        vector<ll> ax;
        vector<ll> ay;
        
        forz(i,k){
            ll px,py;
            cin>>px>>py;
            if(mx.count(px)) mx[px].pb(py);
            if(my.count(py)) my[py].pb(px);
            ax.pb(px);
            ay.pb(py);
        }
        sort(all(ax));
        sort(all(ay));
        ll ans=fun(mx,my,x,y,ax,ay)+fun(my,mx,y,x,ay,ax);
        ans/=2;
        p1(ans);
    }
    return 0;
}