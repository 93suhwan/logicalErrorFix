#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
void solve() {
  long long int a, b, c, d, e, f, g, h, x, n, m, i, j, k, r, o, t, q;
  cin >> n;
  string ss, st;
  cin >> ss >> st;
  for (i = 0; i < n; i++) {
    if (st[i] == '1') {
      if (ss[i] == '0')
        ss[i] = '5';
      else if (i - 1 >= 0 && ss[i - 1] == '1')
        ss[i - 1] = '5';
      else if (i + 1 < n && ss[i + 1] == '1')
        ss[i + 1] = '5';
    }
  }
  c = 0;
  for (i = 0; i < n; i++) {
    if (ss[i] == '5') c++;
  }
  cout << c << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, a, b, n, c, i;
  cin >> t;
  c = 1;
  while (t--) {
    solve();
  }
  return 0;
}
