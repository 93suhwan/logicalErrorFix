#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[4001];
vector<long long> dfs(int l, int r) {
  if (r == l) return {0};
  vector<long long> ans(r - l + 1, LLONG_MIN);
  int pos = min_element(a + l, a + r) - a;
  auto L = dfs(l, pos), R = dfs(pos + 1, r);
  for (int i = 0; i <= pos - l; ++i) {
    for (int j = 0; j <= r - pos - 1; ++j) {
      for (int op = 0; op <= 1; ++op) {
        ans[i + j + op] =
            max(ans[i + j + op],
                L[i] + R[j] -
                    1LL * (2 * i * j + op * (2 * i + 2 * j + 1 - m)) * a[pos]);
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << dfs(1, n + 1)[m];
}
