#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - 48), ch = getchar();
  return x * f;
}
int t, n, mp1[200005], mp2[200005];
struct AB {
  int a, b, c, id, l, r;
  bool operator<(const AB &A) const {
    if (a + b - c != A.a + A.b - A.c) return a + b - c < A.a + A.b - A.c;
    if (l != A.l) return l < A.l;
    return r < A.r;
  }
} d[200005];
int main() {
  cin >> t;
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      d[i].a = read(), d[i].b = read(), d[i].c = read(), d[i].id = i;
      d[i].l = max(d[i].a - d[i].c, 0);
      d[i].r = min(d[i].a, d[i].a + d[i].b - d[i].c);
    }
    sort(d + 1, d + n + 1);
    int r = -1e9, ans = 0, las = 1;
    for (int i = 1; i <= n; i++) {
      if (d[i].a + d[i].b - d[i].c != d[i - 1].a + d[i - 1].b - d[i - 1].c) {
        r = -1e9;
      }
      if (d[i].l > r) {
        for (int j = las; j < i; j++) {
          mp1[d[j].id] = d[j].a - d[i - 1].l;
          mp2[d[j].id] = d[j].c - (d[j].a - d[i - 1].l);
        }
        ans++;
        r = d[i].r;
        las = i;
      }
    }
    for (int j = las; j <= n; j++) {
      mp1[d[j].id] = d[j].a - d[n].l;
      mp2[d[j].id] = d[j].c - (d[j].a - d[n].l);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", mp1[i], mp2[i]);
    }
  }
}
