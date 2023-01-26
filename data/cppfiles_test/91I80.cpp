#include <bits/stdc++.h>
using namespace std;
const int N = 100005, mod = 1e9 + 7;
int a[N], n, b[N], c[N];
int t[N];
void add(int x, int y) {
  for (; x <= n; x += x & -x) t[x] = (t[x] + y) % mod;
}
int fd(int x) {
  int y = 0;
  for (; x; x -= x & -x) y = (t[x] + y) % mod;
  return y;
}
void cl(int i) {
  int x = a[i], y = b[i + 1];
  int k = (x + y - 1) / y;
  add(i, -1ll * c[i] * i % mod);
  b[i] = (a[i] / k);
  c[i] = k - 1;
  add(i, 1ll * c[i] * i % mod);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), t[i] = 0, c[i] = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = a[i];
      for (int j = i - 1; j >= 1; j--) {
        if (b[j] + (a[j] % (c[j] + 1) != 0) > b[j + 1])
          cl(j);
        else
          break;
      }
      ans = (ans + fd(i)) % mod;
    }
    printf("%d\n", ans);
  }
}
