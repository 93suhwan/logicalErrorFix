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
  long long sumtag, multag, tag;
} tree[N];
int cnt = 0;
void init(int &i) {
  i = ++cnt;
  tree[i].sumtag = tree[i].tag = 0;
  tree[i].multag = 1;
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
  if (tree[i].tag) {
    tree[ls].dp = tree[rs].dp = 0;
    tree[ls].sumtag = tree[rs].sumtag = 0;
    tree[ls].multag = tree[rs].multag = 1;
    tree[ls].tag = tree[rs].tag = 1;
  }
  tree[ls].dp =
      MOD(tree[ls].dp * tree[i].multag + tree[i].sumtag * (mid - l + 1) % mod);
  tree[rs].dp =
      MOD(tree[rs].dp * tree[i].multag + tree[i].sumtag * (r - mid) % mod);
  tree[ls].sumtag =
      MOD(tree[ls].sumtag * tree[i].multag % mod + tree[i].sumtag);
  tree[rs].sumtag =
      MOD(tree[rs].sumtag * tree[i].multag % mod + tree[i].sumtag);
  tree[ls].multag = MOD(tree[ls].multag * tree[i].multag);
  tree[rs].multag = MOD(tree[rs].multag * tree[i].multag);
  tree[i].multag = 1;
  tree[i].tag = 0;
  tree[i].sumtag = 0;
}
void update(int &i, int l, int r, int x, int y, long long k) {
  if (!i) init(i);
  if (l >= x && r <= y) {
    if (k == -1) {
      tree[i].multag = MOD(tree[i].multag * k);
      tree[i].dp = MOD(tree[i].dp * k);
      tree[i].sumtag = MOD(tree[i].sumtag * k);
    } else if (k == -2) {
      tree[i].tag = 1;
      tree[i].dp = tree[i].sumtag = 0;
      tree[i].multag = 1;
    } else {
      tree[i].sumtag = MOD(tree[i].sumtag + k);
      tree[i].dp = MOD(tree[i].dp + 1ll * (r - l + 1) * k % mod);
    }
    return;
  }
  push_down(i, l, r);
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
int main() {
  int n;
  scanf("%d", &n);
  int mx = 1e9;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    long long sum = 0;
    if (i > 1) sum = tree[root].dp;
    if (i == 1)
      update(root, 1, mx, 1, a[i], 1);
    else {
      update(root, 1, mx, 1, a[i], -1);
      update(root, 1, mx, 1, a[i], sum);
    }
    if (a[i] + 1 <= mx) update(root, 1, mx, a[i] + 1, mx, -2);
  }
  printf("%lld\n", tree[root].dp);
}
