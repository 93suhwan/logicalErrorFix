#include <bits/stdc++.h>
using namespace std;
string s;
bool consi(int l, int h) {
  for (int i = l; i <= h; i++) {
    if (s[i] != '0') return false;
  }
  return true;
}
void solve() {
  cin >> s;
  bool z = 0, o = 0;
  int zs = -1;
  int ze = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      z = 1;
      if (zs == -1) zs = i;
      ze = i;
    } else {
      o = 1;
    }
  }
  int ans = -1;
  if (z and o) {
    if (consi(zs, ze))
      ans = 1;
    else
      ans = 2;
  } else if (z) {
    ans = 1;
  } else {
    ans = 0;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
