#include"bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                first
#define ss                second
#define MM                998244353
#define int               long long
#define pb                push_back
#define pf                push_front
#define ps(x,y)           fixed<<setprecision(y)<<x
#define w(x)              int x; cin>>x; while(x--)
#define FOR(i,a,b)        for(int i=(a);i<(b);i++)
#define ROF(i,a,b)        for(int i=(a);i>=(b);i--)
#define so(a,n)           sort(a,a+n)
#define rso(a,n)          sort(a,a+n),reverse(a,a+n)
#define all(v)            (v).begin(),(v).end()
#define ps(x,y)           fixed<<setprecision(y)<<x
const int                 maxn = 2e5 + 10;
const int                 modulo = 1000000007;
#define mod               1000000007;
const double              pi = 3.141592653589;
#pragma optimize(Ofast)
#define vv vector<vector<int>>
#define vi vector<int>
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;
//in multiset lower_bound and upper_bound works as vice versa
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;
//cout << X.find_by_order(1)->ss; // in pair<int,int> gives 1 index second value
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
//check n==1 and base cases//
//********************************---------always check array boundness-----------****************
//factorial ncr
int printNcR(int n, int r)
{
    if (n < r)return 0;
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else p = 1;
    return p;
}
// void c_p_c()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r+", stdin);
//     freopen("output.txt", "w+", stdout);
// #endif
// }
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}


// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
// const int N = 1e4 + 5;
// int dp[N];
// bool prime[N];
// std::vector<int> v;


// bool prime[N];
// void precompute()
// {
//  memset(prime , 1, sizeof(prime));
//  prime[0] = 0;
//  prime[1] = 0;
//  for (int i = 2; i * i <= N; i++)
//  {
//      if (prime[i] == 1)
//          for (int j = i * i; j <= N; j += i )prime[j] = 0;
//  }
// }
// #**************************************************
// const int MAX_SIZE = 1000006;
// void SieveOfEratosthenes(vector<int>& primes)
// {
//     bool IsPrime[MAX_SIZE];
//     memset(IsPrime, true, sizeof(IsPrime));

//     for (int p = 2; p * p < MAX_SIZE; p++) {
//         if (IsPrime[p] == true) {
//             for (int i = p * p; i < MAX_SIZE; i += p)
//                 IsPrime[i] = false;
//         }
//     }

//     // Store all prime numbers
//     for (int p = 2; p < MAX_SIZE; p++)
//         if (IsPrime[p])
//             primes.push_back(p);
// }
//*********************************************
// generating subsets..
// for ( int i = 0 ; i < ( 1 << m ) ; ++ i )
// {
//  for ( int j = 0; j < m ; ++ j )
//  {
//      if ( ( i & ( 1 << j ) ) != 0)
//      {

//      }
//  }
// }
// int msb(unsigned a) {
//  return __lg(a ^ (a & (a - 1)));
// }
//*********************************************
const int NN = 1000006;
std::vector<int>primes;
bool IsPrime[NN];
void SieveOfEratosthenes()
{

    memset(IsPrime, true, sizeof(IsPrime));
    IsPrime[1] = false;
    IsPrime[0] = false;
    for (int p = 2; p * p < NN; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < NN; i += p)
                IsPrime[i] = false;
        }
    }
    // for (int p = 2; p < NN; p++)
    //     if (IsPrime[p] == true)
    //         primes.push_back(p);
}
// //************************************************
int mceil(int a, int b)
{
    if (a % b == 0)return a / b;
    else return a / b + 1;
}
// const int N = 2e5 + 5;
// std::vector<int> v[N];
// 3 2 1 4 5

// bipartiteness
// const int N = 1e5 + 5;
// int col[N];
// int vis[N];
// int possible = 0;
// std::vector<int> v[N];
// void dfs(int n, int c)
// {
//  if (vis[n] == 1)return;
//  vis[n] = 1;
//  col[n] = c;
//  for (auto i : v[n])
//  {
//      if (vis[i] == 0)dfs(i, c ^ 1);
//      else
//      {
//          if (c == col[i])
//          {
//              possible = -1;
//              return;
//          }
//      }
//  }
// }
// char mp[105][105];
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

