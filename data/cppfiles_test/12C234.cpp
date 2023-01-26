#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 1 && m % 2 == 1)
      cout << "NO\n";
    else if (n % 2 == 0 && m % 2 == 0) {
      if (k & 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    } else if (n % 2 == 1 && m % 2 == 0) {
      if (k >= m / 2) {
        k -= m / 2;
        if (k & 1)
          cout << "NO\n";
        else
          cout << "YES\n";
      } else
        cout << "NO\n";
    } else {
      int r = n * m / 2 - k;
      if (r >= n / 2) {
        r -= n / 2;
        if (r & 1)
          cout << "NO\n";
        else
          cout << "YES\n";
      } else
        cout << "NO\n";
    }
  }
  return 0;
}
