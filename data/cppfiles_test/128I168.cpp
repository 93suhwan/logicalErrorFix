/* AdityaChaudhary */


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;


void print(int x) { cerr << x; }
void print(long x) { cerr << x; }
void print(long long x) { cerr << x; }
void print(unsigned x) { cerr << x; }
void print(unsigned long x) { cerr << x; }
void print(unsigned long long x) { cerr << x; }
void print(float x) { cerr << x; }
void print(double x) { cerr << x; }
void print(long double x) { cerr << x; }
void print(char x) { cerr << '\'' << x << '\''; }
void print(const char* x) { cerr << '\"' << x << '\"'; }
void print(const string& x) { cerr << '\"' << x << '\"'; }
void print(bool x) { cerr << (x ? "true" : "false"); }

#define ok order_of_key
#define fbo find_by_order 
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define sz size
#define ll long long int 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define iv(a,n) for(ll i=0;i<n;i++)cin>>a[i];
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<ll>      vl;
typedef vector<string>  vs;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
typedef map<ll, ll>      ml;
typedef map<ll, vl>      mvl;
typedef map<char, ll>    mcl;
typedef multimap<ll, ll> mml;

const int mod = 1e9 + 7;
const int mod2 = 998244353;
const long long inf = 1e18;
const long double PI = 3.141592653589793;

int vis[200005];
int dis[200005];
int col[200005];
vl ad[200005];
queue<int> q;
vi primes;
ll N, M;


/***********************************************************************************************/

int fact(int n)
{
    int res = 1;
    for (int i = n;i >= 1;i--)
        (res *= i) %= mod;
    return (res % mod);

}

long long maxsubarraysum(vl array, long long n) {
    long long best = -mod, sum = 0;
    for (long long k = 0; k < n; k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    return  best;

}

ll gcd(ll a, ll b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}


bool isPrime(int n)
{
    // Corner cases 
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void sieve(ll m)
{
    bool ar[m + 1] = { false };
    int maxN = m;
    ar[0] = true;
    ar[1] = true;

    for (int i = 2;i * i <= maxN;i++)
    {
        if (!ar[i])
        {
            for (int j = i * i;j <= maxN;j += i)
                ar[j] = true;
        }
    }

    for (int i = 2;i <= maxN;i++)
        if (!ar[i])
            primes.pb(i);

}

//THIS IS THE CODE TO FIND ALL PRIME NUMBERS IN THE RANGE "L" to "R";

vector<long long > segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    vector<long long >realprime;
    for (int i = 0;i <= R - L;i++) {
        if (isPrime[i]) {
            realprime.emplace_back(i + L);

        }
    }
    return realprime;

}

struct CMP {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        if (lena == lenb) return a.first < b.first;
        return lena > lenb;
    }
};

/***********************************************************************************************/

int par[200005];
int findset(int v) {
    if (v == par[v])
        return v;
    return findset(par[v]);
}

void merge(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a != b) {
        par[b] = a;
    }
}


bool isValid(int x, int y)
{
    if (x<1 || x>N || y<1 || y>M)
        return false;

    return true;
}

void dfs(int x)
{
    vis[x] = 1;

    for (auto i : ad[x]) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    return;
}


void bfs(ll src)
{
    q.push(src);
    dis[src] = 0;
    vis[src] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int node : ad[curr])
            if (vis[node] == 0)
            {
                dis[node] = dis[curr] + 1;
                vis[node] = 1;
                q.push(node);
            }
    }
}

void readG()
{
    rep(i, 0, M)
    {
        ll x, y;
        cin >> x >> y;
        ad[x].pb(y);
        ad[y].pb(x);
    }
}

/************************************************************************************************/

ll binarySearch(vl& arr, ll l, ll r, ll x)
{
    while (l <= r)
    {
        ll m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}


unsigned long long power(unsigned long long x, ll y, ll p)
{
    unsigned long long res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n, ll p)
{
    return power(n, p - 2, p);
}

unsigned long long nCr(unsigned ll n, ll r, ll p)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

unsigned long long nPr(unsigned ll n, ll r, ll p)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[n - r], p) % p) % p;
}


/***************************************************************************************************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // cout<<fixed<<setprecision(9);

    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        ll n = 0, m = 0, i = 0, j = 0, k = 0, cnt = 0, ans = 0, sum = 0, flag = 0, pos = -1, ind = -1, mn = inf, mx = -inf, res = 0;
        string s,t;
        
        cin>>n;
        
        if(n%2)
        {
            m=n-1;
            m/=2;
            if(m%2==0)
            cout<<1<<" "<<m-1<<" "<<m+1<<endl;
            else
            cout<<1<<" "<<m-2<<" "<<m+2<<endl;
            
        }
        else
        {
            cout<<1<<" "<<(n/2)-1<<" "<<(n/2)<<endl;
        }
        


    }

    return 0;

}

