#include <bits/stdc++.h>
using namespace std;
void write(vector<int> &v) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
}
void read(vector<int> &v) {
  for (auto &i : v) cin >> i;
}
const int INF = 1e9;
const int64_t INFF = 1e18;
const int N = 1e6 + 69;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  vector<int> pos(n, 1);
  for (int i = 0; i < n; i++) {
    if (s2[i] == '1') {
      if (s1[i] == '0') {
        ans++;
        pos[i] = 0;
      } else if (i > 0 && s1[i - 1] == '1' && pos[i - 1]) {
        ans++;
        pos[i - 1] = 0;
      } else if (i < n - 1 && s1[i + 1] == '1' && pos[i + 1]) {
        ans++;
        pos[i + 1] = 0;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
