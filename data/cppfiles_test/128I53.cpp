

/*
   AUTHOR 
    
    Mr. PANKAJ GOYAL 
    Coding Lover 
    codechef   : pankaj_2407
    codeforces : pankaj_2407
    
                     */
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll, ll> umll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<ll> sl;
typedef unordered_set<ll> usl;
typedef multiset<ll> ml;

#define      unsigned long long int ull
#define      fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      F first
#define      S second
#define      f(i,n)             for (int i = 0; i < n; i++)
#define      fr(i,n)            for(int i=(int)n-1;i>=0;--i)
#define      fo(i,a,b)          for(ll i=(ll)a;i<=(ll)b;i++)
#define      pb                 push_back
#define      mp                 make_pair
#define      sz(x)              (ll)((x).size())
#define      ub                 upper_bound
#define      lb                 lower_bound
#define      I                  insert
#define      mem1(a)            memset(a,-1,sizeof(a))
#define      mem0(a)            memset(a,0,sizeof(a))
#define      pri_que_down       priority_queue<ll>
#define      pri_que_up         priority_queue<ll, vector<ll>, greater<ll> >
#define      fix(x)             fixed<<setprecision(x)
#define      P(x)               cout << x << "\n"
#define      R(x)               cin >> x
#define      nl                 cout << '\n'
#define      fill(a, b)         memset(a, b, sizeof(a))
#define      setbits(x)         __builtin_popcountll(x)

#define      display(v) for(int i =0;i<(int)v.size();++i)cout << v[i] << " "
#define      all(v) v.begin(),v.end()
#define      rall(v) v.rbegin(),v.rend()
#define      read(a) for(int i = 0;i<sz(a);++i)cin>>a[i]
#define       inf  4e18;

const int mod = 1e9 + 7;
const double PI = 3.1415926535897932384626;

const int nax = 300*1000 + 10;
ll fac[nax];
ll mod_inv[nax];


inline ll add(ll a, ll b){ ll c = (a%mod) + (b%mod); if(c >= mod) c -= mod; return c; }
inline ll mul(ll a, ll b){ return ((a%mod) * 1ll * (b%mod)) % mod; }
inline ll sub(ll a, ll b){ int c = (a%mod) - (b%mod); if(c < 0) c += mod; return c; }
inline ll gcd(ll a,ll b){return __gcd(a,b);}
inline ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
inline void ANS(bool a) { if(a) cout<<"YES\n"; else cout<<"NO\n";}
inline void Ans(bool a) { if(a) cout<<"Yes\n"; else cout<<"No\n";}
inline void ans(ll a) {cout<<a<<"\n";}

// ---------------------------------------*******************--------------------------------------//
vl prefix_sum(vl &a){
    vl b(sz(a));
    partial_sum(all(a),b.begin());
    return b;
}
ll total_sum(vl &v){
   return  accumulate(all(v),0);
}
ll power(ll x,ll y) 
{ 
    ll res = 1;
    x=x%mod;  
    while(y>0) 
    { 
        if (y&1) res=(res*x)%mod;
        y=y>>1; 
        x=(x*x)%mod; 
    } 
    return res; 
} 
void pre(){
    fac[0] = fac[1] = 1;
    for(int i = 2;i<nax;++i){
        fac[i] = mul(i , fac[i-1]);
    } 
    mod_inv[0] = mod_inv[1] = 1;
    for(int i =2;i<nax;++i){
        mod_inv[i] = power(fac[i] , mod - 2);
    }
 
}
ll ncr(ll n, ll r)
{
    if(r > n)return 0LL;
    ll ans = mul(fac[n] , mod_inv[r]);
    ans = mul(ans , mod_inv[n-r]);
    return ans;
}

ll str_to_int(string s)
{
    stringstream geek(s); 
    ll x=0; 
    geek>>x; 
    return x;
}
string int_to_str(ll n)
{
    return to_string(n);
}


ll HCF_of_vl(vl &A)
{
    ll i,a=A[0];
     fo(i,1,A.size()) a=gcd(a,A[i]);
    return a;
}

ll LCM_of_vl(vl &A)
{
    ll i,a=A[0];
    fo(i,1,A.size()) a=lcm(a,A[i]);
     return a;
}


map<ll,ll> count_freq_vl(vl &A)
{
    map<ll,ll>result;
    ll i,n=A.size();
    f(i,n)  result[A[i]]++;
    return result;
}


void factorize(ll n) 
{ 
	ll i,count = 0; 
	while (!(n % 2)) { 
		n >>= 1; 
		count++; 
	} 
	if (count)  cout<<"2 : "<<count<<"\n";
	for (i=3; i<=sqrt(n);i+= 2) { 
		count=0; 
		while(n%i == 0){ 
			count++; 
			n=n/i; 
		} 
		if (count) 
		cout<<i<<" : "<<count<<"\n";
	} 
	if (n>2) 
	cout<<n<<" : 1"<<"\n";
} 
void Prime(ll n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}
vl count_bits_vl(vl &v,ll x)
{
     vl counts(x,0);
    for(ll i=0;i<x;i++)
    {
        for(ll j=0;j<sz(v);j++) if((1ll<<i)&v[j]) counts[i]++;
    }
    return counts;
}
vl make_fact_vl(ll n)
{
     vl fact; fact.pb(1);
    for(ll i=1;i<=n;i++) fact.pb(mul(i,fact[i-1]));
    return fact;
}
void fib(ll n)
{
    vl f;
    f.pb(1);f.pb(1);f.pb(2);
    for(ll i=3; i<n; i++)
     f.pb((f[i-1]%mod+f[i-2]%mod)%mod);
}
ll mod_inverse(ll n)
{
    return power(n,mod-2);
}
bool isPrime(ll n)
{
    if (n<2)  return 0;
    if (n<4) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
  
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}
 
/* ---------------------------------------*******************--------------------------------------
                                ll prefix_sum(vl &v)
                                ll total_sum(vl &v)
                                void pre() --> for fact and mod_inv arrays
                                ll power(ll a,ll b)ll fact(ll n)    
                                ll ncr(ll n, ll r)
                                ll str_to_int(string s)
                                string int_to_str(ll n)
                                ll HCF_of_vl(vl &A)
                                ll LCM_of_vl(vl &A)
                                map<ll,ll> count_freq_vl(vl &A)
                                void factorize(ll n)
                                void Prime(int n)
                                vl count_bits_vl(vl &v)
                                vl make_fact_vl(ll n)
                                void fib(ll n)
                                ll mod_inverse(ll n)
                                bool isPrime(ll n)
 *****----------------------------------*******************--------------------------------------*/

void testcase()
{   
  ll n,a=2; cin>>n;
  while(a){
      if(__gcd(n-a-1,a)==1 && a!= n-a-1){
          cout<<"1 "<<a<<" "<<n-a-1<<"\n";
          return;
      } 
      a++;
  }
}
 


// ---------------------------------------*******************--------------------------------------//

void solve()
{
     ll t=1;
     cin>>t;
      while(t--)
      {
          testcase();
      }
}

signed main()
{
   fast;
    
  //  pre();
    solve();
    return 0;
}


