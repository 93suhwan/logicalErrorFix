//clear adj and visited vector declared globally after each test case
//check for long long overflow   
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Incase of close mle change language to c++17 or c++14  
#include <bits/stdc++.h>         
#include <ext/pb_ds/assoc_container.hpp>  
// #define int long long       
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back 
#define mod 998244353ll
#define lld long double
#define mii map<int, int> 
#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
const long long N=200005, INF=2000000000000000000;
lld pi=3.1415926535897932;
int lcm(int a, int b)
{
    int g=__gcd(a, b);
    return a/g*b;
}
int power(int a, int b, int p)
    {
        if(a==0)
        return 0;
        int res=1;
        a%=p;
        while(b>0)
        {
            if(b&1)
            res=(res*a)%p;
            b>>=1;
            a=(a*a)%p;
        }
        return res;
    }
const int MOD=mod;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    // friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};
Mint st[4*N];
pair <Mint, Mint> lazy[4*N];
int a[N];
Mint lazy2[4*N];
vector <int> v;
void propogate(int node, int l, int r)
{
    st[node]*=lazy[node].ff;
    st[node]+=(lazy[node].ss*(v[r]-v[l-1]));
    if(l!=r){
        lazy[2*node].ss*=lazy[node].ff;
        lazy[2*node].ff*=lazy[node].ff;
        lazy[2*node].ss+=lazy[node].ss;
        lazy[2*node+1].ss*=lazy[node].ff;
        lazy[2*node+1].ff*=lazy[node].ff;
        lazy[2*node+1].ss+=lazy[node].ss;
    }
    lazy[node]={1, 0};
}
void build(int node, int l, int r)
{
    if(l==r)
    {
        // if((int)v[l]<=(int)a[1])
        st[node]=0;
        lazy[node]={1, 0};
        return;
    }
    int mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    st[node]=(st[node*2]+st[node*2+1]);
    lazy[node]={1, 0};
    return;
}
void update(int node, int l, int r, int x, int y, pair<Mint, Mint> p)
{
    propogate(node, l, r);
    if(y<x||x>r||y<l)
    return;
    int mid=(l+r)/2;
    if(l>=x&&r<=y)
    {
        lazy[node]=p;
        propogate(node, l, r);
        return;
    }
    update(node*2, l, mid, x, y, p);
    update(node*2+1, mid+1, r, x, y, p);
    st[node]=(st[node*2]+st[node*2+1]);
    return;
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    set <int> s;
    rep(i,1,n+1)
    {
        // a[i]=getRand(1, 1e9);
        // cin>>a[i];
        a[i]=1;
        s.insert(a[i]);
    }
    // return 0;
    int x=1;
    mii mp;
    v.pb(0);
    for(auto it:s)
    {
        mp[it]=x++;
        v.pb(it);
    }
    x--;
    build(1, 1, x);
    update(1, 1, x, 1, mp[a[1]], {1, 1});
    rep(i,2,n+1)
    {
        propogate(1, 1, x);
        Mint base=st[1];
        // cout<<base<<" ";
        int pos=mp[a[i]];
        // cout<<query(1, 1, x, 1, x)<<" ";
        update(1, 1, x, 1, x, {mod-1, base});
        // cout<<query(1, 1, x, 1, x)<<" ";
        if(pos!=x)
        update(1, 1, x, pos+1, x, {0, 0});
        // cout<<query(1, 1, x, 1, x)<<"\n";
        // rep(j,1,x+1)
        // cout<<query(1, 1, x, j, j)<<" ";cout<<"\n";
        // update2(1, 1, 2, 1, 2, 100);
        // cout<<query(1, 1, x, 1, x)<<"\n";
    }
    propogate(1, 1, x);
    cout<<st[1];
}
