#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n, d;
int tot1, tot2;
int ans;
struct misaka {
  int a, s;
  bool operator<(const misaka &cmp) const { return a > cmp.a; }
} a[N], b[N], c[N], tmp[N];
set<misaka> S;
bool cmp1(misaka x, misaka y) { return x.a < y.a; }
bool cmp2(misaka x, misaka y) {
  if (x.s != y.s) return x.s < y.s;
  return x.a > y.a;
}
int main() {
  read(n), read(d);
  for (int i = 1; i <= n; i++) read(a[i].s), read(a[i].a);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (a[i].s < d)
      ;
    else if (a[i].s >= a[i].a)
      b[++tot1] = a[i];
    else
      c[++tot2] = a[i];
  int now = 1;
  sort(b + 1, b + tot1 + 1, cmp1);
  sort(c + 1, c + tot2 + 1, cmp2);
  memcpy(tmp, c, sizeof(c));
  int qwq = 0, simo = 1e9;
  for (int i = tot2; i >= 1; i--) {
    if (simo < tmp[i].a) continue;
    simo = tmp[i].a;
    c[++qwq] = tmp[i];
  }
  tot2 = qwq;
  sort(c + 1, c + tot2 + 1, cmp2);
  for (int i = 1; i <= tot1; i++) {
    if (d > b[i].s) continue;
    while (now <= tot2 && c[now].s < b[i].a) {
      S.insert(c[now]);
      now++;
    }
    while (!S.empty() && (S.begin()->a) > b[i].s) S.erase(S.begin());
    ans++, d = max(d, b[i].a);
  }
  while (now <= tot2) S.insert(c[now]), now++;
  printf("%d\n", ans + S.size());
  return 0;
}
