#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int T, n, m, a[N], b[N], st[N << 1], top;
vector<int> head[N << 1];
map<int, int> M;
struct Bit {
  int tr[N << 1], lim;
  void modify(int x, int y) {
    for (; x <= lim; x += x & -x) tr[x] += y;
  }
  int query(int x) {
    int ret = 0;
    for (; x; x -= x & -x) ret += tr[x];
    return ret;
  }
} B;
struct Seg {
  int tag, Min;
} tr[N << 2];
void upd(int p) { tr[p].Min = min(tr[p << 1].Min, tr[p << 1 | 1].Min); }
void build(int p, int l, int r) {
  tr[p].tag = 0;
  if (l == r) {
    tr[p].Min = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  upd(p);
}
void f(int p, int k) {
  tr[p].Min += k;
  tr[p].tag += k;
}
void pushdown(int p, int l, int r) {
  int mid = (l + r) >> 1;
  if (tr[p].tag) {
    f(p << 1, tr[p].tag);
    f(p << 1 | 1, tr[p].tag);
    tr[p].tag = 0;
  }
}
void modify(int p, int l, int r, int nl, int nr, int k) {
  if (l == nl && r == nr) {
    f(p, k);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(p, l, r);
  if (nr <= mid)
    modify(p << 1, l, mid, nl, nr, k);
  else if (nl > mid)
    modify(p << 1 | 1, mid + 1, r, nl, nr, k);
  else
    modify(p << 1, l, mid, nl, mid, k),
        modify(p << 1 | 1, mid + 1, r, mid + 1, nr, k);
  upd(p);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    top = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], st[++top] = a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i], st[++top] = b[i];
    sort(b + 1, b + 1 + m);
    sort(st + 1, st + 1 + top);
    int num = unique(st + 1, st + 1 + top) - st - 1;
    for (int i = 1; i <= num; ++i) M[st[i]] = i;
    for (int i = 1; i <= n; ++i) a[i] = M[a[i]];
    for (int i = 1; i <= m; ++i) b[i] = M[b[i]];
    B.lim = num;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += B.query(num) - B.query(a[i]);
      B.modify(a[i], 1);
    }
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) head[a[i]].push_back(i);
    int now = 0;
    for (int i = 1; i <= m; ++i) {
      while (now < b[i]) {
        for (int i = 0; i < head[now].size(); ++i)
          modify(1, 1, n, head[now][i], n, -1);
        ++now;
        for (int i = 0; i < head[now].size(); ++i)
          modify(1, 1, n, head[now][i], n, -1);
      }
      int tmp = B.query(b[i] - 1);
      ans += B.query(b[i] - 1);
      int Min = min(tr[1].Min, 0);
      ans += Min;
    }
    cout << ans << endl;
    for (int i = 0; i <= num; ++i) head[i].clear(), B.tr[i] = 0;
  }
  return 0;
}
