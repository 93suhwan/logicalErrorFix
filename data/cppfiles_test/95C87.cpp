#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void run_case(int test) {
  int n, m;
  cin >> n >> m;
  vector<long long> to_hash(n);
  for (int i = 0; i < n; i++) to_hash[i] = rng();
  long long sum_xor = 0;
  for (int i = 0; i < n; i++) sum_xor ^= to_hash[i];
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<long long>> _hash_max(n, vector<long long>(m));
  auto _hash_min = _hash_max;
  vector<vector<pair<int, int>>> inters(n, vector<pair<int, int>>(m));
  for (int j = 0; j < m; j++) {
    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
      ids[i] = i;
    }
    sort(ids.begin(), ids.end(),
         [&](int lhs, int rhs) { return a[lhs][j] < a[rhs][j]; });
    for (int i = 0; i + 1 < n; i++) {
      inters[i][j] = make_pair(a[ids[i]][j], a[ids[i + 1]][j]);
      _hash_min[i][j] = (i > 0 ? _hash_min[i - 1][j] : 0LL) ^ to_hash[ids[i]];
      _hash_max[n - i - 2][j] = sum_xor ^ _hash_min[i][j];
    }
  }
  pair<int, int> ans = make_pair(-1, -1);
  for (int i = 0; i + 1 < n; i++) {
    int cnt_l = 0;
    int mn_mx = inters[i][0].second;
    int mx_mn = inters[i][0].first;
    for (int j = 0; j + 1 < m; j++) {
      mn_mx = min(mn_mx, inters[i][j].second);
      mx_mn = max(mx_mn, inters[i][j].first);
      if (mn_mx <= mx_mn) break;
      if (_hash_min[i][j] == _hash_min[i][0]) {
        cnt_l++;
      } else {
        break;
      }
    }
    int cnt_r = 0;
    mn_mx = inters[n - i - 2][m - 1].second;
    mx_mn = inters[n - i - 2][m - 1].first;
    for (int j = m - 1; j > 0; j--) {
      mn_mx = min(mn_mx, inters[n - i - 2][j].second);
      mx_mn = max(mx_mn, inters[n - i - 2][j].first);
      if (mn_mx <= mx_mn) break;
      if (_hash_max[i][j] == _hash_min[i][0]) {
        cnt_r++;
      } else {
        break;
      }
    }
    if (cnt_l + cnt_r >= m) {
      ans = make_pair(i, cnt_l);
    }
  }
  if (ans.first == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  string res(n, 'R');
  vector<int> ids(n);
  for (int i = 0; i < n; i++) {
    ids[i] = i;
  }
  sort(ids.begin(), ids.end(),
       [&](int lhs, int rhs) { return a[lhs][0] < a[rhs][0]; });
  for (int i = 0; i <= ans.first; i++) {
    res[ids[i]] = 'B';
  }
  cout << res << ' ' << ans.second << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  int tests = 1;
  cin >> tests;
  for (int test = 1; test <= tests; test++) run_case(test);
  return 0;
}