//***************************************************************************************************************
//In  main function first  memset(LCA, -1, sizeof(LCA)) and then dfs() and then initlca()
// const int N = 300005;
// const int Maxn = 21;
// int LCA[N][Maxn];
// std::vector<int> v[N];
// int level[N];
// int parent[N];
// void dfs(int node = 1, int par = -1, int depth = 0)
// {
//     level[node] = depth;
//     LCA[node][0] = par;
//     parent[node] = par;
//     for (auto i : v[node])
//     {
//         if (i != par)dfs(i, node, depth + 1);
//     }
// }
// int query(int x, int y)
// {
//     if (y == 0 || x == -1)return x;

//     for (int i = Maxn; i >= 0; i--)
//     {
//         if (y >= (1 << i))
//             return query(LCA[x][i], y - (1 << i));
//     }
// }
// int getlca(int a, int b)
// {
//     if (level[a] > level[b])swap(a, b);
//     int d = level[b] - level[a];
//     while (d > 0)
//     {
//         int i = log2(d);
//         b = LCA[b][i];
//         d -= (1 << i);
//     }
//     if (a == b)return a;
//     for (int i = Maxn - 1; i >= 0; i--)
//     {
//         if (LCA[a][i] != -1 and (LCA[a][i] != LCA[b][i]))
//         {
//             a = LCA[a][i], b = LCA[b][i];
//         }
//     }
//     return LCA[b][0];
// }
// void initlca(int n)
// {
//     for (int i = 1; i <= Maxn; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (LCA[j][i - 1] != -1)
//             {
//                 int par = LCA[j][i - 1];
//                 LCA[j][i] = LCA[par][i - 1];
//             }
//         }
//     }
// }
// int getdis(int a, int b)
// {
//     int lca = getlca(a, b);
//     return level[b] + level[a] - 2 * (level[lca]);
// }
//****************************************************************************************************************************
// 0 = up, 1 = right, 2 = down, 3 = left
// char a[1005][1005];
// 0 = up, 1 = right, 2 = down, 3 = left
// int dx[] = {1, 0, 0, -1};
// int dy[] = {0, -1, 1, 0};
int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};
// vector<vector<int>>dp(n,vector<int>(m, -1))
// try to use comparataor instead of writing whole

//**********************************************************************
//##string hashing
// const int maxm = 5e5 + 5;
// int suf[maxm];
// int b[maxm];
// void SingleHash(string &s, int base = 131)
// {
//     int n = s.length();
//     b[0] = 1;
//     b[1] = base;
//     for (int i = n - 1; i >= 0; --i) {
//         suf[i] = (s[i] + (int)suf[i + 1] * b[1]) % mod;
//     }
//     for (int i = 2; i <= n; ++i) {
//         b[i] = (int)b[i - 1] * b[1] % mod;
//     }
// }

// int substr(int l, int r)
// {   // [l, r]
//     int v = suf[l] - (int)suf[r + 1] * b[r - l + 1];
//     v %= mod;
//     v += mod;
//     v %= mod;
//     return v;
// }
// int mul(int a, int b)
// {
//     int ans = (a * b) % P;
//     return ans;
// }
// int add(int a, int b) {
//     a += b;
//     if (a >= P) a -= P;
//     return a;
// }
//********************************************************************
// const int N = 300006;
// vector<int>prefix(N + 1, 0);
// string t;
// void kmp(string &s)
// {
//     // s-> jisko dhudna hai
//     int n = s.size();
//     for (int i = 1; i < n; i++)
//     {
//         int j = prefix[i - 1];
//         while (j > 0 and s[i] != s[j])j = prefix[j - 1];

//         if (s[i] == s[j])j++;
//         prefix[i] = j;
//     }
//     for (int i = 0; i < n; i++)cout << prefix[i] << ' ';
//     // cout << '\n';
//     // int i(0), j(0);
//     // // jisme dhudna hai
//     // while (i < t.size())
//     // {
//     //     if (t[i] == s[j])i++, j++;
//     //     else
//     //     {
//     //         if (j != 0)j = prefix[j - 1];
//     //         else i++;
//     //     }
//     //     if (j == s.size())
//     //     {
//     //         cout << i - s.size() << '\n';
//     //         return;
//     //     }
//     // }
// }
//int prefix[N + 1];

//stores smallest prime factor for every number
// const int maxi = 1e7 + 5;
// int spf[maxi];
// // Calculating SPF (Smallest Prime Factor) for every
// // number till MAXN.
// // Time Complexity : O(nloglogn)
// void sieve()
// {
//     spf[1] = 1;
//     for (int i = 2; i < maxi; i++)
//         spf[i] = i;
//     for (int i = 4; i < maxi; i += 2)
//         spf[i] = 2;

