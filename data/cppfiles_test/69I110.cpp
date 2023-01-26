#include <bits/stdc++.h>
using namespace std;
void solve() {
  string n;
  cin >> n;
  int sz = (int)n.length();
  int mn = sz + 1;
  if (sz == 1 && n != "1" && n != "2" && n != "4" && n != "8") {
    cout << 1 << "\n";
    return;
  } else if (sz == 1) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 0; i <= 62; i++) {
    string gg = to_string((1LL) << i);
    int ll = gg.length();
    int tmp = 0;
    int nok = 0;
    int qq = 0;
    for (int j = 0; j < sz; j++) {
      if (gg[qq] == n[j] && qq < ll)
        qq++;
      else
        nok++;
    }
    tmp = nok;
    if (ll < qq) tmp += (ll - qq);
    mn = min(tmp, mn);
  }
  cout << mn << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
