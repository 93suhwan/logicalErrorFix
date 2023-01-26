#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int TT = 1;
  cin >> TT;
  for (int tt = 1; tt <= TT; tt++) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (k > 3) {
      if (m >= n - 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (k == 3) {
      if ((n * (n - 1)) / 2 == m)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (k == 2) {
      if (n == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
