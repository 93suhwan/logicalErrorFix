#include <bits/stdc++.h>
using namespace std;
long long int t, i, p, n, l, k, j, a[1000000], b[1000000], c, d;
int main() {
  cin >> t;
  while (t--) {
    for (i = 0; i < 7; i++) cin >> a[i];
    sort(a, a + n);
    cout << a[0] << " " << a[1] << " ";
    c = a[0] + a[1];
    for (i = 2; i < 7; i++) {
      if (a[i] == c) p++;
    }
    if (p == 2)
      cout << c << endl;
    else {
      for (i = 2; i < 7; i++) {
        if (a[i] != c) {
          cout << a[i] << endl;
          break;
        }
      }
    }
    c = 0, p = 0;
  }
}
