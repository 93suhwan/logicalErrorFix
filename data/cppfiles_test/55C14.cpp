#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf("%c", &x); }
void _R(char *x) { scanf("%s", x); }
template <class T, class U>
void _R(pair<T, U> &x) {
  _R(x.first);
  _R(x.second);
}
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const unsigned int &x) { printf("%u", x); }
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.12f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
void _E() {}
template <class T, class... U>
void _E(const T &head, const U &...tail) {
  _W(head);
  printf(sizeof...(tail) ? " " : " <<-\n");
  _E(tail...);
}
void E() {}
template <class T, class... U>
void E(const T &head, const U &...tail) {
  printf("〇 ");
  _W(head);
  printf(sizeof...(tail) ? " " : " <<-\n");
  _E(tail...);
}
template <class T>
void A(const T *st, const T *ed) {
  for (auto i = st; i != ed; _W(*i++))
    if (i != st) putchar(' ');
  putchar('\n');
}
int n, m;
pair<int, int> tag[600005 << 2];
pair<int, int> mx[600005 << 2];
int id[600005 << 2];
int hsh[600005], tot;
int ans[300005];
int path[300005];
vector<pair<int, int> > g[300005];
void build(int i, int l, int r) {
  tag[i] = {0, 0};
  mx[i] = {0, 0};
  if (l == r) {
    mx[i].second = 0;
    return;
  }
  int m = l + r >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}
void pushdown(int i, int l, int r) {
  if (tag[i].first) {
    tag[i << 1] = tag[i];
    tag[i << 1 | 1] = tag[i];
    mx[i << 1] = tag[i];
    mx[i << 1 | 1] = tag[i];
    tag[i] = {0, 0};
  }
}
pair<int, int> query(int i, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mx[i];
  pushdown(i, l, r);
  int m = l + r >> 1;
  pair<int, int> ans = {0, -1};
  if (L <= m) ans = query(i << 1, l, m, L, R);
  if (m < R) ans = max(ans, query(i << 1 | 1, m + 1, r, L, R));
  return ans;
}
void update(int i, int l, int r, int L, int R, int v, int id) {
  if (L <= l && r <= R) {
    mx[i] = {v, id};
    tag[i] = {v, id};
    return;
  }
  pushdown(i, l, r);
  int m = l + r >> 1;
  if (L <= m) update(i << 1, l, m, L, R, v, id);
  if (m < R) update(i << 1 | 1, m + 1, r, L, R, v, id);
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}
void __Run_Case(int __Case = 0) {
  R(n, m);
  for (int i = 1, op, l, r; i <= m; ++i) {
    R(op, l, r);
    g[op].push_back({l, r});
    hsh[++tot] = l;
    hsh[++tot] = r;
  }
  sort(hsh + 1, hsh + tot + 1);
  tot = unique(hsh + 1, hsh + tot + 1) - hsh - 1;
  int num = 0, id = 0;
  for (int i = 1; i <= n; ++i) {
    pair<int, int> res = {0, -1};
    for (auto &x : g[i]) {
      x.first = lower_bound(hsh + 1, hsh + tot + 1, x.first) - hsh;
      x.second = lower_bound(hsh + 1, hsh + tot + 1, x.second) - hsh;
      res = max(res, query(1, 1, tot, x.first, x.second));
    }
    for (auto x : g[i]) {
      update(1, 1, tot, x.first, x.second, res.first + 1, i);
    }
    ans[i] = res.first + 1;
    path[i] = res.second;
    if (ans[i] > num) {
      num = ans[i];
      id = i;
    }
  }
  num = n - num;
  W(num);
  while (id) {
    ans[id] = -1;
    id = path[id];
  }
  for (int i = 1; i <= n; ++i)
    if (ans[i] != -1) printf("%d%c", i, " \n"[(num--) == 0]);
}
void init() {}
int main() {
  init();
  int __T = 1;
  for (int __Case = 1; __Case <= __T; ++__Case) __Run_Case(__Case);
  return 0;
}
