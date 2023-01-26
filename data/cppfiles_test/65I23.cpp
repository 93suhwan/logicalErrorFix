#include <bits/stdc++.h>
using namespace std;
int n, a[200000 + 1], lst;
char c[200000 + 1];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i)
    if (i == n || c[i] != c[i + 1]) {
      if (c[i] == 'L') {
        for (int j = i; j >= lst + 1; --j) {
          if ((i - j) & 1)
            cout << a[j] << ' ' << 'L' << endl;
          else
            cout << a[j] << ' ' << 'R' << endl;
        }
      } else {
        for (int j = i; j >= lst + 1; --j) {
          if ((i - j) & 1)
            cout << a[j] << ' ' << 'R' << endl;
          else
            cout << a[j] << ' ' << 'L' << endl;
        }
      }
      lst = i;
    }
  return 0;
}
