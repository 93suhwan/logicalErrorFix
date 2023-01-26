#include <bits/stdc++.h>
using ll = long long;
void solve() {
  long long m;
  std::cin >> m;
  std::vector<ll> pref1(m + 1);
  std::vector<ll> pref2(m + 1);
  ll val;
  std::cin >> val;
  pref1[1] = val;
  for (int i = 2; i <= m; ++i) {
    std::cin >> val;
    pref1[i] = pref1[i - 1] + val;
  }
  std::cin >> val;
  pref2[1] = val;
  for (int i = 2; i <= m; ++i) {
    std::cin >> val;
    pref2[i] = pref2[i - 1] + val;
  }
  ll ans = 100000000000;
  for (int b = 1; b <= m; ++b) {
    ll b_s1 = pref1[m] - pref1[b];
    ll b_s2 = pref2[b - 1];
    ans = std::min(ans, std::max(b_s1, b_s2));
  }
  std::cout << ans << '\n';
}
int main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}
