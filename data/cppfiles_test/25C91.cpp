#include <bits/stdc++.h>
using namespace std;
bool sol(int i, int j, string s, string t, bool direction) {
  if (s[i] != t[j]) return false;
  if (j == t.size() - 1) return true;
  bool a = false, b = false;
  if (direction) {
    if (i > 0) a = sol(i - 1, j + 1, s, t, false);
    if (i < s.size() - 1) b = sol(i + 1, j + 1, s, t, true);
  } else {
    if (i > 0) a = sol(i - 1, j + 1, s, t, false);
  }
  return a || b;
}
void solve() {
  string s, t;
  cin >> s >> t;
  bool ans = false;
  for (int i = 0; i < s.size(); i++) {
    if (sol(i, 0, s, t, true)) {
      ans = true;
      break;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
