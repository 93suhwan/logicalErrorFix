#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int all = n * m;
    if (n & 1) {
      if (m & 1) {
        assert(false);
      } else {
        if (k < m / 2)
          cout << "NO\n";
        else {
          k -= m / 2;
          if (k & 1)
            cout << "NO\n";
          else
            cout << "YES\n";
        }
      }
    } else {
      if (m & 1) {
        if (k & 1)
          cout << "NO\n";
        else {
          all -= n;
          all /= 2;
          if (k <= all)
            cout << "YES\n";
          else
            cout << "NO\n";
        }
      } else {
        if (k & 1)
          cout << "NO\n";
        else
          cout << "YES\n";
      }
    }
  }
}
