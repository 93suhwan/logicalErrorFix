#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char p[maxn * 2];
long long a[maxn], b[maxn], c[maxn], d[maxn], e[maxn];
bool cmp(long long x, long long y) { return x > y; }
void solve() {
  long long n, i, j, k, len;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    a[i] = b[i] = c[i] = d[i] = e[i] = 0;
  }
  for (i = 1; i <= n; i++) {
    long long num[10] = {0};
    scanf("%s", p);
    len = strlen(p);
    for (j = 0; j < len; j++) {
      num[p[j] - 'a' + 1]++;
    }
    a[i] = 2 * num['a' - 'a' + 1] - len;
    b[i] = 2 * num['b' - 'a' + 1] - len;
    c[i] = 2 * num['c' - 'a' + 1] - len;
    d[i] = 2 * num['d' - 'a' + 1] - len;
    e[i] = 2 * num['e' - 'a' + 1] - len;
  }
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + n, cmp);
  sort(c + 1, c + 1 + n, cmp);
  sort(d + 1, d + 1 + n, cmp);
  sort(e + 1, e + 1 + n, cmp);
  long long suma = 0, numa = 0, sumb = 0, numb = 0, sumc = 0, numc = 0,
            sumd = 0, numd = 0, sume = 0, nume = 0;
  for (i = 1; i <= n; i++) {
    if (suma + a[i] > 0) {
      suma += a[i];
      numa++;
    } else
      break;
  }
  for (i = 1; i <= n; i++) {
    if (sumb + b[i] > 0) {
      sumb += b[i];
      numb++;
    } else
      break;
  }
  for (i = 1; i <= n; i++) {
    if (sumc + c[i] > 0) {
      sumc += c[i];
      numc++;
    } else
      break;
  }
  for (i = 1; i <= n; i++) {
    if (sumd + d[i] > 0) {
      sumd += d[i];
      numd++;
    } else
      break;
  }
  for (i = 1; i <= n; i++) {
    if (sume + e[i] > 0) {
      sume += e[i];
      nume++;
    } else
      break;
  }
  long long maxx = 0;
  if (maxx < numa) maxx = numa;
  if (maxx < numb) maxx = numb;
  if (maxx < numc) maxx = numc;
  if (maxx < numd) maxx = numd;
  if (maxx < nume) maxx = nume;
  printf("%d\n", maxx);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
