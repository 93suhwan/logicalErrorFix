#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
const int MOD = 1e9 + 7;
void FASTIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MAX_N = 2e5 + 5;
int t;
int n, m;
template <class T>
inline void apply_mod(T& value) {
  if (value > m) {
    value %= m;
  }
}
double stop;
void solve() {
  cin >> n >> m;
  stop = clock();
  vl dp(n + 1, 0);
  ll last = 0;
  int cnt = 0;
  dp[n] = 1;
  for (int i = n; i >= 1; i--) {
    dp[i] += last;
    apply_mod(dp[i]);
    for (int j = 2; i / j >= 1; j++) {
      cnt++;
      dp[i / j] += dp[i] * (1 + (i - j * (i / j)) / (i / j));
      apply_mod(dp[i / j]);
      j += (i - j * (i / j)) / (i / j);
    }
    last += dp[i];
    apply_mod(last);
  }
  cerr << "inner loop cnt: " << cnt << "\n";
  cout << dp[1] << "\n";
}
int main() {
  FASTIO();
  t = 1;
  while (t--) {
    solve();
  }
  cerr << "Time: " << (clock() - stop) / CLOCKS_PER_SEC << "s\n";
  return 0;
}
