#include <bits/stdc++.h>
using namespace std;
const long long B = 1e6, D = 6, mod1 = 998244353, mod2 = 1e9 + 7;
vector<long long> vec[10];
long long sum[10];
long long calc(long long u) { return (u % mod1 + mod1) % mod1; }
long long tot = 0, cnt = 0;
long long n, ans = 0;
void solve(long long u) {
  if (u > n) return;
  if (u * B > n / 10 && u * B + B - 1 <= n) {
    long long tmp = 1;
    for (long long i = 0; i <= D; ++i, tmp *= 10) {
      long long A = calc(cnt - tmp * u);
      long long pos =
          lower_bound(vec[i].begin(), vec[i].end(), mod1 - A) - vec[i].begin();
      ans = (ans + 1ll * A * vec[i].size() + sum[i] -
             1ll * mod1 * (vec[i].size() - pos)) %
            mod2;
    }
    cnt += tot;
    return;
  }
  ++cnt, ans = (ans + calc(cnt - u)) % mod2;
  for (long long i = 0; i < 10; ++i) solve(u * 10 + i);
}
void dfs(long long u, long long dep) {
  if (dep > D) return;
  ++tot, vec[dep].push_back(calc(tot - u));
  for (long long i = 0; i < 10; ++i) dfs(u * 10 + i, dep + 1);
}
pair<string, long long> b[5000005];
void print() {
  for (long long i = 1; i <= n; ++i) b[i] = {to_string(i), i};
  sort(b + 1, b + n + 1);
  long long res = 0;
  for (long long i = 1; i <= n; ++i) res = (res + calc(i - b[i].second)) % mod2;
  cout << res << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  dfs(0, 0);
  for (long long i = 0; i <= D; ++i)
    sort(begin(vec[i]), end(vec[i])),
        sum[i] = accumulate(begin(vec[i]), end(vec[i]), 0ll) % mod2;
  for (long long i = 1; i < 10; ++i) solve(i);
  cout << (ans % mod2 + mod2) % mod2 << "\n";
}
