#include <bits/stdc++.h>
using namespace std;
const int Maxx = 2 * 1e5 + 99;
long long mod = 998244353;
string s;
int n, l, r;
int a[66], b[66];
void solve() {
  cin >> n;
  cin >> s;
  l = -1, r = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (i == 0) s[i] == 'a' ? ++a[0] : ++b[0];
    if (s[i] == 'a')
      a[i] = a[i - 1] + 1, b[i] = b[i - 1];
    else
      b[i] = b[i - 1] + 1, a[i] = a[i - 1];
  }
  for (int i = 0; i < s.size() - 1; ++i) {
    for (int j = i + 1; j < s.size(); ++j) {
      if (i == 0 && a[j] == b[j]) {
        l = 1, r = j + 1;
        break;
      }
      if (a[j] - a[i - 1] == b[j] - b[i - 1]) {
        l = i + 1, r = j + 1;
        break;
      }
    }
  }
  cout << l << " " << r << endl;
}
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
