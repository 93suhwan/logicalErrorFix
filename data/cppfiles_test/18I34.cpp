#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
inline long long max(long long a, long long b) { return ((a > b) ? a : b); }
inline long long min(long long a, long long b) { return ((a > b) ? b : a); }
long long power(long long x, long long ex);
long long powermod(long long x, long long ex, long long md);
const long long inf = 4e18 + 9;
const long long mod = 1e9 + 7;
const long double PI = acos(-1);
const long double eps = 1e-9;
const long long N = 1e6 + 1;
long long arr[N], par[N], vis[N];
long long n, d;
long long calc(vector<long long> &v) {
  long long n = (long long)((v).size());
  vector<long long> dp(n, 0);
  for (long long i = 0; i < (n); i++) {
    if (i == 0) {
      if (v[i] == 1) dp[i] = 1;
    } else {
      if (v[i] == 1) {
        dp[i] = 1;
      }
      if (v[i - 1] == 1) dp[i] += dp[i - 1];
    }
  }
  if (dp[n - 1] == n) return inf;
  long long ans = 0ll;
  for (long long i = 0; i < (n); i++) ans = max(ans, dp[i]);
  return ans;
}
void solve() {
  for (long long i = 0; i < (n + 1); i++) {
    par[i] = vis[i] = arr[i] = 0;
  }
  cin >> n >> d;
  for (long long i = 0; i < (n); i++) cin >> arr[i];
  for (long long i = 0; i < (n); i++) {
    long long to_replace = (i + n - d) % n;
    par[i] = to_replace;
    42;
  }
  vector<vector<long long> > graph;
  if (DEBUG) {
    for (long long i = 0; i < (n); i++)
      if (false) cerr << par[i] << " ";
    if (false) cerr << "\n";
  }
  for (long long i = 0; i < (n); i++) {
    if (!vis[i]) {
      long long node = i;
      long long start = i;
      vector<long long> path;
      path.push_back(arr[node]);
      vis[node] = 1;
      node = par[node];
      while (!vis[node] && node != start) {
        path.push_back(arr[node]);
        vis[node] = 1;
        node = par[node];
      }
      graph.push_back(path);
    }
  }
  long long ans = 0ll;
  for (long long i = 0; i < ((long long)((graph).size())); i++) {
    42;
    long long x = calc(graph[i]);
    42;
    ans = max(ans, x);
  }
  if (ans == inf) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(20);
  long long NTC = 1;
  cin >> NTC;
  long long PTC = 0;
  while ((PTC++) < NTC) {
    if (false) cerr << "Testcase # " << PTC << "\n";
    solve();
    if (false) cerr << "*************************\n";
  }
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long a = power(x, y / 2);
  if (y % 2 == 0)
    return a * a;
  else
    return x * a * a;
}
long long powermod(long long x, long long ex, long long md) {
  long long ans = 1ll;
  while (ex > 0) {
    if (ex & 1ll) ans = (ans * x) % md;
    ex >>= 1ll;
    x = (x * x) % md;
  }
  return ans;
}
