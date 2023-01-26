#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[20], al;
int b[20], bl;
int d[20];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    memset(d, 0, sizeof(d));
    memset(a, 0, sizeof(a));
    memset(b, -1, sizeof(b));
    al = 0;
    while (n) {
      a[al] = n % 10;
      n /= 10;
      al++;
    }
    a[al] = 0;
    bl = al;
    int l = bl - 1, c = 0;
    while (l != -1) {
      if (d[a[l]] == 0) {
        c++;
        if (c > k) {
          c = k;
          break;
        }
      }
      d[a[l]]++;
      b[l] = a[l];
      l--;
    }
    if (l != -1) {
      bool tf = false;
      while (1) {
        for (int i = a[l] + 1; i <= 9; i++) {
          if ((d[i] != 0) || (c < k)) {
            if (d[i] == 0) c++;
            b[l] = i;
            d[i]++;
            tf = true;
            break;
          }
        }
        if (tf) break;
        l++;
        d[a[l]]--;
        if (d[a[l]] == 0) c--;
      }
      int m = 0;
      if (c == k) {
        for (int i = 0; i <= 9; i++)
          if (d[i] != 0) {
            m = i;
            break;
          }
      }
      for (int i = l - 1; i >= 0; i--) b[i] = m;
    }
    for (int i = bl - 1; i >= 0; i--) printf("%d", b[i]);
    printf("\n");
  }
  return 0;
}
