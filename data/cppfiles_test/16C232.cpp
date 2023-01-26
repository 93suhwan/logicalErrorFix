#include <bits/stdc++.h>
using namespace std;
const long long INF_MAX = 1e18;
const long long INF_MIN = (1e18) * (-1);
const long long mod = 1e9 + 7;
const long long N = 2e5 + 10;
void Solve() {
  long long n;
  cin >> n;
  string s, x;
  cin >> s;
  x = s;
  sort(s.begin(), s.end());
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] != x[i]) ans++;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long Test = 1;
  cin >> Test;
  while (Test--) {
    Solve();
  }
  return 0;
}
