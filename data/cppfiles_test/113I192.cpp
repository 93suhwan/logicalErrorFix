#include <bits/stdc++.h>
using namespace std;
void solve() {
  string x1;
  int p1;
  string x2;
  int p2;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  int n = x1.length() + p1;
  int m = x2.length() + p2;
  if (n > m)
    cout << ">\n";
  else if (n < m)
    cout << "<\n";
  else {
    char ch = '=';
    for (int i = 0; i < min(x1.length(), x2.length()); i++) {
      if ((x1[i]) > (x2[i])) {
        ch = '>';
        break;
      } else if ((x1[i] < (x2[i]))) {
        ch = '<';
        break;
      }
    }
    cout << ch << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
