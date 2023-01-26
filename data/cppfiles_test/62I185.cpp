    // "It does not matter how slowly you go as long as you do not stop." - Confucius
#include <bits/stdc++.h>

using namespace std;

/*
author : Roshan_Mehta
motto : Time Management,Consistency,Patience!!
*/

#define int long long

template<typename T>
void __print(const T &t);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local_Debug
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


#define M1 1000000007
#define M2 998244353
#define G(a,b) get<a>(b)
#define ll long long
#define pb push_back
#define mt make_tuple
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rsort(x) sort(x,greater<int> ())
#define rall(x) rbegin(x), rend(x) //useful in sorting
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
// #define gcd __gcd
#define lcm(a,b) (a*b)/gcd(a,b)
#define deci(n) fixed << setprecision(n)
#define test() int test_case;cin >> test_case;while (test_case--)
#define loop(i,a,n) for(int i=a;i<n;i++)
#define sp " "
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define clz(x) __builtin_clz(x)
#define clzll(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctz(x)
#define ctzll(x) __builtin_ctzll(x)
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<int,pi> tri;
typedef pair<pi,int> rtri;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umii;
typedef map<int,int> mii;
typedef set<int> si;
#define input(n,k) int n,k;cin>>n;cin>>k;vi arr(n,0);loop(i,0,n){cin>>arr[i];}
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

const int MOD = 1e9 + 7;
int md=MOD;

int Power(int n, int x) {int ans = 1;while (x > 0) {if (x & 1) ans = (ans * n) % md;
n = (n * n) % md;x = x >> 1;}return ans;}

vl fact, inv;

void inverse(ll n)
{if(n>=inv.size()){ll size=inv.size();size=size==0? 1:size;
inv.resize(n + 1);inv[0] = 1;
for (ll i = size; i <= n; i++)inv[i] = Power(fact[i], md - 2);}}

void factorial(ll n)
{if(n>=fact.size()){ll size=fact.size();size=size==0? 1:size;
fact.resize(n + 1);fact[0] = 1;for (ll i = size; i <= n; i++)
fact[i] = (fact[i - 1] * i) % md;
}}

ll ncr(ll n, ll r) { return (((fact[n] * inv[r]) % md) * inv[n - r]) % md; }

vl SieveOfEratosthenes(int n)
{
bool prime[n+1];
memset(prime, true, sizeof(prime));
for (int p=2; p*p<=n; p++)
{if (prime[p] == true){for (int i=p*p; i<=n; i += p)
prime[i] = false;}}

vl ans;for (int p=2; p<=n; p++)if (prime[p])ans.pb(p);return ans;
}
vi primeFactors(int n)
{
vi ans;
while (n % 2 == 0) {ans.pb(2);n = n / 2;}
for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {ans.pb(i);n = n / i;}}
if (n > 2)ans.pb(n);return ans;
}
// bool isprime(ll n)
// {
//     if(n<2)
//         return false;
//     for(ll x:{2,3,5,7,11,13,17,19,23,29,31,37})
//     {
//         if(n==x)
//             return true;
//         bool flag=true;
//         ll r=1;
//         ll t=1;
//         while(r<=((n-1)>>__builtin_ctzll(n-1)))
//         {
//             if(r&((n-1)>>__builtin_ctzll(n-1)))
//                 t=((__int128)t*x)%n;
//             x=((__int128)x*x)%n;
//             r<<=1;
//         }
//         if(t==1||t==n-1)
//             flag=false;
//         for(r=0;r<__builtin_ctzll(n-1);r++)
//         {
//             t=((__int128)t*t)%n;
//             if(t==n-1)
//                 flag=false;
//         }
//         if(flag)
//             return false;
//     }
//     return true;
// }

ll NcR(int n, int r)
{long long p = 1, k = 1;if (n - r < r)r = n - r;if (r != 0) {while (r) {p *= n;k *= r;
long long m = gcd(p, k);p /= m;k /= m;n--;r--;}
}else p = 1;return p;// cout << p << endl;
}
bool sortasc(const rtri a,const rtri b) //Ascending ... change the argument accordingwise;
{
return a.second<b.second;
}
bool sortdesc(const int a,const int b) //Descending... change the argument accordingwise;a
{
return a>b;
}
int myceil(int num,int den)
{
if ((num >= 0 and den > 0) or ( num <= 0 and den < 0))
    return num%den == 0 ? num/den : num/den + 1;
return num / den;
}
int myfloor(int num,int den)
{
if ((num >= 0 and den > 0) or ( num <= 0 and den < 0))
    return num%den == 0 ? num/den : num/den;
int ans = num / den;
return num % den == 0 ? ans : ans - 1;
}
int midofthree(int a,int b,int c)
{
if((a<=b and a>=c) or (a<=c and a>=b))
    return a;
else if((b>=a and b<=c) or (b<=a and b>=c))
    return b;
return c;
}
ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;m=a%m;a=t;t=y;y=x-q*y;x=t;
    }
    if(x<0) x+=m0;
    return x;
}
string to_string(char c) {
return string(1, c);
}
clock_t startTime;
double getCurrentTime() {
return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  //From Umnik Template
using ull = unsigned long long;
struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};
//use like this : unordered_map<long long, int, customhash> safemap;

ll myRand(ll B) {
return (ull)rng() % B;
}

// reinitialize value of md(example md = M1 or md=M2);
ll add(ll x, ll y) {
x %= md;
y %= md;
x += y;
if (x >= md) return x - md;
return x;
}
ll sub(ll x, ll y) {
x %= md;
y %= md;
x -= y;
if (x < 0) return x + md;
return x;
}
ll mult(ll x, ll y) {
x %= md;
y %= md;
return (x * y) % md;
}
ll bin_pow(ll x, ll p) {
if (p == 0) return 1;
if (p & 1) return mult(x, bin_pow(x, p - 1));
return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
return bin_pow(x, md - 2);
}

void q1();void q2();void q3();void q4();void q5();
#define pie 3.141592653589793238462643383279

int testCase = 0;
void giveOutput(){
testCase++;
cout << "Case #" << testCase << ": ";   
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
if (start < 0) start = 0;
if (end < 0) end = (int)(v.size());

for (int i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

//********************THE END OF`` TEMPLATES*******************//

const int maxN = 2e5 + 5;


void run_testcase(){
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //Start with special node
    if (arr[0] == 1) {
        cout << n + 1 << " ";
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
        return;
        
    }
    //End with special node
    if (arr[n - 1] == 0) {
        for (int i = 0; i < n + 1; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
        return;
        
    }
    //Can't start or end with special node
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0 and arr[i + 1] == 1) {
            for (int j = 0; j < i; j++)
            {
                cout << j + 1 << " ";
            }
            cout << n + 1 << " ";
            for (int j = i; j < n; j++)
            {
                cout << j + 1 << " ";
            }
            cout << endl;
            return;
            
            
        }
    }
    cout << -1 << endl;
    return;
    
    
    
}


int32_t main()
{
startTime = clock();
fast();
#ifdef Local_Debug
freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
test()
{
    run_testcase();
    // q2();
}

return 0;
}

