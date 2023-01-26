#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
long long binpow(long long a, long long b);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================SUBHADEEP DAS======================//

//vi g[N];
//int a[N];
//int m = unique(s.begin(), s.end()) - s.begin(); calculate blocks of consecutive same elements
  // Like 100111 --- 1, 00, 111 so m=3.

/*bool prime(ll n)
{
  ll c=0;
  for(ll i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}*/
/*ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}*/
/*ll binsearch(vector<ll>&v , ll l, ll r, ll x)
{
  if(l<=r)
  {
    ll mid= l+(r-l)/2;
    if(x>v[mid])
     return binsearch(v,mid+1,r,x);
    else if(x<v[mid])
     return binsearch(v,l,mid-1,x);
    else
      return mid;
  }
  return -1;
}*/
/*ll binomialCoeff(ll n, ll k)
{
    ll res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i) {
        res *= (n - i)%mod;
        res /= (i + 1)%mod;
    }
    return res%mod;
}*/
/*void initfact() {
    fact[0] = 1;
    for(ll i = 1; i < N; i++) {
        fact[i] = (fact[i-1] * i);
        fact[i] %= mod;
    }
}*/
/*void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}*/
/*ll nCr(ll n, ll r) //if n is very large or n>>>r
{
  ll num =fact[n];
  ll den = fact[n-r]*fact[r];
  den%= mod;
  den= mpow(den,mod-2);
  return (num*den)%mod;
}*/
/*ll logf(ll k, ll l)
{
  if(l==1)
    return 0;
  ll c=0;
  while(l>1)
  {
   l/=k;
   c++;
  }
  return c;
}*/
/*ll findGCD(vl &arr)// Gcd of n nos
{
    ll result = arr[0];
    for (ll i = 1; i < arr.size(); i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}*/
void solve() {
  ll a,b,c,m;
  cin>>a>>b>>c>>m;
  ll ans= a+b+c-3;
  if(ans>=m)
  cout<<"YES"<<"\n";
  else
  cout<<"NO"<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
/*void ipgraph(int n, int m)
{
    int i, u, v;
    while(m--)
  {
        cin>>u>>v;
    u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}*/

/*void dfs(int u, int par)
{
    for(int v:g[u])
  {
        if (v == par) continue;
        dfs(v, u);
    }
}*/
