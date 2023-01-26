#include <bits/stdc++.h>
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(long long &x) { scanf("%lld", &x); }
void sc(long long &x, long long &y) { scanf("%lld%lld", &x, &y); }
void sc(long long &x, long long &y, long long &z) {
  scanf("%lld%lld%lld", &x, &y, &z);
}
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(long long x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(long long x, long long y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(long long x, long long y, long long z) {
  printf("%lld %lld %lld\n", x, y, z);
}
using namespace std;
void ast(long long x, long long l, long long r) { assert(x >= l && x <= r); }
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }
const int N = 3e5 + 5, mod = 1e9 + 7;
int n, m, q, k, a[N];
struct node {
  int l, r, id;
  bool operator<(const node &o) const { return l < o.l; }
};
vector<node> qry;
int tot, rt[N], ls[N * 30], rs[N * 30];
long long t[N * 30];
long long ans[N];
void ins(int l, int r, int x, int y, int v, int &now) {
  if (r < x || l > y) return;
  if (!now) now = ++tot;
  t[now] += 1ll * (y - x + 1) * v;
  if (l == r) return;
  int m = (l + r) >> 1;
  ins(l, m, x, y, v, ls[now]);
  ins(m + 1, r, x, y, v, rs[now]);
}
void add(int l1, int r1, int l2, int r2, int v) {
  l1++;
  r1++;
  r1++;
  while (l1 <= k) ins(0, m, l2, r2, v, rt[l1]), l1 += l1 & -l1;
  while (r1 <= k) ins(0, m, l2, r2, -v, rt[r1]), r1 += r1 & -r1;
}
void add(int l, int r, int x) {
  if ((l - 1) / k == (r - 1) / k)
    add((l - 1) % k, (r - 1) % k, (l - 1) / k, (r - 1) / k, x);
  else {
    add((l - 1) % k, k - 1, (l - 1) / k, (l - 1) / k, x);
    add(0, (r - 1) % k, (r - 1) / k, (r - 1) / k, x);
    if ((l - 1) / k + 1 <= (r - 1) / k - 1)
      add(0, k - 1, (l - 1) / k + 1, (r - 1) / k - 1, x);
  }
}
long long query(int l, int r, int x, int now) {
  if (l > x || !now) return 0;
  if (r <= x) return t[now];
  int m = (l + r) >> 1;
  return query(l, m, x, ls[now]) + query(m + 1, r, x, rs[now]);
}
long long query(int l, int r) {
  l++;
  int t = l - 1;
  long long ans = 0;
  while (l) ans += query(0, m, r, rt[l]), l -= l & -l;
  while (t) ans -= query(0, m, r, rt[t]), t -= t & -t;
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &q, &k);
  m = (n - 1) / k;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= q; i++) {
    int l, r;
    sc(l, r);
    qry.push_back({l, r, i});
  }
  sort(qry.begin(), qry.end());
  stack<int> st;
  st.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (a[st.top()] >= a[i]) {
      int l = st.top();
      st.pop();
      add(l, st.top() - 1, -a[l]);
    }
    add(i, st.top() - 1, a[i]);
    st.push(i);
    while (qry.size() && qry.back().l == i) {
      ans[qry.back().id] = query((i - 1) % k, (qry.back().r - 1) / k);
      qry.pop_back();
    }
  }
  for (int i = 1; i <= q; i++) out(ans[i]);
}