//     for (int i = 3; i * i < maxi; i++)
//     {
//         if (spf[i] == i)
//         {
//             for (int j = i * i; j < maxi; j += i)
//                 if (spf[j] == j)spf[j] = i;
//         }
//     }
// }
//const int N = 5e6 + 4;
// int bit[N];
// int get(int r)
// {
//     int ret = 0;
//     for (; r >= 0; r = (r & (r + 1)) - 1)
//         ret = max(ret, bit[r]);
//     return ret;
// }
// void update(int idx, int val)
// {
//     for (; idx < n; idx = idx | (idx + 1))
//         bit[idx] = max(bit[idx], val);
// }
const int N = 3e5 + 5;
const int INF = 1e18;
//std::vector<int>v[N];
int si[N];
int par[N];
int vis[N];
// int get(int u)
// {
//     if (u == par[u])return u;
//     else return par[u] = get(par[u]);
// }
// int maxi;
// int node;
// void union_sets(int a, int b) {
//     a = get(a);
//     b = get(b);
//     if (a != b)
//     {
//         if (si[a] < si[b])swap(a, b);
//         par[b] = a;
//         si[a] += si[b];
//         if (si[a] > si[b])maxi = si[a], node = a;
//         else maxi = si[b], node = b;
//     }
// }
/*
Rerooting Technique:https://codeforces.com/blog/entry/68142?#comment-590195

* Calculte the ans for the root 0, using dfs
* Now shift the root one by one to the childs of
* prevRoot. And calculate the ans, for each of them
* in O(1)

* When shifting the root. Subtract the contri of that child c1 from dp[prevRoot].
* Make that child as root. Add the contri of prevRoot for that child c1

* Call dfs2 on the childs of the child c1

* Roll Back: IMPORTANT: First, Remove contri of prev root from the child c1
* Add the contri of that child c1 to the dp[prevRoot]

* Repeat second step for the other childs of prevRoot.
*/

// stack<int>sta;
// const int N = 1e5 + 5;
// int dp[N];
// int dp1[N];
// int ans[N];
// int a[N];
// int vis[N];
// std::vector<int> v[N];
// void dfs2(int u, int par)
// {
//     ans[u] = dp[u];
//     for (auto it : v[u])
//     {
//         if (it == par)continue;
//         {
//             dp[u] -= max(0ll, dp[it]);
//             dp[it] += max(0ll, dp[u]);
//             dfs2(it, u);
//             dp[it] -= max(0ll, dp[u]);
//             dp[u] += max(0ll, dp[it]);
//         }
//     }
// }
// void dfs(int u, int par)
// {
//     dp[u] = a[u - 1];
//     for (auto it : v[u])
//     {
//         if (it != par)
//         {
//             dfs(it, u);
//             dp[u] = __gcd(dp[u], dp[it]);
//         }
//     }
// }
// int arrA[N], arrB[N];

// struct fenwick
// {
//     int bit[N];
//     inline int add(int r)
//     {
//         int sum = 0;
//         while (r > 0)
//         {
//             sum += bit[r];
//             r -= (r & (-r));
//         }
//         return sum;
//     }
//     void update(int x, int v)
//     {
//         while (x <= N)
//         {
//             bit[x] += v;
//             x += (x & (-x));
//         }
//     }
// } A, B;
void solve()
{
    int n; cin >> n;
    int a[n];
    map<int, int>mp;
    multiset<int>s;
    s.insert(-1);
    FOR(i, 0, n)cin >> a[i], mp[a[i]]++, s.insert(a[i]);
    int mex = 0, cnt = 0;
    cout << mp[0] << ' ';
    set<int>s1;
    s1.insert(0);
    if (s.find(0) != s.end()) s.erase(s.find(0));
    FOR(i, 1, n + 1)
    {
        if (*s1.rbegin() == i - 1)
        {
            cout << cnt + mp[i] << ' ';
            if (s.size())
            {
                auto it = s.upper_bound(i);
                it--;
                if (*it == i)
                {
                    s.erase(s.find(i));
                    s1.insert(i);
                }
                else
                {
                    if (*it != -1)
                    {
                        int x = *it;
                        cnt += (i - x);
                        s1.insert(i);
                        s.erase(s.find(x));
                    }
                }
            }
        }
        else cout << "-1 ";
    }
    cout << '\n';

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //c_p_c();
    //SieveOfEratosthenes();
    //ss();
    //sieve();
    // pre();
    //prep();
    w(t)
    solve();
}