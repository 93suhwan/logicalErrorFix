#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - 48;
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 - 48 + c;
  return x;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
int n, m;
int zt[1000002];
int zs[1000002], zi;
int num[150002], mt[150002];
int fa[1000002];
struct QJ {
  int l, r;
} st[7500000];
int tt;
int Find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Find(fa[x]);
}
bool cmp(QJ a, QJ b) {
  if (a.l == b.l) return a.r < b.r;
  return a.l < b.l;
}
void Step1() {
  for (int i = 2; i <= 1000001; i++)
    if (zt[i] == 0) {
      zs[++zi] = i;
      fa[zi] = zi;
      zt[i] = zi;
      for (int j = i; j <= 1000001 / i; j++) zt[i * j] = -1;
    }
}
void Step2() {
  int x, kl;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    x = num[i] = read();
    kl = -1;
    for (int j = 1; zs[j] * zs[j] <= 1000001; j++)
      if (x % zs[j] == 0) {
        while (x % zs[j] == 0) x /= zs[j];
        if (kl == -1)
          kl = Find(j);
        else
          fa[Find(j)] = kl;
      }
    if (x != 1)
      if (kl == -1)
        kl = Find(zt[x]);
      else
        fa[Find(zt[x])] = kl;
    mt[i] = kl;
  }
  for (int i = 1; i <= n; i++) mt[i] = Find(mt[i]);
}
void Step3() {
  int x, kt[10], ki;
  for (int i = 1; i <= n; i++) {
    x = num[i] + 1;
    ki = 0;
    for (int j = 1; zs[j] * zs[j] <= 1000001; j++)
      if (x % zs[j] == 0) {
        while (x % zs[j] == 0) x /= zs[j];
        kt[++ki] = Find(j);
      }
    if (x != 1) kt[++ki] = Find(zt[x]);
    kt[++ki] = mt[i];
    for (int i = 1; i <= ki; i++)
      for (int j = 1; j <= ki; j++)
        if (i != j) st[++tt] = (QJ){kt[i], kt[j]};
  }
  sort(st + 1, st + tt + 1, cmp);
}
void Step4() {
  QJ t;
  int x, y, l, r, mid;
  while (m--) {
    x = read();
    y = read();
    if (mt[x] == mt[y]) {
      write(0);
      putchar(10);
      continue;
    }
    l = 1;
    r = tt;
    t.l = mt[x];
    t.r = mt[y];
    while (l < r) {
      mid = (l + r) / 2;
      if (cmp(st[mid], t))
        l = mid + 1;
      else
        r = mid;
    }
    if (st[l].l == t.l && st[l].r == t.r)
      write(1);
    else
      write(2);
    putchar(10);
  }
}
int main() {
  Step1();
  Step2();
  Step3();
  Step4();
  return 0;
}
