#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double)-1);
int in(int &a, int &b, int &c, int &d) {
  return scanf("%d%d%d%d", &a, &b, &c, &d);
}
int in(int &a, int &b, int &c) { return scanf("%d%d%d", &a, &b, &c); }
int in(int &a, int &b) { return scanf("%d%d", &a, &b); }
int in(long long &a, long long &b) { return scanf("%lld%lld", &a, &b); }
int in(long long &a, long long &b, long long &c, long long &d) {
  return scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
}
int in(long long &a, long long &b, long long &c) {
  return scanf("%lld%lld%lld", &a, &b, &c);
}
int in(long long &a) { return scanf("%lld", &a); }
int in(int &a) { return scanf("%d", &a); }
int in(char *s) { return scanf("%s", s); }
int in(char &c) { return scanf("%c", &c); }
void out(int a, bool ln) { printf("%d%c", a, " \n"[ln]); }
void out(long long a, bool ln) { printf("%lld%c", a, " \n"[ln]); }
void out(double a, int digit, bool ln) {
  printf("%.*f%c", digit, a, " \n"[ln]);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 5e5 + 10;
const int maxm = 1e6 + 5;
const long long mod = 1e9 + 7;
struct node {
  int val, mark, ls, rs, id;
} tree[maxn << 2];
int n, m, cnt = 1;
void push_down(int p) {
  if (!tree[p].ls) tree[p].ls = ++cnt;
  if (!tree[p].rs) tree[p].rs = ++cnt;
  if (tree[p].mark > tree[tree[p].ls].val) {
    tree[tree[p].ls].val = tree[p].mark;
    tree[tree[p].ls].mark = tree[p].mark;
    tree[tree[p].ls].id = tree[p].id;
  }
  if (tree[p].mark > tree[tree[p].rs].val) {
    tree[tree[p].rs].val = tree[p].mark;
    tree[tree[p].rs].mark = tree[p].mark;
    tree[tree[p].rs].id = tree[p].id;
  }
  tree[p].mark = 0;
}
void update(int l, int r, int x, int d, int p = 1, int cl = 1, int cr = 1e9) {
  if (cl > r || cr < l)
    return;
  else if (cl >= l && cr <= r) {
    tree[p].val = x;
    tree[p].id = d;
    if (cr > cl) tree[p].mark = tree[p].val;
  } else {
    int mid = (cl + cr) / 2;
    push_down(p);
    update(l, r, x, d, tree[p].ls, cl, mid);
    update(l, r, x, d, tree[p].rs, mid + 1, cr);
    if (tree[tree[p].ls].val >= tree[tree[p].rs].val) {
      tree[p].val = tree[tree[p].ls].val;
      tree[p].id = tree[tree[p].ls].id;
    } else {
      tree[p].val = tree[tree[p].rs].val;
      tree[p].id = tree[tree[p].rs].id;
    }
  }
}
pair<int, int> query(int l, int r, int p = 1, int cl = 1, int cr = 1e9) {
  if (cl > r || cr < l)
    return pair<int, int>(0, 0);
  else if (cl >= l && cr <= r)
    return pair<int, int>(tree[p].val, tree[p].id);
  else {
    int mid = (cl + cr) >> 1;
    push_down(p);
    pair<int, int> retl = query(l, r, tree[p].ls, cl, mid),
                   retr = query(l, r, tree[p].rs, mid + 1, cr);
    if (retl.first >= retr.first) return retl;
    return retr;
  }
}
vector<pair<int, int> > v[maxn];
int dp[maxn], pre[maxn];
bool vis[maxn];
int main() {
  in(n, m);
  for (int i = 1; i <= m; ++i) {
    int id, l, r;
    in(id, l, r);
    v[id].push_back(pair<int, int>(l, r));
  }
  for (int i = 1; i <= n; ++i) {
    for (auto t : v[i]) {
      pair<int, int> ret = query(t.first, t.second);
      if (ret.first + 1 > dp[i]) {
        dp[i] = ret.first + 1;
        pre[i] = ret.second;
      }
    }
    for (auto t : v[i]) {
      update(t.first, t.second, dp[i], i);
    }
  }
  long long ans = 0, id;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] > ans) {
      ans = dp[i];
      id = i;
    }
  }
  out(n - ans, 1);
  while (id) {
    vis[id] = 1;
    id = pre[id];
  }
  bool flag = 0;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      if (flag) printf(" ");
      flag = 1;
      printf("%d", i);
    }
  }
  return 0;
}
