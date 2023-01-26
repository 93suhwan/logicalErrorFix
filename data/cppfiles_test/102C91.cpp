#include <bits/stdc++.h>
using namespace std;
int yh() {
  int ret = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == EOF) return -1;
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return f ? -ret : ret;
}
const int maxn = 3e5 + 5, mod = 998244353;
int n, k, A, h;
int a[maxn];
int p[maxn];
int tmp[2][maxn];
void calc(int *p, int match, int n) {
  int cur = 0;
  for (int i = (0), iss = (n - 1); i <= iss; i++) tmp[0][i] = i;
  int last = 1, now = 0;
  int rank = n / 2 + 1;
  while (n >= 2) {
    last ^= 1, now ^= 1;
    int pos = 0;
    for (int i = (0), iss = (n / 2 - 1); i <= iss; i++) {
      if (!(match & (1 << cur))) {
        tmp[now][pos++] = tmp[last][(i << 1)];
        p[tmp[last][i << 1 | 1]] = rank;
      } else {
        tmp[now][pos++] = tmp[last][(i << 1 | 1)];
        p[tmp[last][i << 1]] = rank;
      }
      cur++;
    }
    rank = (rank + 1) >> 1;
    n >>= 1;
  }
  p[tmp[now][0]] = 1;
}
int pw[maxn];
int adjust(int *p, int n, int win, int shift) {
  int ans = 0;
  for (int i = (0), iss = (n - 1); i <= iss; i++) {
    if (p[i] == 1) {
      p[i] = 2 - win;
    } else
      p[i] = p[i] * 2 - 1;
    (ans += (long long)(shift + i) * pw[p[i]] % mod) %= mod;
  }
  return ans;
}
map<int, int> ha;
pair<pair<int, int>, int> ans;
int main() {
  k = yh();
  n = 1 << k;
  A = yh(), h = yh();
  pw[0] = 1;
  for (int i = (1), iss = (n); i <= iss; i++)
    pw[i] = (long long)pw[i - 1] * A % mod;
  if (k <= 2) {
    int tm = n - 1;
    for (int s = 0; s < (1 << tm); s++) {
      calc(p, s, n);
      int ans = 0;
      for (int i = (0), iss = (n - 1); i <= iss; i++)
        (ans += ((long long)pw[p[i]] * (i + 1))) %= mod;
      if (ans == h) {
        for (int i = (0), iss = (n - 1); i <= iss; i++)
          cout << p[i] << " \n"[i == n - 1];
        return 0;
      }
    }
    puts("-1");
    return 0;
  }
  ans = {{-1, -1}, -1};
  for (int c = (0), css = (1); c <= css; c++) {
    ha.clear();
    int n = (1 << (k - 1));
    int tm = n - 1;
    for (int i = 0; i < (1 << tm); i++) {
      calc(p, i, n);
      int h1 = adjust(p, n, c == 0, 1);
      ha[h1] = i;
    }
    for (int i = 0; i < (1 << tm); i++) {
      calc(p + n, i, n);
      int h2 = adjust(p + n, n, c == 1, n + 1);
      if (ha.count((h - h2 + mod) % mod)) {
        ans = make_pair(make_pair(ha[(h - h2 + mod) % mod], i), c);
      }
    }
  }
  if (ans.second == -1)
    puts("-1");
  else {
    n /= 2;
    calc(p, ans.first.first, n);
    adjust(p, n, ans.second == 0, 1);
    calc(p + n, ans.first.second, n);
    adjust(p + n, n, ans.second == 1, n + 1);
    for (int i = (0), iss = ((n << 1) - 1); i <= iss; i++)
      cout << p[i] << " \n"[i == (n << 1) - 1];
  }
  return 0;
}
