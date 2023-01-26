#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
const long long N = 4000 * 60 + 10;
map<long long, long long> mp, ac;
vector<long long> v;
long long dp[N][6], n, k;
long long pow(long long x, long long n) {
  long long ans = 1;
  for (; n; n >>= 1) {
    if (n & 1) ans = ans * x % mo;
    x = x * x % mo;
  }
  return ans;
}
void dfs(long long x, long long dep) {
  if (dep == k) {
    dp[ac[x]][mp[x]] = 1;
    return;
  }
  if (ac.count(2 * x) != 0 && dep + 1 <= k) dfs(2 * x, dep + 1);
  if (ac.count(2 * x + 1) != 0 && dep + 1 <= k) dfs(2 * x + 1, dep + 1);
  for (long long i = 0; i < 6; i++) {
    long long ret = 1;
    if (ac.count(2 * x) == 0)
      ret = ret * pow(4ll, (1ll << (k - dep)) - 1ll) % mo;
    else {
      long long tmp = 0;
      for (long long j = 0; j < 6; j++)
        if (i != j && (i ^ 1) != j) {
          (tmp += dp[ac[2 * x]][j]) %= mo;
        }
      ret = ret * tmp % mo;
    }
    if (ac.count(2 * x + 1) == 0)
      ret = ret * pow(4ll, (1ll << (k - dep)) - 1ll) % mo;
    else {
      long long tmp = 0;
      for (long long j = 0; j < 6; j++)
        if (i != j && (i ^ 1) != j) {
          (tmp += dp[ac[2 * x + 1]][j]) %= mo;
        }
      ret = ret * tmp % mo;
    }
    if (mp.count(x) == 0)
      dp[ac[x]][i] = ret;
    else if (i == mp[x])
      dp[ac[x]][i] = ret;
  }
}
long long fun(char c) {
  if (c == 'w')
    return 0;
  else if (c == 'y')
    return 1;
  else if (c == 'g')
    return 2;
  else if (c == 'b')
    return 3;
  else if (c == 'r')
    return 4;
  else if (c == 'o')
    return 5;
}
signed main() {
  cin >> k >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    string s;
    cin >> x >> s;
    mp[x] = fun(s[0]);
    for (; x; x /= 2) v.push_back(x);
  }
  sort(v.begin(), v.end());
  long long T = unique(v.begin(), v.end()) - v.begin();
  for (long long i = 0; i < T; i++) {
    ac[v[i]] = i;
  }
  dfs(1, 1);
  long long ans = 0;
  for (long long i = 0; i < 6; i++) (ans += dp[ac[1]][i]) %= mo;
  cout << ans << '\n';
  return 0;
}
