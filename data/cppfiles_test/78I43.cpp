#include <bits/stdc++.h>
using namespace std;
int a[200000];
int cmmdc(int a, int b) {
  int r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int t, n, div, d, pas, x, i;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    div = 0;
    for (pas = (1 << 29); pas > 0; pas >>= 1) {
      x = 0;
      for (i = 0; i < n; i++) x += ((a[i] >> pas) & 1);
      div = cmmdc(div, x);
    }
    if (div == 0) {
      for (i = 1; i <= n; i++) cout << i << " ";
    }
    for (d = 1; d * d < div; d++) {
      if (div % d == 0) cout << d << " ";
    }
    if (d * d > div) d--;
    for (; d >= 1; d--) {
      if (div % d == 0) cout << div / d << " ";
    }
    cout << "\n";
  }
  return 0;
}
