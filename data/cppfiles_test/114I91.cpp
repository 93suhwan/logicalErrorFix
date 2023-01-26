#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<long long> cc(n);
  vector<vector<long long>> aa(n);
  for (long long i = 0; i < n; ++i) {
    cin >> cc[i];
    aa[i].resize(cc[i]);
    for (long long j = cc[i] - 1; j >= 0; --j) cin >> aa[i][j];
  }
  long long m;
  cin >> m;
  vector<vector<long long>> bb(m, vector<long long>(n));
  for (long long i = 0; i < m; ++i)
    for (long long j = 0; j < n; ++j) {
      cin >> bb[i][j];
      bb[i][j] = cc[j] - bb[i][j];
    }
  sort(bb.begin(), bb.end());
  bb.push_back(vector<long long>());
  for (long long i = 0; i < n; ++i) bb.back().push_back(cc[i]);
  long long ans = 0;
  long long nulls_sum = 0;
  for (long long i = 0; i < n; ++i) nulls_sum += aa[i][0];
  if (m == 0) {
    for (long long i = 0; i < n; ++i) cout << "1 ";
    cout << "\n";
    return;
  }
  if (bb[0] != vector<long long>(n, 0)) {
    for (long long i = 0; i < n; ++i) cout << "1 ";
    cout << "\n";
    return;
  }
  vector<long long> our_build;
  for (long long l = 0; l < m; ++l) {
    vector<long long> v1 = bb[l], v2 = bb[l + 1];
    long long ind_dif = n;
    for (long long i = 0; i < n; ++i)
      if (v1[i] != v2[i]) ind_dif = min(i, ind_dif);
    if (ind_dif == n) continue;
    vector<long long> cur_build = v1;
    cur_build[ind_dif] = v1[ind_dif] + 1;
    for (long long i = ind_dif + 1; i < n; ++i) cur_build[i] = 0;
    for (long long i = ind_dif; i < n; ++i) {
      if (cur_build == v2 || cur_build[i] >= cc[i]) {
        --cur_build[i];
        if (i + 1 < n) cur_build[i + 1] = v1[i + 1] + 1;
        continue;
      }
      long long cur_sum = 0;
      for (long long j = 0; j < n; ++j) cur_sum += aa[j][cur_build[j]];
      if (ans < cur_sum) {
        ans = cur_sum;
        our_build = cur_build;
      }
      --cur_build[i];
      if (i + 1 < n) cur_build[i + 1] = v1[i + 1] + 1;
    }
  }
  for (long long i = 0; i < n; ++i) cout << cc[i] - our_build[i] << " ";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
