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
const int maxn = 3e5 + 5;
const int maxm = 1e6 + 5;
const long long mod = 1e9 + 7;
struct st {
  int l, r;
  long long len, lazy, sum;
} tree[maxn << 2];
void push_up(int root) {
  tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
}
void build(int l, int r, int root) {
  tree[root].l = l, tree[root].r = r, tree[root].len = r - l + 1;
  tree[root].lazy = 0;
  if (l == r) {
    tree[root].sum = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, root << 1);
  build(mid + 1, r, root << 1 | 1);
  push_up(root);
}
void push_down(int root) {
  tree[root << 1].sum += tree[root].lazy * tree[root << 1].len;
  tree[root << 1 | 1].sum += tree[root].lazy * tree[root << 1 | 1].len;
  tree[root << 1].lazy += tree[root].lazy;
  tree[root << 1 | 1].lazy += tree[root].lazy;
  tree[root].lazy = 0;
}
void update(int l, int r, long long c, int root) {
  if (l <= tree[root].l && r >= tree[root].r) {
    tree[root].sum += tree[root].len * c;
    tree[root].lazy += c;
    return;
  }
  if (tree[root].lazy) push_down(root);
  int mid = (tree[root].l + tree[root].r) >> 1;
  if (l <= mid) update(l, r, c, root << 1);
  if (r > mid) update(l, r, c, root << 1 | 1);
  push_up(root);
}
long long query(int l, int r, int root) {
  if (l <= tree[root].l && r >= tree[root].r) {
    return tree[root].sum;
  }
  if (tree[root].lazy) push_down(root);
  int mid = (tree[root].l + tree[root].r) >> 1;
  long long ans = 0;
  if (l <= mid) ans += query(l, r, root << 1);
  if (r > mid) ans += query(l, r, root << 1 | 1);
  return ans;
}
int n;
long long a[maxn], ans[maxn];
int main() {
  in(n);
  build(1, 300000, 1);
  long long pre = 0;
  for (int i = 1; i <= n; ++i) {
    in(a[i]);
    ans[i] = a[i] * (i - 1) - query(a[i], a[i], 1);
    for (long long k = 1, j = a[i]; j <= 300000; k++, j += a[i]) {
      update(j, min(1LL * 300000, j + a[i] - 1), k * a[i], 1);
    }
  }
  build(1, 300000, 1);
  for (int i = 1; i <= n; ++i) {
    ans[i] += pre;
    pre += a[i];
    for (long long k = 1, j = a[i]; j <= 300000; k++, j += a[i]) {
      ans[i] -= query(j, min(1LL * 300000, j + a[i] - 1), 1) * a[i] * k;
    }
    update(a[i], a[i], 1, 1);
    ans[i] += ans[i - 1];
    out(ans[i], i == n);
  }
}
