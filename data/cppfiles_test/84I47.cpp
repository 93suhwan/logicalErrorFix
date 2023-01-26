#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, K = 18;
const long long inf = 1e16 + 42;
struct node {
  long long sum, suff;
};
node btree[K][4 * N];
long long dp[N][K], phi[N];
void build(node* tree, int i, int l, int r);
void update(node* tree, int i, int l, int r, int p, long long x);
void update2(int i, int l, int r, int p, long long x);
long long query(node* tree, int i, int l, int r, int p);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> factors(N);
  for (int i = 1; i < N; ++i) {
    phi[i] += i;
    factors[i].push_back(i);
    for (int j = 2 * i; j < N; j += i) {
      phi[j] -= phi[i];
      factors[j].push_back(i);
    }
  }
  for (int k = 0; k < K; ++k) {
    build(btree[0], 1, 1, N);
    dp[0][k] = (k == 0 ? 0 : inf);
    update(btree[k], 1, 1, N, 1, dp[0][k]);
    update(btree[k], 1, 1, N, 0, -dp[0][k]);
  }
  for (int i = 1; i < N; ++i) {
    for (auto& d : factors[i]) {
      update2(1, 1, N, d, phi[i / d]);
    }
    for (int k = 0; k < K - 1; ++k) {
      if (k == 0) {
        dp[i][k] = inf;
      } else {
        dp[i][k] = query(btree[k - 1], 1, 1, N, i);
      }
      update(btree[k], 1, 1, N, i + 1, dp[i][k]);
      update(btree[k], 1, 1, N, i, -dp[i][k]);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << dp[n][min(k, K - 1)] << '\n';
  }
}
void build(node* tree, int i, int l, int r) {
  if (l == r) {
    tree[i].sum = 0;
    tree[i].suff = 0;
    return;
  }
  int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
  build(tree, lc, l, mid);
  build(tree, rc, mid + 1, r);
}
void update(node* tree, int i, int l, int r, int p, long long x) {
  if (p < l or p > r) {
    return;
  } else if (l == r) {
    tree[i].sum += x;
    tree[i].suff += x;
  } else {
    int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
    update(tree, lc, l, mid, p, x);
    update(tree, rc, mid + 1, r, p, x);
    tree[i].sum = tree[lc].sum + tree[rc].sum;
    tree[i].suff = min(tree[rc].suff, tree[rc].sum + tree[lc].suff);
  }
}
void update2(int i, int l, int r, int p, long long x) {
  if (p < l or p > r) {
    return;
  } else if (l == r) {
    for (int k = 0; k < K; ++k) {
      btree[k][i].sum += x;
      btree[k][i].suff += x;
    }
  } else {
    int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
    update2(lc, l, mid, p, x);
    update2(rc, mid + 1, r, p, x);
    for (int k = 0; k < K; ++k) {
      btree[k][i].sum = btree[k][lc].sum + btree[k][rc].sum;
      btree[k][i].suff =
          min(btree[k][rc].suff, btree[k][rc].sum + btree[k][lc].suff);
    }
  }
}
long long query(node* tree, int i, int l, int r, int p) {
  if (p >= r) {
    return tree[i].suff;
  } else if (p < l) {
    return inf;
  } else {
    int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
    return min(query(tree, lc, l, mid, p) + tree[rc].sum,
               query(tree, rc, mid + 1, r, p));
  }
}
