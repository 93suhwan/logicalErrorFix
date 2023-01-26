#include <bits/stdc++.h>
using namespace std;
int n, a[200000 + 1], lst, l, r, res, tres;
bool op[200000 + 1];
char c[200000 + 1];
int main() {
  cin >> n, lst = n + 1, l = 1, r = n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) cin >> c[i];
  lst = 0;
  for (int i = 1; i <= n; ++i)
    if (i == n || c[i] != c[i + 1]) {
      if ((i - lst) & 1) {
        for (int j = lst + 1; j <= i; ++j) op[j] = (j - lst) & 1;
      } else {
        tres = 0;
        for (int j = lst + 1; j <= i; ++j)
          op[j] = (j - lst - 1) & 1, tres += (2 * op[j] - 1) * a[j];
        if (tres <= abs(res)) op[lst + 1] ^= 1;
      }
      for (int j = lst + 1; j <= i; ++j)
        if (op[j]) {
          if (c[i] == 'L')
            cout << a[j] << ' ' << 'L' << endl, res -= a[j];
          else
            cout << a[j] << ' ' << 'R' << endl, res += a[j];
        }
      for (int j = lst + 1; j <= i; ++j)
        if (!op[j]) {
          if (c[i] == 'L')
            cout << a[j] << ' ' << 'R' << endl, res += a[j];
          else
            cout << a[j] << ' ' << 'L' << endl, res -= a[j];
        }
      lst = i;
    }
  return 0;
}
