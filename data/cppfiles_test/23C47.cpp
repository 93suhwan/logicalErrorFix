#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn = 4003;
int n, m, val[maxn];
void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> val[i];
}
int lc[maxn], rc[maxn];
int f(int l, int r) {
  if (l > r) return -1;
  int min_val = INT_MAX, idx = -1;
  for (int i = l; i <= r; i++)
    if (val[i] < min_val) min_val = val[i], idx = i;
  lc[idx] = f(l, idx - 1), rc[idx] = f(idx + 1, r);
  return idx;
}
vector<long long> merge(vector<long long> a, vector<long long> b, int ver) {
  vector<long long> ans;
  ans.resize((int)a.size() + (int)b.size());
  for (int i = 0; i < (int)a.size(); i++)
    for (int j = 0; j < (int)b.size(); j++) {
      ans[i + j] = max(ans[i + j], a[i] + b[j] - 2ll * i * j * val[ver]);
      ans[i + j + 1] =
          max(ans[i + j + 1], a[i] + b[j] + (long long)(m - 1) * val[ver] -
                                  2ll * ((long long)i * j + i + j) * val[ver]);
    }
  return ans;
}
vector<long long> dfs(int ver) {
  if (ver == -1) return {0};
  return merge(dfs(lc[ver]), dfs(rc[ver]), ver);
}
void solve() {
  int root = f(1, n);
  auto ans = dfs(root);
  cout << ans[m] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
