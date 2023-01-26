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
      if (k % 2 == 0)
        cout << "yes\n";
      else
        cout << "no\n";
    } else if (n % 2 != 0 && m % 2 == 0) {
      t = m / 2;
      f = k - t;
      if (f < 0)
        cout << "no\n";
      else if (f == 0)
        cout << "yes\n";
      else {
        if (f % 2 == 0)
          cout << "yes\n";
        else
          cout << "no\n";
      }
    } else {
      t = n / 2;
      f = s - t;
      if (f < 0)
        cout << "no\n";
      else if (f == 0)
        cout << "yes\n";
      else {
        if (f % 2 == 0)
          cout << "yes\n";
        else
          cout << "no\n";
      }
    }
  }
}
