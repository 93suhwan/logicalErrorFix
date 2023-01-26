#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int ca = 0, cb = 0, cc = 0;
  int z = s.size();
  for (int i = 0; i < z; i++) {
    if (s[i] == 'A') ca++;
    if (s[i] == 'B') cb++;
    if (s[i] == 'C') cc++;
  }
  if (cb == 0) {
    cout << "NO";
    return;
  }
  if (ca == 0 || cc == 0) {
    if (ca == cb || ca == cc || cc == cb)
      cout << "YES";
    else
      cout << "NO";
  } else {
    if (cb == ca + cc)
      cout << "YES";
    else
      cout << "NO";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
