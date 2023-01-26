#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e6 + 5;
void Solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int oo = 0, zz = 0, oz = 0, zo = 0;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == '0' && s2[i] == '0')
      ++zz;
    else if (s1[i] == '1' && s2[i] == '1')
      ++oo;
    else if (s1[i] == '1' && s2[i] == '0')
      ++oz;
    else
      ++zo;
  }
  if (oz == 0 && zo == 0) {
    cout << 0 << endl;
  } else if (zo == 1 && oo == 1 && zz == 0 && oz == 0) {
    cout << 1 << endl;
  } else if (oo == 2 && zz == 1) {
    cout << 3 << endl;
  } else if (oz == zo) {
    cout << 2 * oz << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
