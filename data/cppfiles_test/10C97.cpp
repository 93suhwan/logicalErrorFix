#include <bits/stdc++.h>
using namespace std;
void TEST_CASE() {
  long long n, k;
  cin >> n >> k;
  vector<long long> g[n + 1];
  vector<long long> ans(n + 1, -1);
  vector<long long> v(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> v[i];
    g[v[i]].push_back(i);
  }
  for (long long i = 1; i < n + 1; i++) {
    if ((long long)((g[i]).size()) >= k) {
      for (long long j = 0; j < k; j++) {
        long long pos = g[i][j];
        ans[pos] = j + 1;
      }
      for (long long j = k; j < (long long)((g[i]).size()); j++) {
        ans[g[i][j]] = 0;
      }
    }
  }
  vector<pair<long long, long long> > p;
  for (long long i = 1; i < n + 1; i++) {
    if ((long long)((g[i]).size()) < k && (long long)((g[i]).size()) > 0) {
      p.push_back({(long long)((g[i]).size()), i});
    }
  }
  sort((p).begin(), (p).end());
  vector<vector<long long> > r;
  for (long long i = 0; i < (long long)((p).size()); i++) {
    long long ind = p[i].second;
    vector<long long> te;
    for (long long j = 0; j < (long long)((g[ind]).size()); j++) {
      te.push_back(g[ind][j]);
    }
    r.push_back(te);
  }
  vector<long long> tot;
  for (long long i = 0; i < (long long)((r).size()); i++) {
    for (long long j = 0; j < (long long)((r[i]).size()); j++) {
      tot.push_back(r[i][j]);
    }
  }
  long long s = (long long)((tot).size());
  s = (s / k) * k;
  for (long long i = 0; i < s; i++) {
    long long num = i % k;
    ans[tot[i]] = num + 1;
  }
  for (long long i = s; i < (long long)((tot).size()); i++) {
    ans[tot[i]] = 0;
  }
  for (long long i = 1; i < n + 1; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    TEST_CASE();
  }
  return 0;
}
