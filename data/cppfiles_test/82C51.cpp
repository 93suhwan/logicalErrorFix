#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, s = 0, c = getchar();
  while (!isdigit(c)) s |= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
  return s ? -a : a;
}
const int N = 3e5 + 100;
int n, Q, k;
int a[N];
int head, tail, q[N];
int val[N];
vector<pair<int, int>> qry[N];
int len, pos[N];
long long res[N];
struct SegTree {
  long long val[N << 2], ctag[N << 2];
  void Pushdown(int t, int l, int r) {
    if (ctag[t]) {
      int mid = (r + l) >> 1;
      ctag[t << 1] = ctag[t];
      val[t << 1] = (mid - l + 1) * ctag[t];
      ctag[t << 1 | 1] = ctag[t];
      val[t << 1 | 1] = (r - mid) * ctag[t];
      ctag[t] = 0;
    }
  }
  void Build(int t = 1, int l = 1, int r = len) {
    val[t] = 0, ctag[t] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build(t << 1, l, mid), Build(t << 1 | 1, mid + 1, r);
  }
  void Cover(int x, int y, int v, int t = 1, int l = 1, int r = len) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
      ctag[t] = v;
      val[t] = (r - l + 1) * ctag[t];
      return;
    }
    Pushdown(t, l, r);
    int mid = (l + r) >> 1;
    Cover(x, y, v, t << 1, l, mid);
    Cover(x, y, v, t << 1 | 1, mid + 1, r);
    val[t] = val[t << 1] + val[t << 1 | 1];
  }
  long long Query(int x, int y, int t = 1, int l = 1, int r = len) {
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) return val[t];
    Pushdown(t, l, r);
    int mid = (l + r) >> 1;
    return Query(x, y, t << 1, l, mid) + Query(x, y, t << 1 | 1, mid + 1, r);
  }
} tree;
int main() {
  n = read(), Q = read(), k = read();
  for (int(i) = (1); (i) <= (n); ++(i)) a[i] = read();
  head = 1, tail = 0;
  for (int(i) = (1); (i) <= (n); ++(i)) {
    while (head <= tail && i - q[head] > k) head++;
    while (head <= tail && a[q[tail]] > a[i]) tail--;
    q[++tail] = i;
    val[i] = a[q[head]];
  }
  for (int(i) = (1); (i) <= (Q); ++(i)) {
    int l = read(), r = read();
    qry[l].emplace_back(r, i);
  }
  for (int(i) = (1); (i) <= (k); ++(i)) {
    len = 0;
    for (int j = i; j <= n; j += k) pos[++len] = j;
    tree.Build();
    tail = 0;
    for (int j = len; j >= 1; --j) {
      int l = pos[j];
      for (int t = qry[l].size() - 1; t >= 0; --t) {
        int r = qry[l].at(t).first, id = qry[l].at(t).second;
        res[id] = a[l] + tree.Query(j + 1, (r - i) / k + 1);
      }
      while (tail && val[pos[q[tail]]] > val[l]) --tail;
      tree.Cover(j, tail ? q[tail] - 1 : len, val[l]);
      q[++tail] = j;
    }
  }
  for (int(i) = (1); (i) <= (Q); ++(i)) printf("%lld\n", res[i]);
  return 0;
}
