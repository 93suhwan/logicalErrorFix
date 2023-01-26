#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, n, i, k, z;
    cin >> x >> n;
    long long a[4];
    long long c = x;
    for (i = 0; i < 4; i++) {
      k = i + 1;
      if (c & 1)
        c += k;
      else
        c -= k;
      a[i] = c;
    }
    k = n % 4;
    if (k == 0 || k == 2) {
      cout << a[3] << "\n";
      continue;
    }
    if (k == 1) {
      n--;
      z = n / 4.0;
      if (x & 1)
        cout << a[k - 1] + z * 4 << "\n";
      else
        cout << a[k - 1] - z * 4 << "\n";
    }
    if (k == 3) {
      n--;
      z = n / 4.0;
      if (x & 1)
        cout << a[k - 1] - z * 4 << "\n";
      else
        cout << a[k - 1] + z * 4 << "\n";
    }
  }
}
