#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  bool ans = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int k = m - (j + 1);
      if (i + j < k) continue;
      int start = i;
      int endright = i + j;
      if (endright > n) continue;
      int endleft = endright - k;
      if (endleft > n) continue;
      string right = s.substr(i, j + 1);
      string left = s.substr(endleft, k);
      reverse(left.begin(), left.end());
      if (right + left == t) {
        ans = true;
        break;
      }
    }
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
