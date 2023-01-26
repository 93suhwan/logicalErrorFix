#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 50;
constexpr double eps = 1e-8;
constexpr int inf = 0x3f3f3f3f;
constexpr long long linf = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 1e7 + 50;
constexpr long long mod = 998244353;
int a[maxn];
struct Segment_tree {
  int lson, rson;
  long long dp;
  long long lazy;
} tree[N];
int cnt = 0;
void init(int &i) {
  i = ++cnt;
  tree[i].lazy = 0;
  tree[i].lson = tree[i].rson = tree[i].dp = 0;
}
long long MOD(long long x) {
  if (x < 0)
    x = (x + mod) % mod;
  else if (x > mod)
    x %= mod;
  return x;
}
void push_up(int i) {
  tree[i].dp = tree[tree[i].lson].dp + tree[tree[i].rson].dp;
}
void push_down(int i, int l, int r) {
  if (!tree[i].lson) init(tree[i].lson);
  if (!tree[i].rson) init(tree[i].rson);
  int ls = tree[i].lson, rs = tree[i].rson;
  int mid = (l + r) >> 1;
  tree[ls].dp = MOD(tree[ls].dp + tree[i].lazy * (mid - l + 1) % mod);
  tree[rs].dp = MOD(tree[rs].dp + tree[i].lazy * (r - mid) % mod);
  tree[ls].lazy = MOD(tree[ls].lazy + tree[i].lazy);
  tree[rs].lazy = MOD(tree[rs].lazy + tree[i].lazy);
  tree[i].lazy = 0;
}
void update(int &i, int l, int r, int x, int y, long long k) {
  if (!i) init(i);
  if (l >= x && r <= y) {
    if (k == -1) {
      tree[i].lazy = MOD(tree[i].lazy - tree[i].dp);
      tree[i].dp = MOD(-tree[i].dp);
    } else {
      tree[i].dp = MOD(tree[i].dp + 1ll * (r - l + 1) * k % mod);
      tree[i].lazy = MOD(tree[i].lazy + k);
    }
    return;
  }
  if (tree[i].lazy) push_down(i, l, r);
  int mid = (l + r) >> 1;
  if (y <= mid)
    update(tree[i].lson, l, mid, x, y, k);
  else if (x > mid)
    update(tree[i].rson, mid + 1, r, x, y, k);
  else {
    update(tree[i].lson, l, mid, x, mid, k);
    update(tree[i].rson, mid + 1, r, mid + 1, y, k);
  }
  push_up(i);
}
long long query(int i, int l, int r, int x, int y) {
  if (l >= x && r <= y) return tree[i].dp;
  if (tree[i].lazy) push_down(i, l, r);
  int mid = (l + r) >> 1;
  if (y <= mid)
    return query(tree[i].lson, l, mid, x, y);
  else if (x > mid)
    return query(tree[i].rson, mid + 1, r, x, y);
  else
    return MOD(query(tree[i].lson, l, mid, x, mid) +
               query(tree[i].rson, mid + 1, r, mid + 1, y));
}
int main() {
  int n;
  scanf("%d", &n);
  int mx = 1e9;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    long long sum = 0;
    if (i > 1) sum = query(root, 1, mx, 1, a[i - 1]);
    if (i == 1)
      update(root, 1, mx, 1, a[i], 1);
    else {
      update(root, 1, mx, 1, a[i], -1);
      update(root, 1, mx, 1, a[i], sum);
    }
  }
  printf("%lld\n", query(root, 1, mx, 1, a[n]));
}
