#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
int n, a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int cnt = 0;
    while (1) {
      int f = 0;
      ans++;
      if (ans % 2 == 1) {
        for (int i = 1; i < n; i += 2) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            f = 1;
          }
        }
      } else {
        for (int i = 2; i < n; i += 2) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            f = 1;
          }
        }
      }
      if (f == 0 && cnt == 1) {
        ans = ans - 2;
        break;
      } else if (f == 0 && cnt == 0) {
        cnt++;
      } else if (f == 1) {
        cnt = 0;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
