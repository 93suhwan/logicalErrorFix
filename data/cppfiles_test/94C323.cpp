#include <bits/stdc++.h>
using namespace std;
int t, n, l, a1, a2;
int ans;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> s;
    l = s.size();
    a1 = 0;
    a2 = 0;
    for (int i = 0; i < l; i++) {
      if (i % 2 == 0)
        a1 = a1 * 10 + s[i] - '0';
      else
        a2 = a2 * 10 + s[i] - '0';
    }
    ans = (a1 + 1) * (a2 + 1) - 2;
    cout << ans << '\n';
  }
  return 0;
}
