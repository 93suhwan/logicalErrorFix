#include <bits/stdc++.h>
using namespace std;
const int M = 1000005;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, a[M], b[M], p[M], s[M], num[M];
vector<int> v[M];
char t[M];
long long ans;
void add(int x, int i) {
  b[i] = i;
  while (x > 1) {
    v[p[x]].push_back(i);
    x /= p[x];
  }
}
void del(int x, int i) {
  b[i] = i;
  while (x > 1) {
    if (v[p[x]].empty()) {
      b[i] = 0;
      return;
    }
    b[i] = min(b[i], v[p[x]].back());
    v[p[x]].pop_back();
    x /= p[x];
  }
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 2; i <= 1e6; i++)
    if (!p[i]) {
      p[i] = i;
      for (int j = i; j <= 1e6; j += i) p[j] = i;
    }
  scanf("%s", t + 1);
  for (int i = 1; i <= n; i++) {
    if (t[i] == '*')
      add(a[i], i);
    else
      del(a[i], i);
  }
  for (int i = n; i >= 1; i--) {
    int cnt = 1;
    while (m > 0 && s[m] >= b[i]) {
      cnt += num[m];
      m--;
    }
    s[++m] = b[i];
    num[m] = cnt;
    if (i == b[i]) ans += cnt;
  }
  printf("%lld\n", ans);
}
