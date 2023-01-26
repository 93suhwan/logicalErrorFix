#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) {
    in >> x;
  }
  return in;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  function<vector<long long>(int, int)> dfs = [&](int l, int r) {
    if (l > r) {
      return vector<long long>{0};
    }
    int p = l;
    for (int i = l + 1; i <= r; i++) {
      if (a[i] < a[p]) {
        p = i;
      }
    }
    auto L = dfs(l, p - 1);
    auto R = dfs(p + 1, r);
    vector<long long> dp(L.size() + R.size() + 1);
    for (int i = 0; i < (int)L.size(); i++) {
      for (int j = 0; j < (int)R.size(); j++) {
        dp[i + j] = max(dp[i + j], L[i] + R[j] - a[p] * i * j * 2LL);
        dp[i + j + 1] =
            max(dp[i + j + 1], L[i] + R[j] + (long long)m * a[p] -
                                   a[p] * (2LL * (i + 1) * (j + 1) - 1));
      }
    }
    return dp;
  };
  cout << dfs(0, n - 1)[m] << "\n";
}
