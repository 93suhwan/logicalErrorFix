#include"bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define ff                first
#define ss                second
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
const int                 maxn = 1e3 + 5;
const int                 modulo = 1000000007;
#define mod               1000000009;
const double              pi = 3.14159;
typedef pair<int, int>pp;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>multi_pbds;
// in multiset lower_bound and upper_bound works as vice versa
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update>pair_pbds;
// cout << X.find_by_order(1)->ss; // in pair<int,int> gives 1 index second value

//check n==1 and base cases//
//********************************---------always check array boundness-----------****************
//factorial ncr
// int printNcR(int n, int r)
// {
//     if (n < r)return 0;
//     long long p = 1, k = 1;
//     if (n - r < r)
//         r = n - r;
//     if (r != 0) {
//         while (r) {
//             p *= n;
//             k *= r;
//             long long m = __gcd(p, k);
//             p /= m;
//             k /= m;

//             n--;
//             r--;
//         }
//     }
//     else p = 1;
//     return p;
// }

int power(int x, unsigned int y)
{
    int res = 1;
    //x = x % modulo;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res ;
}
// unsigned long long modInverse(unsigned long long n,
//                               int p)
// {
//     return power(n, p - 2);
// }

// // Returns nCr % p using Fermat's little
// // theorem.
// unsigned long long nCrModPFermat(unsigned long long n,
//                                  int r, int p)
// {
//     // If n<r, then nCr should return 0
//     if (n < r)
//         return 0;
//     // Base case
//     if (r == 0)
//         return 1;

//     // Fill factorial array so that we
//     // can find all factorial of r, n
//     // and n-r
//     unsigned long long fac[n + 1];
//     fac[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fac[i] = (fac[i - 1] * i) % p;

//     return (fac[n] * modInverse(fac[r], p) % p
//             * modInverse(fac[n - r], p) % p)
//            % p;
// }
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
//const int N = 100007;
// std::vector<int>primes;
// bool IsPrime[N];
// void SieveOfEratosthenes()
// {

//     memset(IsPrime, true, sizeof(IsPrime));
//     IsPrime[1] = false;
//     IsPrime[0] = false;
//     for (int p = 2; p * p < N; p++) {
//         if (IsPrime[p] == true) {
//             for (int i = p * p; i < N; i += p)
//                 IsPrime[i] = false;
//         }
//     }
//     for (int p = 2; p < N; p++)
//         if (IsPrime[p] == true)
//             primes.push_back(p);
// }
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
// int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
// int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
// int floodfill(int r, int c, char c1, char c2)
// {

//  if (r<0||c<0||mp[r]==0||mp[c]==0)return 0;
//  if (mp[r][c] != c1)return 0;
//  int ans = 1;
//  mp[r][c] = c2;
//  for (int d = 0; d < 8; d++)ans += floodfill(r + dr[d], c + dc[d], c1, c2);
//  return ans;
// }
//  return ans;
// }
// #############################################################################
// int n, m, c; cin >> n >> m >> c;
// FOR(i, 0, n)
// {
//  int x, y, z; cin >> x >> y >> z;
//  a[z][x][y]++;
// }
// c++;
// for (int k = 0; k < 11; k++ )
// {
//  for (int i = 1; i < 111; i++)
//  {
//      for (int j = 1; j < 111; j++)
//      {
//          a[k][i][j] += a[k][i - 1][j] + a[k][i][j - 1] - a[k][i - 1][j - 1];
//      }
//  }
// }
// FOR(i, 0, m)
// {
//  int t, x, y, xx, yy; cin >> t >> x >> y >> xx >> yy;
//  x--, y--;
//  t = t % c;
//  int ans = 0;
//  for (int k = 0; k < c; k++)
//  {
//      int cur = a[k][xx][yy] - a[k][xx][y] - a[k][x][yy] + a[k][x][y];
//      //cout << cur << '\n';
//      ans += ((t + k) % c) * cur;
//  }
//  cout << ans << '\n';
// }


// #****************************************************************
// CONTRIB : SIR NEAL(LGM)
//     auto in_range = [&](int cnt) {
//         return 0 <= cnt && cnt <= N - 2;
//     };
//     for (int mask = 0; mask < 1 << 4; mask++) {
//         int UL = mask & 1;
//         int UR = mask >> 1 & 1;
//         int DR = mask >> 2 & 1;
//         int DL = mask >> 3 & 1;

