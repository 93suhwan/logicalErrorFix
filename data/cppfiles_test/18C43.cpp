#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,O2,O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << "[" << H << "]";
  debug_out(T...);
}
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const double eps = 0.000001;
const int MOD = 998244353;
const int INF = 1000000101;
const long long LLINF = 1223372000000000555;
const int N = 2e6 + 3e2;
const int M = 522;
int a[N];
int f[N];
int dp[N];
int color[N];
bool cycle = false;
void dfs(int v) {
  if (cycle) return;
  color[v] = 1;
  if (a[v] == 0) {
    dp[v] = 0;
    color[v] = 2;
    return;
  }
  int u = f[v];
  if (color[u] == 0) dfs(u);
  if (color[u] == 1) {
    cycle = true;
    return;
  }
  dp[v] = dp[u] + 1;
  color[v] = 2;
}
void solve(int TC) {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[i] = (i + n - d) % n;
    color[i] = 0;
    dp[i] = INF;
  }
  cycle = false;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) dfs(i);
    if (cycle) break;
  }
  if (cycle) {
    cout << -1 << endl;
    return;
  }
  cout << *max_element(dp, dp + n) << endl;
}
int main() {
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int TC = 1;
  cin >> TC;
  for (int test = 1; test <= TC; test++) {
    solve(test);
  }
  cerr << endl << "Time: " << int(getCurrentTime() * 1000) << " ms" << endl;
  return 0;
}
