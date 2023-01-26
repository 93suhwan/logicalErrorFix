#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> t(n - 2);
    for (int i = 0; i < n - 2; ++i) cin >> t[i];
    string ans = t[0];
    bool ok = true;
    for (int i = 1; i < n - 2; ++i) {
      if (ans.back() != t[i].front()) {
        ok = false;
        ans += t[i];
      } else {
        ans += t[i].back();
      }
    }
    if ((ok)) ans += 'a';
    cout << ans << '\n';
  }
  return 0;
}
