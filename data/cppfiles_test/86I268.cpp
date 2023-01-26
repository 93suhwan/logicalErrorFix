#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i] == '0' && t[i] == '1') || (t[i] == '0' && s[i] == '1')) {
      cnt = 0;
      ans += 2;
    } else if (s[i] == '0' && t[i] == '0') {
      if (cnt >= 1) {
        ans += 2;
        cnt = 0;
        continue;
      }
      ans++;
    } else {
      cnt++;
    }
  }
  long long as = 0;
  cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if ((s[i] == '0' && t[i] == '1') || (t[i] == '0' && s[i] == '1')) {
      cnt = 0;
      as += 2;
    } else if (s[i] == '0' && t[i] == '0') {
      if (cnt >= 1) {
        as += 2;
        cnt = 0;
        continue;
      }
      as++;
    } else {
      cnt++;
    }
  }
  cout << max(ans, as) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
