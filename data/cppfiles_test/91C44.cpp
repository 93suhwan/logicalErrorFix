#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int N = 1e5 + 5;
inline int inc(int x, int y) {
  if ((x += y) >= p) x -= p;
  return x;
}
inline void Inc(int &x, int y) { x = inc(x, y); }
inline int dec(int x, int y) {
  if ((x -= y) < 0) x += p;
  return x;
}
inline void Dec(int &x, int y) { x = dec(x, y); }
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) ans = 1ll * a * ans % p;
  return ans;
}
int n, a[N], b[N], mx[N], Ans, ans, sum;
inline void solve() {
  scanf("%d", &n);
  ans = 0;
  Ans = 0;
  sum = 0;
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  mx[n + 1] = p;
  for (int i = (n); i >= (1); i--) {
    if (a[i] <= mx[i + 1])
      mx[i] = a[i], b[i] = 1;
    else {
      b[i] = (a[i] / mx[i + 1]) + (a[i] % mx[i + 1] != 0);
      mx[i] = (a[i] / b[i]);
    }
    Inc(sum, b[i] - 1);
    Inc(ans, sum);
  }
  Ans = ans;
  for (int i = (n - 1); i >= (1); i--) {
    Dec(ans, 1ll * i * (b[i] - 1) % p);
    if (a[i] != mx[i]) {
      mx[i] = a[i];
      b[i] = 1;
      for (int j = (i - 1); j >= (1); j--) {
        int lstmx = mx[j];
        Dec(ans, 1ll * j * (b[j] - 1) % p);
        if (a[j] <= mx[j + 1])
          mx[j] = a[j], b[j] = 1;
        else {
          b[j] = (a[j] / mx[j + 1]) + (a[j] % mx[j + 1] != 0);
          mx[j] = (a[j] / b[j]);
        }
        Inc(ans, 1ll * j * (b[j] - 1) % p);
        if (mx[j] == lstmx) break;
      }
    }
    Inc(Ans, ans);
  }
  printf("%d\n", Ans);
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
