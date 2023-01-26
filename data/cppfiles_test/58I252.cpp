#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  bool flag = 0;
  int j = 2;
  while (flag == 0 && j <= s1.size() - 1) {
    if (s1[j] != '1' || s2[j] != '1')
      flag = 0;
    else {
      flag = 1;
      cout << "NO" << endl;
      return;
    }
    j++;
  }
  if (flag == 0) {
    cout << "YES" << endl;
    return;
  } else {
    cout << "NO" << endl;
    return;
  }
}
int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
