#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (n % 2 == 0 && m % 2 == 1) {
      if (k % 2 == 0 && k <= n * (m - 1) / 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (n % 2 == 1 && m % 2 == 0) {
      if (k >= m / 2) {
        if ((k - m / 2) % 2 == 0)
          cout << "YES\n";
        else
          cout << "NO\n";
      } else
        cout << "NO\n";
    }
    --tt;
  }
}
