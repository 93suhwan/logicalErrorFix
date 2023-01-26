#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[105];
bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, s = 0, ido;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 1) {
        c1++;
        ido = i;
      } else
        c2++;
      s += a[i];
    }
    if (is_prime(s)) {
      cout << n - 1 << "\n";
      for (int i = 1; i <= n; i++) {
        if (i != ido) {
          cout << i << " ";
        }
      }
      cout << "\n";
    } else {
      cout << n << "\n";
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}
