#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, pre, ans;
    cin >> pre;
    ans = pre[0];
    for (int i = 1; i < n - 2; i++) {
      cin >> s;
      if (s[0] != pre[1]) ans += pre[1];
      ans += s[0];
      pre = s;
    }
    ans += pre[1];
    if (ans.size() != n) ans += 'a';
    cout << ans << endl;
  }
}
