#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int a[N], b[N];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int m, r, p = n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      m = -1e9 - 10;
      for (int j = 1; j <= p; j++) {
        if (a[j] >= m) {
          m = a[j];
          r = j;
        }
      }
      if (r != p) {
        cout << 1 << ' ' << p << ' ' << r << endl;
        for (int j = r + 1, k = 1; j <= p; j++, k++) b[k] = a[j];
        for (int k = 1, j = p - r + 1; k <= r; k++, j++) b[j] = a[k];
        for (int j = 1; j <= p; j++) a[j] = b[j];
      }
      p--;
    }
  }
  return 0;
}