//         if (in_range(U - UL - UR) && in_range(R - UR - DR) && in_range(D - DR - DL) && in_range(L - UL - DL)) {
//             cout << "YES" << '\n';
//             return;
//         }
//     }
// #**********************************************************************

// int bin(int n)
// {   int x = 0;
//     int i = 1, m;
//     while (n > 0)
//     {   if ((n % 2) == 1) m = 9;
//         else m = 0;
//         x += (m) * (i);
//         i = i * 10;
//         n = n / 2;
//     }
//     return x;
// }
//#**************************************************************************
// void fac()
// {
//     s[1].insert(1);
//     for (int i = 2; i < MAX; i++)
//     {
//         for (int j = 1; j * j <= i; j++)
//         {
//             if (i % j == 0)
//             {
//                 if (i == i / j)s[i].insert(j);
//                 else s[i].insert(j), s[i].insert(i / j);
//             }
//         }
//     }
// }

// const int N = 200005;
// const int Maxn = 20;
// int LCA[N][Maxn];
// std::vector<int> v[N];
// int level[N];
// int parent[N];
// void dfs(int node = 1 , int par = -1, int depth = 0)
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
// 0 = up, 1 = right, 2 = down, 3 = left
// char a[1005][1005];
// 0 = up, 1 = right, 2 = down, 3 = left
int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};
// set<int>v[100005];
// int vis[100005];
// int parent[100005];
// map<int, int>mp;
// void dfss(int u, int p) {
//     vis[u] = 1;
//     parent[u] = p;

//     for (auto i : v[u])
//     {
//         if (!vis[i])dfss(i, u);
//         else if (i != p)
//         {
//             vector<int> cyc;
//             int cur = u;
//             cyc.pb(u);
//             while (parent[cur] != i)
//             {
//                 cur = parent[cur];
//                 cyc.pb(cur);
//             }
//             cyc.pb(i);
//             cyc.pb(u);
//             cout << cyc.size() << '\n';
//             for (auto x : cyc) cout << x << " ";
//             exit(0);
//         }
//     }
// }
//vector<vector<int>>dp(n,vector<int>(m, -1))
struct codem
{
    string S;
    int A;
    int B;
    int C;
    int D;
    int E;
};
void solve()
{
    int n, m, k; cin >> n >> m >> k;
    if (n == 1 || m == 1)
    {
        if (m == 1 and k == 1)cout << "NO\n";
        else if (n == 1)cout << "NO\n";
        else cout << "NO\n";
        return;
    }
    if (n & 1)
    {
        int x = m / 2;
        map<int, int>mp;
        for (int i = 0; i < x; i++)mp[i] = n;
        while (k > 0)
        {
            int ok = 0;
            for (int i = 0; i < x; i++)
            {
                if ((mp[i] - 1) % 2 == 0)
                {
                    mp[i]--;
                    ok = 1;
                    k--;
                    break;
                }
            }
            if (ok == 0)
            {
                for (int i = 0; i < x; i++)
                {
                    if (mp[i] > 0)
                    {
                        mp[i]--;
                        k--;
                        break;
                    }

                }
            }
        }
        for (int i = 0; i < x; i++)
        {
            if (mp[i] & 1)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    else
    {
        if (m & 1)m--;
        int x = m / 2;
        map<int, int>mp;
        for (int i = 0; i < x; i++)mp[i] = n;
        while (k > 0)
        {
            int ok = 0;
            for (int i = 0; i < x; i++)
            {
                if ((mp[i] - 1) % 2 == 0)
                {
                    mp[i]--;
                    ok = 1;
                    k--;
                    break;
                }
            }
            if (ok == 0)
            {
                for (int i = 0; i < x; i++)
                {
                    if (mp[i] > 0)
                    {
                        mp[i]--;
                        k--;
                        ok = 1;
                        break;
                    }

                }
            }
            if (ok == 0)
            {
                cout << "NO\n";
                return;
            }
        }
        for (int i = 0; i < x; i++)
        {
            if (mp[i] & 1)
            {
                cout << "NO\n";
                // k--;
                return;
            }
        }
        cout << "YES\n";
        return;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // SieveOfEratosthenes();
    //ss();
    //prep();
    w(t)
    solve();
}