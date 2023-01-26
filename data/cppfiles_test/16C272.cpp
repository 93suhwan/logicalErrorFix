#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  sort(t.begin(), t.end());
  long long ans = 0;
  for (long long i = 0; i < n; i++) ans += (s[i] != t[i]);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n ";
}
