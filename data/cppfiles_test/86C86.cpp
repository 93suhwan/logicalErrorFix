#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0, prev = -1;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '0' && s2[i] == '0') {
      if (i > 0 && s1[i - 1] == '1' && s2[i - 1] == '1' && prev != i - 1)
        ans += 2, prev = i;
      else
        ans += 1;
    } else if (s1[i] == '0' && s2[i] == '1')
      ans += 2;
    else if (s1[i] == '1' && s2[i] == '0')
      ans += 2;
    else {
      if (i > 0 && s1[i - 1] == '0' && s2[i - 1] == '0' && prev != i - 1)
        ans += 1, prev = i;
      else
        ans += 0;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
