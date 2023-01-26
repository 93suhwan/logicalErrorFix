#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

// PBDS

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// iteration
#define fo(i, a, n) for (int i = a; i < n; i++)
#define fomp(it, a) for (auto it = a.begin(); it != a.end(); it++)

#define Interactive false

#if Interactive == false
#define endl "\n"
#endif

// Data-Types
typedef long long ll;
#define int ll
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;

//STL functions
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define range(v) v.begin(), v.end()
#define mem0(x) memset(x, 0, sizeof(x))
#define uniq(v) (v).erase(unique(range(v)), (v).end())

// constants
#define PI 3.1415926535897932384626
#define euler 2.7182818284590452353602874713527
#define PRIME 1'000'000'007
const int INF = 1e9;
const int mod = 1'000'000'007;
string ny[2] = {"NO", "YES"};
const int N = 5000006;

//Helper functions
inline int multi(int a, int b)
{
    return ((a * b) % mod);
}
inline int add(int a, int b)
{
    return (((a + b) % mod + mod) % mod);
}

vector<bool> isPrime(N + 1, true);
vector<int> spf(N);
vector<int> numPrimes(N);
vector<int> fact(N);
vector<int> invFact(N);
vector<int> primes;
int segtree[200005];
// Code samples

// 1. Take input for a pair<int, int> vector, one parameter at a time
//      for (auto &[x, y] : edges) {
//          cin >> x;
//      }
//      for (auto &[x, y] : edges) {
//          cin >> y;
//      }

// 2. Kamenetsky's formula for no. of digits in n!
//      f(x) = n * log10((n / e)) + log10(2 * PI * n) / 2;

void sieve()
{
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int d = i * i; d <= N; d += i)
            {
                isPrime[d] = 0;
            }
        }
    }
}

void primesList()
{
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

void processSPF()
{
    for (int i = 1; i < N; i++)
        spf[i] = i;
    for (int d = 2; d < N; d++)
    {
        if (isPrime[d])
        {
            for (int i = 2 * d; i < N; i += d)
            {
                isPrime[i] = false;
                spf[i] = min(spf[i], d);
            }
        }
    }
}

void processNumPrimes()
{
    for (int i = 1; i < N; i++)
    {
        int num = i;
        while (num != 1)
        {
            numPrimes[i]++;
            num = num / spf[num];
        }
    }
}

int fast_pw(int x, int y)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }

        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int moduloInverse(int x)
{
    return fast_pw(x, mod - 2);
}

void processFact()
{
    int p = PRIME;
    fact[0] = 1;
    int i;
    for (i = 1; i < N; i++)
    {
        fact[i] = (i * fact[i - 1]) % p;
    }
    i--;
    invFact[i] = fast_pw(fact[i], p - 2);
    for (i--; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % p;
    }
}

int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return ((fact[n] * invFact[r]) % PRIME * invFact[n - r]) % PRIME;
}

// Euler Totient Function

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1)
    {
        result -= result / n;
    }
    return result;
}

bool sortBySec(const pii &a, const pii &b)
{
    return (a.second > b.second);
}

int stringToInt(string s)
{
    int num = 0;
    int n = s.size();
    bool neg = false;
    int beg = 0;
    if (s[0] == '-')
    {
        neg = true;
        beg = 1;
    }
    for (int i = beg; i < n; i++)
    {
        num = num * 10 + (int(s[i]) - 48);
    }
    if (neg)
    {
        num *= -1;
    }
    return num;
}

void buildSegtree(vector<int> arr)
{
    int n = arr.size();
    fo(i, 0, n)
    {
        segtree[n + i] = arr[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        // change for other operations
        segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
    }
}

int querySegtree(int l, int r, int n)
{
    l += n;
    r += n;
    int res = 0;
    while (l <= r)
    {
        if (l & 1)
        {
            res += segtree[l];
            l++;
        }
        if (!(r & 1))
        {
            res += segtree[r];
            r--;
        }
        l = l >> 1;
        r = r >> 1;
    }
    return res;
}

void updateSegtree(int in, int n, int value)
{
    in += n;
    segtree[in] = value;
    while (in > 1)
    {
        in = in >> 1;
        segtree[in] = segtree[in * 2] + segtree[2 * in + 1];
    }
}

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

/*
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return ((fact[n] * invFact[r]) % PRIME * invFact[n - r]) % PRIME;
}
*/

bool hasTestCases = true;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 0 || k == 1)
    {
        cout << ny[0] << endl;
        return;
    }
    if (k == 2)
    {
        if (m == 0)
        {
            cout << ny[1] << endl;
        }
        else
        {
            cout << ny[0] << endl;
        }
        return;
    }
    int d = (k - 2);
    int maxm = (n * (n - 1)) / 2;
    int minm = n - 1;
    if (m > maxm || m < minm)
    {
        cout << ny[0] << endl;
        return;
    }
    if (d == 1)
    {
        if (m == maxm)
        {
            cout << ny[1] << endl;
        }
        else
        {
            cout << ny[0] << endl;
        }
        return;
    }
    else
    {
        cout << ny[1] << endl;
    }
}

signed main()
{
    if (Interactive == false)
    {
        ios_base::sync_with_stdio(false);
        std::cout.tie(0);
        cin.tie(0);
    }
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    // sieve();
    // primesList();
    // processFact();
    // processSPF();
    // processNumPrimes();
    int t = 1;
    if (hasTestCases)
        cin >> t;
    while (t--)
    {
        solve();
    }
}