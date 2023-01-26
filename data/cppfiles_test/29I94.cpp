#include <bits/stdc++.h>
using namespace std;
const int Len = 3e5 + 5, SIZE = 3e5 + 5;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int n, m, B, p[Len];
long long Sum[SIZE], a[Len], maxv;
struct node {
  int L[SIZE], R[SIZE], pos[Len], t;
  long long add[Len], A[Len];
  void init(int n) {
    t = sqrt(n);
    for (int i = 1; i <= n; i++) A[i] = add[i] = 0;
    for (int i = 1; i <= t; i++) L[i] = (i - 1) * t + 1, R[i] = i * t;
    if (R[t] < n) R[t] = n;
    for (int j = 1; j <= t; j++)
      for (int i = L[j]; i <= R[j]; i++) pos[i] = j;
  }
  void Add(int x, int w) {
    for (int i = x; i <= R[pos[x]]; i++) A[i] += w;
    for (int i = pos[x] + 1; i <= t; i++) add[i] += w;
    return;
  }
  long long query(int l) {
    if (l < 1) return 0;
    return add[pos[l]] + A[l];
  }
} S1, S2;
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    maxv = max(maxv, a[i]);
  }
  S1.init(maxv), S2.init(maxv);
  B = 1000;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= B)
      ans += Sum[a[i]];
    else {
      for (int j = 0; j * a[i] <= maxv; j++) {
        int l = j * a[i], r = min((j + 1) * a[i] - 1, maxv);
        ans += S1.query(r) - S1.query(l - 1) -
               1LL * (S2.query(r) - S2.query(l - 1)) * j * a[i];
      }
    }
    long long lst[2] = {0, 0}, now;
    for (int j = 1; j <= a[i]; j = now + 1) {
      now = a[i] / (a[i] / j);
      ans += 1LL * a[i] * (S2.query(now) - lst[0]) -
             1LL * (a[i] / j) * (S1.query(now) - lst[1]);
      lst[0] = S2.query(now), lst[1] = S1.query(now);
    }
    ans += 1LL * a[i] * (S2.query(maxv) - S2.query(a[i]));
    S1.Add(a[i], a[i]), S2.Add(a[i], 1);
    for (int j = 1; j <= B; j++) Sum[j] += a[i] % j;
    write(ans), putchar(' ');
  }
  return 0;
}
