#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e2 + 5;
const long long MOD = 1e9 + 7;
const double EPS = 1e-8;
int a[MAX_N * MAX_N], p[MAX_N * MAX_N];
int lowbit(int x) { return x & (-x); }
struct BI_Tree {
  int T[MAX_N * 3];
  void add(int x, int c, int lmt) {
    if (x <= 0) return;
    for (int y = x; y <= lmt; y += lowbit(y)) {
      T[y] += c;
    }
  }
  int getSum(int x) {
    int ans = 0;
    for (int y = x; y > 0; y -= lowbit(y)) {
      ans += T[y];
    }
    return ans;
  }
  void init() { memset(T, 0, sizeof(T)); }
} BIT[MAX_N];
vector<int> xs[MAX_N];
int main() {
  int T, n, m;
  scanf("%d", &T);
  while (T--) {
    long long ans = 0;
    vector<int> ys;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      BIT[i].init();
      xs[i].clear();
    }
    for (int i = 1; i <= n * m; i++) {
      scanf("%d", &a[i]);
      ys.push_back(a[i]);
    }
    sort(ys.begin(), ys.end());
    unordered_map<int, int> low;
    for (int i = 0; i < ys.size(); i++) {
      if (low[ys[i]] == 0) low[ys[i]] = i + 1;
    }
    for (int i = 1; i <= n * m; i++) {
      p[i] = (low[a[i]] - 1) / m;
      low[a[i]]++;
      for (int d = -1; d <= 1; d++) {
        xs[p[i]].push_back(a[i] + d);
      }
    }
    for (int i = 0; i < n; i++) {
      sort(xs[i].begin(), xs[i].end());
      xs[i].erase(unique(xs[i].begin(), xs[i].end()), xs[i].end());
    }
    for (int i = 1; i <= n * m; i++) {
      int x = lower_bound(xs[p[i]].begin(), xs[p[i]].end(), a[i]) -
              xs[p[i]].begin();
      ans += BIT[p[i]].getSum(x);
      BIT[p[i]].add(x + 1, 1, xs[p[i]].size() + 5);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
