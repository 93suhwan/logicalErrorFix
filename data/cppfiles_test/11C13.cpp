#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
int a[maxn], b[maxn], c[maxn];
struct segtree {
  int l, r, mid;
  long long val = 0;
  segtree *lc, *rc;
  segtree(int L, int R) {
    l = L;
    r = R;
    mid = (l + r) / 2;
    if (l != r) {
      lc = new segtree(l, mid);
      rc = new segtree(mid + 1, r);
    }
  }
  void apply(long long X) { val = max(val, X); }
  void update(int L, int R, long long X) {
    if (l == L && r == R) {
      apply(X);
      return;
    } else if (R <= mid)
      lc->update(L, R, X);
    else if (L >= mid + 1)
      rc->update(L, R, X);
    else {
      lc->update(L, mid, X);
      rc->update(mid + 1, R, X);
    }
    val = max(lc->val, rc->val);
  }
  long long query(int L, int R) {
    if (l == L && r == R)
      return val;
    else if (R <= mid)
      return lc->query(L, R);
    else if (L >= mid + 1)
      return rc->query(L, R);
    else {
      return max(lc->query(L, mid), rc->query(mid + 1, R));
    }
  }
} * segroot;
vector<pair<int, int> > pos[maxn];
long long dp[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    b[i] = i - a[i];
  }
  for (int i = 1; i <= n; ++i) {
    c[i] = i - b[i];
    if (b[i] >= 0) pos[b[i]].push_back({c[i], i});
  }
  for (int i = 0; i <= 200000; ++i) {
    if (pos[i].size()) sort(pos[i].begin(), pos[i].end());
  }
  segroot = new segtree(0, 200001);
  for (int i = 0; i <= 200000; ++i) {
    if (pos[i].size() == 0) continue;
    for (auto p : pos[i]) {
      int v = p.second;
      int now = c[v];
      dp[v] = segroot->query(0, now - 1) + 1;
      segroot->update(now, now, dp[v]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
  cout << ans << endl;
}
