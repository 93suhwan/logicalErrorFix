#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k, b, c, d, e = 1, i, j;
    cin >> n >> m >> k;
    long long a[m + 1];
    b = n / m;
    c = n % m;
    for (i = 1; i <= m; i++) a[i] = b + (c-- > 0);
    for (i = 1; i <= k; i++) {
      c = e;
      for (j = 1; j <= m; j++) {
        d = a[j];
        if (d == b) e = c;
        cout << d;
        while (d--) {
          cout << " " << c++;
          if (c > n) c = 1;
        }
        cout << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}
