#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  string t;
  getline(cin >> ws, s);
  getline(cin >> ws, t);
  int n = s.size();
  int m = t.size();
  for (__typeof(n - 1) l = (0); l <= (n - 1); ++l) {
    for (__typeof(n - 1) r = (l); r <= (n - 1); ++r) {
      string right = s.substr(l, r - l + 1);
      int end = max(r - int(m - right.size()), 0);
      if (end > r) break;
      string left = s.substr(end, max(r - end, 0));
      reverse(left.begin(), left.end());
      if ((right + left) == t) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
