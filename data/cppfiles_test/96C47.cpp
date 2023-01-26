#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct ST {
  int suf, pre, sz, start, finish;
  long long res;
  ST() {
    suf = pre = sz = 0;
    start = finish = 0;
    res = 0;
  }
};
const int N = 2e5 + 5;
int a[N];
ST IT[N << 2];
int n, m;
ST join(ST A, ST B) {
  ST tmp;
  tmp.sz = A.sz + B.sz;
  if (A.pre == A.sz && A.finish <= B.start) {
    tmp.pre = A.pre + B.pre;
  } else {
    tmp.pre = A.pre;
  }
  if (B.suf == B.sz && A.finish <= B.start) {
    tmp.suf = A.suf + B.suf;
  } else {
    tmp.suf = B.suf;
  }
  tmp.start = A.start;
  tmp.finish = B.finish;
  tmp.res = A.res + B.res;
  if (A.finish <= B.start) {
    tmp.res += A.suf * 1ll * B.pre;
  }
  return tmp;
}
void build(int k, int i, int j) {
  if (i == j) {
    IT[k].suf = IT[k].pre = IT[k].res = IT[k].sz = 1;
    IT[k].start = IT[k].finish = a[i];
    return;
  }
  int mid = i + j >> 1;
  build(k << 1, i, mid);
  build(k << 1 | 1, mid + 1, j);
  IT[k] = join(IT[k << 1], IT[k << 1 | 1]);
}
void update(int k, int i, int j, int pos, int val) {
  if (pos < i || j < pos) return;
  if (i == j) {
    IT[k].suf = IT[k].pre = IT[k].res = IT[k].sz = 1;
    IT[k].start = IT[k].finish = val;
    return;
  }
  int mid = i + j >> 1;
  update(k << 1, i, mid, pos, val);
  update(k << 1 | 1, mid + 1, j, pos, val);
  IT[k] = join(IT[k << 1], IT[k << 1 | 1]);
}
ST get(int k, int i, int j, int l, int r) {
  if (j < l || r < i) {
    ST tmp;
    return tmp;
  }
  if (l <= i && j <= r) return IT[k];
  int mid = i + j >> 1;
  return join(get(k << 1, i, mid, l, r), get(k << 1 | 1, mid + 1, j, l, r));
}
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (m--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      update(1, 1, n, x, y);
      a[x] = y;
    } else {
      cout << get(1, 1, n, x, y).res << '\n';
    }
  }
}
