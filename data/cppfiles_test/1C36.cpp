#include <bits/stdc++.h>
using namespace std;
const double _ = 1e-9, D = 2.0 * acos(-1);
bool eq(double x, double y) { return abs(x - y) <= _; }
bool le(double x, double y) { return x - y <= _; }
bool les(double x, double y) { return y - x > _; }
struct Val {
  double v;
  int* pos;
  bool operator<(const Val& y) const { return les(v, y.v); }
} ar[400010];
int n, K, ax[100010], ay[100010], sz, tt, l[200010], r[200010], pos[200010],
    num, ans, nw, np;
double li = 0, ri = 2e5, m, d[100010], deg[100010], ts, tc, td, tl, tr;
priority_queue<int> pq;
void Add(double x, double y) {
  ++tt, ar[++sz] = (Val){x, &l[tt]}, ar[++sz] = (Val){y, &r[tt]};
}
bool cmp(const int& x, const int& y) { return l[x] < l[y]; }
bool Check() {
  sz = tt = 0;
  for (int i = 1; i <= n; ++i)
    if (le(d[i], 2.0 * m)) {
      if (eq(d[i], 2.0 * m))
        Add(deg[i], deg[i]);
      else {
        td = acos(d[i] / (2.0 * m)), tl = deg[i] - td, tr = deg[i] + td;
        if (le(D, tr))
          Add(tl, D), Add(0, tr - D);
        else if (le(tl, 0))
          Add(0, tr), Add(tl + D, D);
        else
          Add(tl, tr);
      }
    }
  sort(ar + 1, ar + sz + 1), num = 0, ar[0].v = -1;
  for (int i = 1; i <= sz; ++i)
    num += !eq(ar[i].v, ar[i - 1].v), *ar[i].pos = num;
  for (int i = 1; i <= tt; ++i) pos[i] = i;
  sort(pos + 1, pos + tt + 1, cmp);
  ans = nw = 0, np = 1;
  while (!pq.empty()) pq.pop();
  for (int i = 1; i <= num; ++i) {
    while (np <= tt && l[pos[np]] <= i) pq.push(-r[pos[np]]), ++nw, ++np;
    while (!pq.empty() && i > -pq.top()) pq.pop(), --nw;
    ans = max(ans, nw);
  }
  return ans >= K;
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &ax[i], &ay[i]);
    if (ax[i] == 0 && ay[i] == 0) {
      --n, --i, --K;
      continue;
    }
    d[i] = sqrt(1.0 * ax[i] * ax[i] + 1.0 * ay[i] * ay[i]);
    tc = 1.0 * ax[i] / d[i], ts = 1.0 * ay[i] / d[i],
    deg[i] = (ts < 0 ? D - acos(tc) : acos(tc));
  }
  if (K <= 0) return putchar('0'), 0;
  while (ri - li > 1e-4) m = (li + ri) / 2.0, Check() ? ri = m : li = m;
  printf("%.10lf", li);
  return 0;
}
