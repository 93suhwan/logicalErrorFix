#include <bits/stdc++.h>
using namespace std;
void TEST_CASE() {
  string s, t;
  cin >> s >> t;
  map<char, long long> m;
  for (long long i = 0; i < 26; i++) {
    m[s[i]] = i;
  }
  long long ans = 0;
  for (long long i = 1; i < (long long)((t).size()); i++) {
    ans += abs(m[t[i]] - m[t[i - 1]]);
  }
  cout << ans << "\n";
}
signed main() {
  freopen("Error.txt", "w", stderr);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    TEST_CASE();
  }
  return 0;
}
