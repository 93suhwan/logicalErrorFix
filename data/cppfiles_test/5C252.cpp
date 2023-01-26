#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 10;
void Perform() {
  long long n;
  cin >> n;
  string s[2];
  cin >> s[0] >> s[1];
  long long ans = 0;
  vector<long long> vis(n + 1, 0);
  for (long long i = 0; i < n; ++i) {
    if (s[1][i] != '0') {
      if (i and s[0][i - 1] == '1' and !vis[i - 1]) {
        ++ans;
      } else if (s[0][i] == '0') {
        ++ans;
        vis[i] = 1;
      } else if (i + 1 < n and s[0][i + 1] == '1' and !vis[i + 1]) {
        ++ans;
        vis[i + 1] = 1;
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    Perform();
  }
  return 0;
}
