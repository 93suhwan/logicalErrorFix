#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    k = n * m / 2 - k;
    if (n % 2 == 1) {
      swap(n, m);
      k = n * m / 2 - k;
    }
    if (m % 2 == 1) {
      if ((k >= n / 2 && (k - n / 2) % (2) == 0)) {
        cout << "YES" << '\n';
        continue;
      } else {
        cout << "NO" << '\n';
        continue;
      }
    } else {
      if (k % 2 == 0)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
