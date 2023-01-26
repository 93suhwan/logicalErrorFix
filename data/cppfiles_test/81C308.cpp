#include <bits/stdc++.h>
using namespace std;
vector<long long> t;
void build(vector<int> &a, int x, int lx, int rx) {
  if (rx - lx == 1) {
    t[x] = a[lx];
    return;
  }
  int m = (lx + rx) >> 1;
  build(a, (x << 1) + 1, lx, m);
  build(a, (x << 1) + 2, m, rx);
  t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}
void update(int i, int v, int x, int lx, int rx) {
  if (rx - lx == 1) {
    t[x] = v;
    return;
  }
  int m = (lx + rx) >> 1;
  if (i < m)
    update(i, v, (x << 1) + 1, lx, m);
  else
    update(i, v, (x << 1) + 2, m, rx);
  t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}
long long get_sum(int l, int r, int x, int lx, int rx) {
  if (lx >= r || l >= rx) return 0;
  if (lx >= l && rx <= r) return t[x];
  int m = (lx + rx) >> 1;
  return get_sum(l, r, (x << 1) + 1, lx, m) +
         get_sum(l, r, (x << 1) + 2, m, rx);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    t.assign(n << 2, 0);
    for (int i = 0; i < n; i++) {
      int v = s[i] == '+' ? 1 : -1;
      if (i & 1) v = -v;
      update(i, v, 0, 0, n);
    }
    while (q--) {
      int i, j;
      cin >> i >> j;
      long long s = abs(get_sum(i - 1, j, 0, 0, n));
      if (s % 2 == 0)
        s = min(s, 2LL);
      else
        s = 1;
      cout << s << '\n';
    }
  }
  return 0;
}
