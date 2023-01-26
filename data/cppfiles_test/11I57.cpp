#include <bits/stdc++.h>
const long long MAXN = 400005;
const long long HALF = 200001;
const long long INF = 10000000;
long long n;
std::vector<long long> bit(MAXN, -INF);
struct node {
  long long val = -INF;
  node *L = NULL, *R = NULL;
};
void update(long long l, long long r, node* root, long long x, long long t) {
  if (x < l || x > r) {
    return;
  }
  if (l == x && l == r) {
    root->val = t;
    return;
  }
  long long mid = (l + r) / 2;
  long long maxi = -INF;
  if (x <= mid) {
    if (root->L == NULL) {
      root->L = new node;
    }
    update(l, mid, root->L, x, t);
  } else {
    if (root->R == NULL) {
      root->R = new node;
    }
    update(mid + 1, r, root->R, x, t);
  }
  if (root->L != NULL) {
    maxi = std::max(root->L->val, maxi);
  }
  if (root->R != NULL) {
    maxi = std::max(root->R->val, maxi);
  }
  root->val = maxi;
}
long long findd(long long l, long long r, node* root, long long x,
                long long y) {
  if (x > r || y < l) {
    return -INF;
  }
  if (x <= l && r <= y) {
    return root->val;
  }
  long long mid = (l + r) / 2;
  long long maxi = -INF;
  if (root->L != NULL) {
    maxi = std::max(maxi, findd(l, mid, root->L, x, y));
  }
  if (root->R != NULL) {
    maxi = std::max(maxi, findd(mid + 1, r, root->R, x, y));
  }
  return maxi;
}
struct seg {
  std::vector<node> arr;
  void upd(long long a, long long b, long long v, long long id = 0,
           long long l = 0, long long r = n - 1) {
    update(0, MAXN, &arr[id], b, v);
    if (l == r) return;
    if (a <= ((l + r) / 2))
      upd(a, b, v, (id + 1), l, ((l + r) / 2));
    else
      upd(a, b, v, (id + 2 * (((l + r) / 2) - l + 1)), ((l + r) / 2) + 1, r);
  }
  long long maxs(long long x, long long y, long long z, long long id = 0,
                 long long l = 0, long long r = n - 1) {
    if (y < l || r < x) return -INF;
    if (x <= l && r <= y) {
      long long ans = findd(0, MAXN, &arr[id], 0, z);
      return ans;
    }
    return std::max(maxs(x, y, z, (id + 1), l, ((l + r) / 2)),
                    maxs(x, y, z, (id + 2 * (((l + r) / 2) - l + 1)),
                         ((l + r) / 2) + 1, r));
  }
};
seg tree;
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long N;
  std::cin >> N;
  n = N + 1;
  std::pair<long long, long long> help[N];
  tree.arr = std::vector<node>(2 * n - 1);
  for (long long i = 0; i < N; i++) {
    std::cin >> help[i].first;
    help[i].second = i + 1;
  }
  std::sort(help, help + N);
  long long best = 0;
  tree.upd(0, HALF, 0);
  for (long long i = 0; i < N; i++) {
    long long cur =
        tree.maxs(0, help[i].second, help[i].second - help[i].first + HALF) + 1;
    best = std::max(best, cur);
    tree.upd(help[i].second, help[i].second - help[i].first + HALF, cur);
  }
  std::cout << best << std::endl;
  return 0;
}
