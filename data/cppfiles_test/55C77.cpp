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
const int maxn = 6e5 + 10;
const int maxm = 1e6 + 5;
const long long mod = 1e9 + 7;
struct st {
  int l, r, len;
  pair<int, int> sum, lazy;
} tree[maxn << 2];
void push_up(int root) {
  tree[root].sum = max(tree[root << 1].sum, tree[root << 1 | 1].sum);
}
void build(int l, int r, int root) {
  tree[root].l = l, tree[root].r = r, tree[root].len = r - l + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, root << 1);
  build(mid + 1, r, root << 1 | 1);
  push_up(root);
}
void push_down(int root) {
  tree[root << 1].sum = max(tree[root].lazy, tree[root << 1].sum);
  tree[root << 1 | 1].sum = max(tree[root].lazy, tree[root << 1 | 1].sum);
  tree[root << 1].lazy = max(tree[root << 1].lazy, tree[root].lazy);
  tree[root << 1 | 1].lazy = max(tree[root << 1 | 1].lazy, tree[root].lazy);
  tree[root].lazy = pair<int, int>(0, 0);
}
void update(int l, int r, pair<int, int> c, int root) {
  if (l <= tree[root].l && r >= tree[root].r) {
    tree[root].sum = c;
    tree[root].lazy = c;
    return;
  }
  if (tree[root].lazy.first) push_down(root);
  int mid = (tree[root].l + tree[root].r) >> 1;
  if (l <= mid) update(l, r, c, root << 1);
  if (r > mid) update(l, r, c, root << 1 | 1);
  push_up(root);
}
pair<int, int> query(int l, int r, int root) {
  if (l <= tree[root].l && r >= tree[root].r) {
    return tree[root].sum;
  }
  if (tree[root].lazy.first) push_down(root);
  int mid = (tree[root].l + tree[root].r) >> 1;
  pair<int, int> ans = pair<int, int>(0, 0);
  if (l <= mid) ans = query(l, r, root << 1);
  if (r > mid) ans = max(ans, query(l, r, root << 1 | 1));
  return ans;
}
vector<pair<int, int> > v[maxn];
vector<int> t;
int dp[maxn], pre[maxn], n, m;
bool vis[maxn];
int main() {
  in(n, m);
  for (int i = 1; i <= m; ++i) {
    int id, l, r;
    in(id, l, r);
    v[id].push_back(pair<int, int>(l, r));
    t.push_back(l);
    t.push_back(r);
  }
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  build(1, t.size(), 1);
  map<int, int> mm;
  for (int i = 0; i < t.size(); i++) {
    mm[t[i]] = i + 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (auto t : v[i]) {
      pair<int, int> ret = query(mm[t.first], mm[t.second], 1);
      if (ret.first + 1 > dp[i]) {
        dp[i] = ret.first + 1;
        pre[i] = ret.second;
      }
    }
    for (auto t : v[i]) {
      update(mm[t.first], mm[t.second], pair<int, int>(dp[i], i), 1);
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
