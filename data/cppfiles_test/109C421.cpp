#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != '0') {
      ans += s[i] - '0' + 1;
    }
  }
  ans += s[n - 1] - '0';
  cout << ans << '\n';
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
