#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
int64_t t, n, k;
int64_t power(int64_t a, int64_t b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return power(a % mod * a % mod, b / 2);
  else
    return a % mod * power(a % mod * a % mod, (b - 1) / 2);
}
void solve() {
  string s = bitset<32>(k).to_string();
  reverse(s.begin(), s.end());
  int64_t ans = 0;
  for (int64_t i = 0; i < s.size(); i++) {
    if (s[i] == '1') ans = (ans % mod + power(n, i) % mod) % mod;
  }
  cout << ans % mod << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> t;
  while (t--) {
    cin >> n >> k;
    solve();
  }
  return 0;
}
