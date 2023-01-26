#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 50, M = 4e3 + 5;
long long st[N << 2], n, m, lazy[N << 2];
void propagate(int low, int high, int pos) {
  st[pos] += lazy[pos];
  st[pos] %= m;
  if (low != high) {
    (lazy[pos << 1] += lazy[pos]) %= m;
    (lazy[pos << 1 | 1] += lazy[pos]) %= m;
  }
  lazy[pos] = 0;
}
void update(int low, int high, int l, int r, long long v, int pos) {
  propagate(low, high, pos);
  if (low > r || high < l) return;
  if (low >= l && high <= r) {
    (st[pos] += v) %= m;
    if (low != high) {
      (lazy[pos << 1] += v) %= m;
      (lazy[pos << 1 | 1] += v) %= m;
    }
    return;
  }
  int mid = (low + high) >> 1;
  update(low, mid, l, r, v, pos << 1);
  update(mid + 1, high, l, r, v, pos << 1 | 1);
}
long long get(int low, int high, int i, int pos) {
  propagate(low, high, pos);
  if (low == high) return st[pos];
  int mid = (low + high) >> 1;
  if (i <= mid)
    return get(low, mid, i, pos << 1);
  else
    return get(mid + 1, high, i, pos << 1 | 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  update(1, n, 1, 1, 1, 1);
  long long x, cnt;
  for (long long i = 1; i < n; ++i) {
    x = get(1, n, i, 1);
    update(1, n, i + 1, n, x, 1);
    cnt = 2;
    for (long long j = i + i; j <= n; j += i) {
      update(1, n, j, min(n, j + cnt - 1), x, 1);
      ++cnt;
    }
  }
  cout << get(1, n, n, 1);
  return 0;
}
