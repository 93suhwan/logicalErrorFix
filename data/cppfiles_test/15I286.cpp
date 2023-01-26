#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long Fact_Length = 1e5 + 1;
long long Power(long long base, long long expo) {
  long long $result = 1;
  base %= mod;
  while (expo) {
    if (expo % 2 == 1) $result = ($result * base) % mod;
    base = (base * base) % mod;
    expo /= 2;
  }
  return $result;
}
long long Mod_Inv(long long $a) { return Power($a, mod - 2); }
long long Factorial[Fact_Length];
long long Make_Factorial() {
  Factorial[0] = 1;
  for (long long i = 1; i < Fact_Length; i++) {
    Factorial[i] = (i * Factorial[i - 1]) % mod;
  }
  return 0;
}
long long Implement_Make_Factorial = Make_Factorial();
long long nCr(long long $n, long long $r) {
  if ($n < $r || $n < 0 || $r < 0) return 0;
  long long $ans = (Factorial[$n] * Mod_Inv(Factorial[$r])) % mod;
  $ans = ($ans * Mod_Inv(Factorial[$n - $r])) % mod;
  return $ans;
}
const long long N = 101;
vector<long long> adj[N];
long long n, k;
long long dep[N];
void DFS(long long chi, long long par, long long cur) {
  dep[cur]++;
  for (auto x : adj[chi]) {
    if (x == par) continue;
    DFS(x, chi, cur + 1);
  }
}
long long val(long long root) {
  for (long long i = 1; i <= n; i++) dep[i] = 0;
  for (auto x : adj[root]) {
    DFS(x, root, 1);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long x = dep[i];
    long long val = nCr(x, k);
    ans += val;
    ans %= mod;
  }
  return ans;
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) adj[i].clear();
  for (long long i = 1; i <= n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (k == 2) {
    long long ans = (n * (n - 1)) / 2;
    cout << ans << endl;
    return;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += val(i);
    ans %= mod;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
