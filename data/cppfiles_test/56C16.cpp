#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, N = 2e5 + 5;
long long n, save[N], near[10][10], tot, k;
map<long long, long long> attach, in_path;
map<pair<long long, long long>, long long> memo;
map<string, long long> color;
set<long long> adj[N];
long long modPow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1LL;
  }
  return ret;
}
long long Left(long long x) { return (x << 1); }
long long Right(long long x) { return (x << 1) + 1; }
void init() {
  long long res = 1, p2 = 1;
  save[1] = 1;
  for (long long i = 2; i <= k; ++i) {
    p2 = p2 * 2LL;
    res = res * modPow(4LL, p2) % MOD;
    res %= MOD;
    save[i] = res;
  }
  color["white"] = 0;
  color["yellow"] = 1;
  color["green"] = 2;
  color["blue"] = 3;
  color["red"] = 4;
  color["orange"] = 5;
  for (long long i = 0; i < 6; ++i) {
    for (long long j = 0; j < 6; ++j) {
      near[i][j] = 1;
    }
  }
  for (long long i = 0; i < 6; i += 2) {
    near[i][i] = near[i + 1][i + 1] = 0;
    near[i][i + 1] = near[i + 1][i] = 0;
  }
}
long long dfs(long long u, long long must_color, long long depth) {
  if (depth == k) return 1;
  if (memo.find({u, must_color}) != memo.end()) return memo[{u, must_color}];
  long long ret = 1, cnt = 2;
  if (in_path[Left(u)]) {
    cnt--;
    if (attach.find(Left(u)) == attach.end()) {
      long long sum = 0;
      for (long long i = 0; i < 6; ++i)
        if (near[must_color][i]) {
          sum = (sum + dfs(Left(u), i, depth + 1)) % MOD;
        }
      ret = ret * sum % MOD;
    } else {
      long long cc = attach[Left(u)];
      if (near[must_color][attach[Left(u)]])
        ret = ret * dfs(Left(u), cc, depth + 1) % MOD;
      else
        ret = 0;
    }
  }
  if (in_path[Right(u)]) {
    cnt--;
    if (attach.find(Right(u)) == attach.end()) {
      long long sum = 0;
      for (long long i = 0; i < 6; ++i)
        if (near[must_color][i]) {
          sum = (sum + dfs(Right(u), i, depth + 1)) % MOD;
        }
      ret = ret * sum % MOD;
    } else {
      long long cc = attach[Right(u)];
      if (near[must_color][attach[Right(u)]])
        ret = ret * dfs(Right(u), cc, depth + 1) % MOD;
      else
        ret = 0;
    }
  }
  if (cnt == 1 || cnt == 2) {
    ret = ret * save[k - depth] % MOD;
    ret = (ret * 4) % MOD;
  }
  if (cnt == 2) {
    ret = ret * save[k - depth] % MOD;
    ret = (ret * 4) % MOD;
  }
  return memo[{u, must_color}] = ret;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  init();
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    string t;
    cin >> x >> t;
    long long temp = x;
    while (temp) {
      in_path[temp] = 1;
      temp >>= 1;
    }
    attach[x] = color[t];
  }
  long long res = 0;
  if (attach.find(1) != attach.end()) {
    res = dfs(1, attach[1], 1);
  } else {
    for (long long i = 0; i < 6; ++i) {
      res = (res + dfs(1, i, 1)) % MOD;
    }
  }
  cout << res << endl;
  return 0;
}
