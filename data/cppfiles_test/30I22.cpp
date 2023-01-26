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
int ksk[150002][22], kkt[150002];
int Find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Find(fa[x]);
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
  int x;
  for (int i = 1; i <= n; i++) {
    x = num[i] + 1;
    for (int j = 1; zs[j] * zs[j] <= 1000001; j++)
      if (x % zs[j] == 0) {
        while (x % zs[j] == 0) x /= zs[j];
        ksk[i][++kkt[i]] = j;
      }
    if (x != 1) ksk[i][++kkt[i]] = zt[x];
  }
}
void Step4() {
  int x, y, g;
  while (m--) {
    x = read();
    y = read();
    if (mt[x] == mt[y]) {
      write(0);
      putchar(10);
      continue;
    }
    g = 0;
    for (int i = 1; i <= kkt[x]; i++)
      if (Find(ksk[x][i]) == mt[y]) {
        write(1);
        putchar(10);
        g = 1;
        break;
      }
    if (g) continue;
    g = 0;
    for (int i = 1; i <= kkt[y]; i++)
      if (Find(ksk[y][i]) == mt[x]) {
        write(1);
        putchar(10);
        g = 1;
        break;
      }
    if (!g) write(2), putchar(10);
  }
}
int main() {
  Step1();
  Step2();
  Step3();
  Step4();
  return 0;
}
