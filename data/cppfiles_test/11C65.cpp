#include <bits/stdc++.h>
using namespace std;
void solve();
template <typename T>
struct segtree {
  int N = 1;
  vector<T> seg;
  segtree(int n) {
    while (N < n) N *= 2;
    seg.resize(2 * N, nil);
  }
  segtree(vector<T> &v, int offset = 0) {
    int n = v.size();
    while (N < n + offset) N *= 2;
    seg.resize(2 * N, nil);
    for (int i = 0; i < n; i++) seg[N + i + offset] = v[i];
    for (int i = N - 1; i; i--) seg[i] = join(seg[2 * i], seg[2 * i + 1]);
  }
  const T nil = 0;
  T join(T a, T b) { return max(a, b); }
  T qer(int l, int r) {
    l += N;
    r += N;
    T s = nil;
    while (l <= r) {
      if (l & 1) s = join(s, seg[l++]);
      if (~r & 1) s = join(s, seg[r--]);
      l /= 2;
      r /= 2;
    }
    return s;
  }
  void add(int i, T o) {
    i += N;
    seg[i] = max(seg[i], o);
    for (i /= 2; i; i /= 2) seg[i] = join(seg[2 * i], seg[2 * i + 1]);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  segtree<int> seg(n + 1);
  vector<array<int, 2> > ord;
  for (int i = 0; i < n; i++)
    if (i + 1 - a[i] >= 0) ord.push_back({i + 1 - a[i], i + 1});
  sort(ord.begin(), ord.end());
  int ans = 0;
  for (auto i : ord) {
    int mx = seg.qer(0, i[1] - i[0] - 1) + 1;
    seg.add(i[1] - i[0], mx);
    ans = max(ans, mx);
  }
  cout << ans << '\n';
  return 0;
}
void solve() {}
