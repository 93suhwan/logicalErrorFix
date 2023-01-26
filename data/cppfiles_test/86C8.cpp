#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
inline int add(int x, int y) {
  return x + y >= 998244353 ? x + y - 998244353 : x + y;
}
inline int add(int x, int y, int z) { return add(add(x, y), z); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + 998244353 : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % 998244353; }
inline int mul(int x, int y, int z) { return mul(mul(x, y), z); }
int qpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
int Inv(int x) { return qpow(x, 998244353 - 2); }
int pw[10000005], res[10000005], co[10000005];
void work() {
  int n = read(), k = read(), x = read();
  if (x == 0) {
    if (n > k)
      printf("0\n");
    else {
      int ans = 1;
      for (int i = 0; i < n; i++) ans = mul(ans, sub(pw[k], pw[i]));
      printf("%d\n", ans);
    }
  } else {
    int ans = 0, c = qpow(2, n);
    res[0] = pw[k - 1] - 1;
    for (int i = 1; i < k; i++) res[i] = mul(res[i - 1], pw[k - i - 1] - 1);
    co[0] = 1;
    for (int i = 1; i <= k; i++) co[i] = mul(co[i - 1], c);
    for (int i = 0; i < k; i++) {
      int r = mul(co[k - i - 1], i ? res[i - 1] : 1, pw[k - i - 1]);
      if (i & 1)
        ans = sub(ans, r);
      else
        ans = add(ans, r);
    }
    printf("%d\n", ans);
  }
}
signed main() {
  pw[0] = 1;
  for (int i = 1; i < 10000005; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
  int T = read();
  while (T--) work();
  return 0;
}
