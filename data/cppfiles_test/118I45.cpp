#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define endl '\n'
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 1005
#define mod 998244353
#define cd complex<double>
#define PI acos(-1)

namespace fft
{
  int n;

  void fft(vector<cd> &a, bool invert)
  {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
      int bit = n >> 1;
      for (; j & bit; bit >>= 1)
        j ^= bit;
      j ^= bit;
      if (i < j)
        swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
      double ang = 2 * PI / len * (invert ? -1 : 1);
      cd wlen(cos(ang), sin(ang));
      for (int i = 0; i < n; i += len)
      {
        cd w(1);
        for (int j = 0; j < len / 2; j++)
        {
          cd u = a[i + j], v = a[i + j + len / 2] * w;
          a[i + j] = u + v;
          a[i + j + len / 2] = u - v;
          w *= wlen;
        }
      }
    }
    if (invert)
      for (cd &x : a)
        x /= n;
  }
  vector<int> mul(vector<int> a, vector<int> b)
  {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    n = 1;
    while (n < 2 * max(a.size(), b.size()))
      n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
      fa[i] *= fb[i];
    fft(fa, true);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = (int)round(fa[i].real()) % mod;
    return ans;
  }
} // namespace fft

struct modint
{
  int val;
  modint(int v = 0) { val = ((v % mod) + mod) % mod; }
  int pow(int y)
  {
    modint x = val;
    modint z = 1;
    while (y)
    {
      if (y & 1)
        z *= x;
      x *= x;
      y >>= 1;
    }
    return z.val;
  }
  int inv() { return pow(mod - 2); }
  void operator=(int o) { val = o % mod; }
  void operator=(modint o) { val = o.val % mod; }
  void operator+=(modint o) { *this = *this + o; }
  void operator-=(modint o) { *this = *this - o; }
  void operator*=(modint o) { *this = *this * o; }
  void operator/=(modint o) { *this = *this / o; }
  bool operator==(modint o) { return val == o.val; }
  bool operator!=(modint o) { return val != o.val; }
  int operator*(modint o) { return ((val * o.val) % mod); }
  int operator/(modint o) { return (val * o.inv()) % mod; }
  int operator+(modint o) { return (val + o.val) % mod; }
  int operator-(modint o) { return (val - o.val + mod) % mod; }
};

int n;
vector<int> adj[MAXN];
modint f[MAXN];
int deg[MAXN];
modint dp[MAXN][MAXN];

void calc()
{
  f[0] = 1;
  for (int i = 1; i < MAXN; i++)
    f[i] = f[i - 1] * i;
}
void dfs(int s, int p)
{
  deg[s] = 0;
  for (auto const &i : adj[s])
  {
    if (i == p)
      continue;
    deg[s]++;
    dfs(i, s);
  }
}
vector<int> solve()
{
  deque<vector<int>> vecs;
  for (int i = 0; i < n; i++)
  {
    vecs.pb({1, deg[i]});
  }
  while (vecs.size() > 1)
  {
    vector<int> v = vecs.back();
    vecs.pop_back();
    vector<int> v2 = vecs.back();
    vecs.pop_back();
    vector<int> v3 = fft::mul(v, v2);
    vecs.push_front(v3);
  }
  return vecs.back();
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  calc();
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(0, -1);
  vector<int> dp = solve();
  modint ans = 0;
  for (int k = 0; k < n; k++)
  {
    modint curr = dp[k]; // de quantos jeitos posso escolher k arestas
    curr *= f[n - k];    // de quantos jeitos posso colorir os n - k vértices que não são os filhos das arestas que escolhi
    (k & 1) ? ans -= curr : ans += curr;
  }
  cout << ans.val << endl;
  return 0;
}
// f(k) - quantidade de maneiras de
// escolher k arestas para serem não beautiful