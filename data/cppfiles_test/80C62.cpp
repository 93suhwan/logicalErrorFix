#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int T, n, m, tot, cnt;
int a[N], b[N], A[N], c[N], li[N], p[N];
void lisan() {
  sort(li + 1, li + 1 + tot);
  cnt = unique(li + 1, li + 1 + tot) - li - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(li + 1, li + 1 + cnt, a[i]) - li;
  for (int i = 1; i <= m; i++)
    b[i] = lower_bound(li + 1, li + 1 + cnt, b[i]) - li;
}
int lowbit(int x) { return x & (-x); }
void upd(int x) {
  for (; x <= cnt; x += lowbit(x)) c[x]++;
}
long long qry(int x) {
  long long summ = 0;
  for (; x; x -= lowbit(x)) summ += c[x];
  return summ;
}
long long calc() {
  long long summ = 0;
  for (int i = 1; i <= tot; i++) {
    summ += qry(cnt) - qry(A[i]);
    upd(A[i]);
  }
  return summ;
}
void solve(int Lb, int Rb, int La, int Ra) {
  if (Lb > Rb) return;
  int mid = (Lb + Rb) >> 1;
  int val = b[mid];
  int minn = 2e9, summ1 = 0, summ2 = 0;
  for (int i = Ra - 1; i >= La; i--)
    if (a[i] < val) summ2++;
  minn = summ2;
  p[mid] = La;
  for (int i = La + 1; i <= Ra; i++) {
    if (a[i - 1] < val) summ2--;
    if (a[i - 1] > val) summ1++;
    if (summ1 + summ2 < minn) minn = summ1 + summ2, p[mid] = i;
  }
  solve(Lb, mid - 1, La, p[mid]);
  solve(mid + 1, Rb, p[mid], Ra);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    tot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), li[++tot] = a[i];
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]), li[++tot] = b[i];
    sort(b + 1, b + 1 + m);
    lisan();
    for (int i = 1; i <= cnt; i++) c[i] = 0;
    solve(1, m, 1, n + 1);
    tot = 0;
    int nowb = 1;
    for (int i = 1; i <= n; i++) {
      while (p[nowb] == i && nowb <= m) A[++tot] = b[nowb++];
      A[++tot] = a[i];
    }
    while (nowb <= m) A[++tot] = b[nowb++];
    printf("%lld\n", calc());
  }
  return 0;
}
