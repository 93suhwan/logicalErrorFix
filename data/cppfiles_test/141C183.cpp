#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a, b;
  cin >> a >> b;
  vector<long long> a1;
  vector<long long> b1;
  for (int i = a.length() - 1; i >= 0; i--) {
    a1.push_back(a[i] - 48);
  }
  for (int i = b.length() - 1; i >= 0; i--) {
    b1.push_back(b[i] - 48);
  }
  long long m = 0, i = 0;
  string ans = "";
  for (; i < a1.size(); i++) {
    if (a1[i] <= b1[m]) {
      if (m >= b1.size() || i >= a1.size()) {
        cout << -1 << '\n';
        return;
      }
      ans += (char)(b1[m] - a1[i] + 48);
      m++;
    } else {
      long long x, y;
      x = b1[m];
      y = b1[m + 1];
      long long z = y * 10 + x;
      long long d = z - a1[i];
      m += 2;
      if (d < 0) {
        cout << -1 << '\n';
        return;
      }
      if (d > 10) {
        cout << -1 << '\n';
        return;
      }
      if (d < 0) {
        cout << -1 << '\n';
      }
      ans += (char)(d + 48);
    }
  }
  if (m < b1.size()) {
    for (int j = m; j < b1.size(); j++) ans += (char)(b1[j] + 48);
  }
  if (i < a1.size()) {
    cout << -1 << '\n';
    return;
  }
  bool ch = true;
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (ans[i] != '0') ch = false;
    if (ch and ans[i] == '0') continue;
    cout << ans[i];
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
