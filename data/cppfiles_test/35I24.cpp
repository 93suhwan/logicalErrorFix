#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, A = 1e6 + 5;
int n, a[N], nxt[N];
unordered_map<int, stack<int> > buc;
bool tag[A];
int p[A];
vector<int> pri;
long long res = 0;
void init() {
  for (int i = 2; i < A; ++i) {
    if (!tag[i]) pri.push_back(i), p[i] = i;
    for (int j = 0; j < (int)pri.size(); ++j) {
      if (i * pri[j] >= A) break;
      tag[i * pri[j]] = true, p[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
}
void add(int i, int x) {
  nxt[i] = i;
  while (x > 1) buc[p[x]].push(i), x /= p[x];
}
void del(int i, int x) {
  if (x == 1) return nxt[i] = i, void();
  while (x > 1) {
    if (buc[p[x]].empty())
      nxt[i] = 0;
    else
      nxt[i] = min(nxt[i], buc[p[x]].top()), buc[p[x]].pop();
    x /= p[x];
  }
}
struct Seg_Tree {
  struct Node {
    int data;
  } tr[N << 2];
  void up(int u) { tr[u].data = min(tr[u << 1].data, tr[u << 1 | 1].data); }
  void modify(int u, int l, int r, int x, int z) {
    if (l == r) return tr[u].data = z, void();
    int mid = (l + r) >> 1;
    if (x <= mid)
      return modify(u << 1, l, mid, x, z), up(u);
    else
      return modify(u << 1 | 1, mid + 1, r, x, z), up(u);
  }
  int query(int u, int l, int r, int x, int y, int z) {
    int mid = (l + r) >> 1, res = n + 1;
    if (x <= l && r <= y) {
      if (tr[u].data >= z) return n + 1;
      if (l == r) return l;
      if (tr[u << 1].data < z)
        return query(u << 1, l, mid, x, y, z);
      else
        return query(u << 1 | 1, mid + 1, r, x, y, z);
    }
    if (x <= mid) res = query(u << 1, l, mid, x, y, z);
    if (res != n + 1) return res;
    if (y > mid) res = query(u << 1 | 1, mid + 1, r, x, y, z);
    return res;
  }
} t;
int main() {
  init(), cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    char c = getchar();
    while (c != '*' && c != '/') c = getchar();
    if (c == '*')
      add(i, a[i]);
    else
      del(i, a[i]);
  }
  for (int i = 1; i <= n; ++i) t.modify(1, 1, n, i, nxt[i]);
  for (int i = 1; i <= n; ++i) res += t.query(1, 1, n, i, n, i) - i;
  return printf("%lld\n", res), 0;
}
