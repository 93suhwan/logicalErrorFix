#include <bits/stdc++.h>
long long q_pow(long long x, long long n, long long mod) {
  x %= mod;
  long long ret = 1;
  while (n) {
    if (n & 1) ret = x * ret % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
long long getbit(long long now) {
  int cnt = 0;
  while (now) {
    cnt++;
    now -= (now) & (-now);
  }
  return cnt;
}
int dx[] = {1, 0};
int dy[] = {0, 1};
using namespace std;
void dbg_out() { cout << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cout << ' ' << H;
  dbg_out(T...);
}
const long long maxn = 1e5 + 5;
const long long maxm = 250 + 10;
const long long INF = 0x3f3f3f3f;
const long long IINF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void mul(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
vector<int> vec[2];
int dp[2][maxn];
int a[maxn];
int n;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int pre = 0, now = 1;
  long long ans = 0;
  long long seg, st;
  for (int i = n; i >= 1; i--) {
    swap(pre, now);
    dp[now][a[i]] = 1;
    vec[now].emplace_back(a[i]);
    for (auto to : vec[pre]) {
      seg = (a[i] + to - 1) / to;
      st = a[i] / seg;
      ans += (seg - 1) * dp[pre][to] * i % mod;
      if (ans >= mod) ans -= mod;
      dp[now][st] += dp[pre][to];
      vec[now].emplace_back(st);
    }
    sort(vec[now].begin(), vec[now].end());
    vec[now].resize(unique(vec[now].begin(), vec[now].end()) -
                    vec[now].begin());
    for (auto to : vec[pre]) {
      dp[pre][to] = 0;
    }
    vec[pre].clear();
  }
  for (auto to : vec[now]) {
    dp[now][to] = 0;
  }
  vec[now].clear();
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
