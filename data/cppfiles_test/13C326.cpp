#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    int dem1 = 0, dem2 = 0, dem3 = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (s[i] == 'A')
        dem1++;
      else if (s[i] == 'B')
        dem2++;
      else
        dem3++;
    }
    if (dem1 == dem2 && dem3 == 0)
      cout << "YES" << endl;
    else if (dem2 == dem3 && dem1 == 0)
      cout << "YES" << endl;
    else if (dem1 + dem3 == dem2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
