#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const double Pi = acos(-1.0);
int t, n;
int a[N];
int dir[][2] = {{0, 0},  {0, 1},   {-1, 0}, {0, -1}, {1, 0},
                {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
inline int gcd(int x, int y) {
  if (!x) return y;
  return gcd(y % x, x);
}
inline int power(int x, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
int k[N];
void solve() {
  n = read();
  int r = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    if (i % 2) {
      r += a[i];
    } else {
      ans += min(r, a[i]);
      r = max(0, r - a[i]);
      k[i] = 1;
      for (int j = i - 1; j >= 1; j -= 2) {
        if (a[j]) {
          int tmp = a[j];
          a[j] = max(0, a[j] - a[i]);
          a[i] = max(0, a[i] - tmp);
        }
        int las = j;
        if (a[i] == 0) {
          while (j >= 1 && a[j] == 0) j -= 2;
          for (int l = j; l < i; ++l) {
            ans += k[l];
          }
          break;
        }
        if (a[i] == 0) {
          for (int l = las; l < i; ++l) {
            k[l] = 0;
          }
          break;
        }
      }
      if (a[i] != 0) {
        for (int l = 1; l < i; ++l) {
          ans += k[l];
          k[l] = 0;
        }
        k[i] = 0;
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  solve();
  return 0;
}
