#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("-O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define m_p make_pair
#define f first
#define s second
#define vec vector
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pw(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define fast_ioi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<long long,long long> pll;
template <class T> bool umin(T &a,const T &b){return (a>b?a=b,1:0);}
template <class T> bool umax(T &a,const T &b){return (a<b?a=b,1:0);}
auto rng=bind(uniform_int_distribution<int>(1,20),mt19937(time(0)));
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
template <class T> using oset=tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N=1e5+1;
const int K=19;
const int SQ=2*sqrt(N)+1;
ll dp[N][K];
ll phi[N];
ll suf[N][SQ];
int val[SQ];
int c1;
int sq[N];
int p[N];
int getid(int l,int r){
    int lw=(l<=r/(sq[r]+1)?l-1:r/(sq[r]+1)+sq[r]-(r/l));
    return lw;
}
ll calc(int l,int r){
    if(l>r) return 1e18;
    int i=getid(l,r)+1;
    int x=r/l;
    ll how=suf[r][i]+1ll*((r/x)-l+1)*(p[x]);
    return how;
}
void rec(int l,int r,int k,int x,int y){
    if(l>r) return;
    int tm=(l+r)>>1;
    int best=x;
//    debug()<<imie(dp[mid-1])
    for(int mid=x;mid<=min(tm,y);mid++){
//        debug()<<imie(mid)imie(dp[mid][k]+calc(mid+1,r));
        if(umin(dp[tm][k+1],dp[mid-1][k]+calc(mid,tm)))
            best=mid;
    }
    rec(l,tm-1,k,x,best);
    rec(tm+1,r,k,best,y);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<N;i++){
        phi[i]+=i;
        for(int j=2*i;j<N;j+=i) phi[j]-=phi[i];
        p[i]=p[i-1]+phi[i];
    }
    for(int i=1;i<N;i++){
        sq[i]=sqrt(i);
        c1=0;
        for(int j=1;j<=sq[i];j++){
            val[c1++]=i/j;
        }
        for(int j=i/(sq[i]+1);j>=1;j--){
            val[c1++]=j;
        }
        reverse(val,val+c1);
        for(int j=0;j<c1;j++){
            int x=i/val[j];
            int l=(j?val[j-1]+1:1),r=val[j];
//            debug()<<imie(i/r)imie(i/l);
//            assert(i/r==i/l);
            x=r-l+1;
            suf[i][j]=(1ll*x*p[i/val[j]]);
        }
//        cout<<endl;
        for(int j=c1-2;j>=0;j--) suf[i][j]+=suf[i][j+1];
    }
    for(int i=1;i<N;i++) dp[i][1]=calc(1,i);
//    return 0;
    dp[0][1]=1e18;
    for(int t=1;t<K-1;t++){
        for(int i=0;i<N;i++) dp[i][t+1]=1e18;
        rec(1,N-1,t,1,N-1);
//        for(int i=0;i<N;i++)
//            cout<<dp[i][t+1]<<' ';
//        cout<<endl;
    }
    while(t--){
        int n,k;
        cin>>n>>k;
        if(pw(k)>n){
            cout<<n<<'\n';
            continue;
        }
        else{
            cout<<dp[n][k]<<'\n';
        }
    }
    return 0;
}
/*
*/
