#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int mod = 998244353;
const int inf = 2147483647;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
void up(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int n, m, k, L[N], R[N], a[N], b[N], cnt[N], f[N];
bool v[N];
vector<pair<int, int> > h;
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    int l = read();
    for (int j = 1; j <= l; j++) a[j] = read(), cnt[a[j]]++;
    bool flag = false;
    for (int j = 1; j <= l; j++)
      if (cnt[a[j]] > 1) {
        flag = true;
        break;
      }
    for (int j = 1; j <= l; j++) cnt[a[j]]--;
    for (int j = 2; j <= l; j++) {
      if (R[a[j - 1]] && R[a[j - 1]] != a[j]) flag = true;
      R[a[j - 1]] = a[j];
      v[a[j]] = true;
    }
    for (int j = 1; j < l; j++) {
      if (L[a[j + 1]] && L[a[j + 1]] != a[j]) flag = true;
      L[a[j + 1]] = a[j];
    }
    if (flag) {
      for (int j = 1; j <= l; j++) v[a[j]] = true;
    }
  }
  for (int i = 1; i <= k; i++)
    if (!v[i]) {
      int cnt = 0, t = i;
      while (t) {
        cnt++;
        t = R[t];
      }
      b[cnt]++;
    }
  for (int i = 1; i <= m; i++)
    if (b[i]) h.push_back(make_pair(i, b[i]));
  f[0] = 1;
  for (int i = 1; i <= m; i++)
    for (pair<int, int> j : h)
      if (j.first <= i) up(f[i], (long long)f[i - j.first] * j.second % mod);
  printf("%d\n", f[m]);
  return 0;
}
