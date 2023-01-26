#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
long long pow_mod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 998244353;
    b >>= 1;
    a = a * a % 998244353;
  }
  return ans;
}
int n, m, T;
long long ji[400032], invji[400032];
struct TREE {
  int num;
} tr[400032 << 3];
vector<int> ve;
struct ques {
  int x, y;
} q[400032];
long long C(int n, int m) {
  return ji[n] * invji[m] % 998244353 * invji[n - m] % 998244353;
}
void build(int rt, int l, int r) {
  tr[rt].num = r - l + 1;
  if (l == r) return;
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
}
int query(int rt, int l, int r, int k) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (tr[rt << 1 | 1].num >= k)
    return query(rt << 1 | 1, mid + 1, r, k);
  else
    return query(rt << 1, l, mid, k - tr[rt << 1 | 1].num);
}
vector<int> cg;
void change(int rt, int l, int r, int k) {
  if (l == r) {
    tr[rt].num = 0;
    cg.push_back(l);
    return;
  }
  int mid = l + r >> 1;
  if (tr[rt << 1 | 1].num >= k)
    change(rt << 1 | 1, mid + 1, r, k);
  else
    change(rt << 1, l, mid, k - tr[rt << 1 | 1].num);
  tr[rt].num = tr[rt << 1].num + tr[rt << 1 | 1].num;
}
void getback(int rt, int l, int r, int pos) {
  if (l == r) {
    tr[rt].num = 1;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    getback(rt << 1, l, mid, pos);
  else
    getback(rt << 1 | 1, mid + 1, r, pos);
  tr[rt].num = tr[rt << 1].num + tr[rt << 1 | 1].num;
}
bool vis[400032];
int main() {
  T = read();
  ji[0] = 1;
  for (int i = 1; i < 400032; ++i) ji[i] = ji[i - 1] * i % 998244353;
  invji[400032 - 1] = pow_mod(ji[400032 - 1], 998244353 - 2);
  for (int i = 400032 - 2; i >= 0; --i)
    invji[i] = invji[i + 1] * (i + 1) % 998244353;
  build(1, 1, 200000);
  while (T--) {
    ve.clear();
    n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
      q[i].x = read(), q[i].y = read();
    }
    int tmp = 200000 - n, lst = n;
    for (int i = m; i >= 1; --i) {
      tmp += lst - q[i].x;
      lst = q[i].x - 1;
      ve.push_back(query(1, 1, 200000, tmp + q[i].x - q[i].y));
      change(1, 1, 200000, tmp + q[i].x - q[i].y + 1);
    }
    int as = 0;
    for (int i = 0; i < ve.size(); ++i)
      if (!vis[ve[i]]) vis[ve[i]] = 1, as++;
    for (int i = 0; i < ve.size(); ++i) vis[ve[i]] = 0;
    cout << C(n + n - 1 - as, n) << '\n';
    for (int i = 0; i < cg.size(); ++i) getback(1, 1, 200000, cg[i]);
    cg.clear();
  }
  return 0;
}
