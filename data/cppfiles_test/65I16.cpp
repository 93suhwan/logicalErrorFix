#include <bits/stdc++.h>
using namespace std;
int n, a[200000 + 1], d[200000 + 1], lst, l, r;
char c[200000 + 1];
bool op[200000 + 1];
int main() {
  cin >> n, lst = n + 1, l = 1, r = n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = n; i >= 1; --i)
    if (i == 1 || c[i] != c[i - 1]) {
      if ((lst - i) & 1) {
        for (int j = lst - 1; j >= i; --j)
          d[j] = a[r], op[j] = ((lst - 1 - j) & 1), r--;
      } else {
        for (int j = lst - 1; j >= i + 1; --j)
          d[j] = a[r], op[j] = ((lst - 1 - j) & 1), r--;
        d[i] = a[l], op[i] = 0, l++;
      }
      lst = i;
    }
  lst = 0;
  for (int i = 1; i <= n; ++i)
    if (i == n || c[i] != c[i + 1]) {
      for (int j = i; j >= lst + 1; --j) {
        if ((c[j] == 'L') ^ op[j])
          cout << d[j] << ' ' << 'L' << endl;
        else
          cout << d[j] << ' ' << 'R' << endl;
      }
      lst = i;
    }
  return 0;
}
