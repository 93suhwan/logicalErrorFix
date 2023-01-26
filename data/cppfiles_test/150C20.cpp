#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    if (a[n - 1] % 3 == 1) {
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        if (a[i] % 3 && a[i] % 3 != 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        printf("%d\n", a[n - 1] / 3 + 1);
        continue;
      }
      ok = true;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 1 || a[i] == a[n - 1] - 1) {
          ok = false;
          break;
        }
      }
      if (ok)
        printf("%d\n", a[n - 1] / 3 + 1);
      else
        printf("%d\n", a[n - 1] / 3 + 2);
    } else if (a[n - 1] % 3 == 2) {
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        if (a[i] % 3 && a[i] % 3 != 2) {
          ok = false;
          break;
        }
      }
      if (ok)
        printf("%d\n", a[n - 1] / 3 + 1);
      else
        printf("%d\n", a[n - 1] / 3 + 2);
    } else {
      bool ok = true;
      for (int i = 0; i < n; ++i)
        if (a[i] % 3) {
          ok = false;
          break;
        }
      if (ok)
        printf("%d\n", a[n - 1] / 3);
      else
        printf("%d\n", a[n - 1] / 3 + 1);
    }
  }
  return 0;
}
