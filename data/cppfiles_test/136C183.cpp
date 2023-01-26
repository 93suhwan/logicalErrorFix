#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    long long b[n + 1];
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    long long sumb = 0, suma = 0;
    bool bad = 0;
    for (int i = 1; i <= n; i++) {
      sumb += b[i];
    }
    long long temp = n * (n + 1) / 2;
    if (sumb % temp != 0) {
      bad = 1;
    } else {
      suma = sumb / temp;
      for (int i = 1; i <= n - 1; i++) {
        long long t = suma - b[i + 1] + b[i];
        if (t % n != 0) {
          bad = 1;
          break;
        } else {
          a[i + 1] = t / n;
          if (a[i + 1] <= 0) {
            bad = 1;
            break;
          }
        }
      }
      if (bad == 0) {
        a[1] = suma;
        for (int i = 2; i <= n; i++) {
          a[1] -= a[i];
        }
        if (a[1] <= 0) {
          bad = 1;
        }
      }
    }
    if (bad == 1) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
