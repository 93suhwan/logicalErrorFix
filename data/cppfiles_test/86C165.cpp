#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2;
  for (cin >> t; t--; ans = 0) {
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++) {
      int x[2] = {};
      x[s1[i] - '0'] = 1;
      x[s2[i] - '0'] = 1;
      if (x[0] && x[1])
        ans += 2;
      else if (i + 1 < n && ((x[0] && s1[i + 1] == '1' && s2[i + 1] == '1') ||
                             (x[1] && s1[i + 1] == '0' && s2[i + 1] == '0'))) {
        ans += 2;
        i++;
      } else
        ans += x[0];
    }
    cout << ans << '\n';
  }
}
