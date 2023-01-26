#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, i;
  cin >> a;
  while (a--) {
    int n, m, k, h, v, s, f, g, t;
    cin >> n >> m >> k;
    h = (m / 2) * n;
    v = (n / 2) * m;
    s = (m * n) / 2;
    s = s - k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 != 0)
        g = h - k - 1;
      else
        g = h - k;
      if (g >= s)
        cout << "yes\n";
      else
        cout << "no\n";
    } else if (n % 2 != 0 && m % 2 == 0) {
      t = m / 2;
      f = k % m;
      if (f <= t)
        f = f;
      else
        f = m - f;
      g = v - k + f;
      if (k <= h && s <= g)
        cout << "yes\n";
      else
        cout << "no\n";
    } else {
      t = n / 2;
      f = s % n;
      if (f <= t)
        f = f;
      else
        f = n - f;
      g = h - s + f;
      if (s <= v && k <= g)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
}
