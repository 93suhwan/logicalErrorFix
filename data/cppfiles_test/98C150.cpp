#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a, s;
  cin >> a >> s;
  map<long long, long long> pos;
  for (long long i = 0; i < 26; i++) pos[a[i]] = i;
  long long n = s.size();
  long long ans = 0;
  for (long long i = 1; i < n; i++) {
    long long tmp = abs(pos[s[i]] - pos[s[i - 1]]);
    ans += tmp;
  }
  cout << ans << "\n";
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
