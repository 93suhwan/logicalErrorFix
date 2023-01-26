#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int x[n];
    for (int i = 0; i < n; ++i) cin >> x[i];
    string s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];
    int ans = INT_MIN;
    vector<int> bperm;
    for (int i = 0; i < (1 << n); ++i) {
      int d = 0;
      for (int j = 0; j < n; ++j) {
        d += (((i >> j)&1) ? -x[j] : x[j]);
      }
      pair<int,int> kv[m] = {};
      for (int j = 0; j < m; ++j) {
        kv[j].second = j;
        for (int k = 0; k < n; ++k) {
          if (s[k][j] == '1') {
            kv[j].first += (((i >> j)&1) ? 1 : -1);
          }
        }
      }
      sort(kv, kv+m);
      for (int j = 1; j <= m; ++j) {
        d += kv[j-1].first*j;
      }
      if (d > ans) {
        ans = d;
        vector<int> perm(m);
        for (int j = 0; j < m; ++j) {
          perm[kv[j].second] = j+1;
        }
        bperm = perm;
      }
    }
    for (int i : bperm) cout << i << ' ';
    cout << endl;
  }
}