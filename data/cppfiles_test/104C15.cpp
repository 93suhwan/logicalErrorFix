#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return f == 1 ? x : -x;
}
const int maxn = 2e5 + 10;
int n, m;
pair<long long, long long> a[maxn], range[maxn], b[maxn];
long long sum;
inline pair<long long, long long> getrange(pair<long long, long long> x) {
  return pair<long long, long long>(x.first >= m ? -m : m - x.first * 2,
                                    x.second >= m ? m : x.second * 2 - m);
}
inline long long getintersect(pair<long long, long long> x,
                              pair<long long, long long> y) {
  if (y.first <= x.first && x.first <= y.second) return x.first;
  if (x.first <= y.first && y.first <= x.second) return y.first;
  if (x.second <= y.first && y.second <= x.second) return y.second;
}
inline void init() {
  n = read();
  m = read();
  sum = 0;
  for (int i = 1; i <= n; i++)
    a[i].first = read(), a[i].second = read(), sum += a[i].second - a[i].first,
    range[i] = getrange(a[i]);
}
inline void doit() {
  b[n + 1] = pair<long long, long long>(0, 0);
  for (int i = n; i >= 1; i--) {
    b[i] = pair<long long, long long>(b[i + 1].first + range[i].first,
                                      b[i + 1].second + range[i].second);
  }
  long long target, nxt;
  if (b[1].first <= sum && sum <= b[1].second)
    target = sum + ((sum + b[1].first) % 2 == 0 ? 0 : 1);
  else
    target = abs(b[1].first - sum) < abs(b[1].second - sum) ? b[1].first
                                                            : b[1].second;
  printf("%lld\n", abs(sum - target));
  for (int i = 1; i <= n; i++) {
    pair<long long, long long> x = pair<long long, long long>(
        target - range[i].second, target - range[i].first);
    nxt = getintersect(x, b[i + 1]);
    printf("%lld %lld\n", (m - (target - nxt)) / 2, (m + (target - nxt)) / 2);
    target = nxt;
  }
}
int main() {
  int t = read();
  while (t--) {
    init();
    doit();
  }
}
