#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> c[n + 1];
  for (long long i = 1; i <= n; i++) {
    long long cnt;
    cin >> cnt;
    while (cnt--) {
      long long tp;
      cin >> tp;
      c[i].push_back(tp);
    }
  }
  long long m;
  cin >> m;
  vector<long long> v[m + 1];
  set<vector<long long> > ban;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j < n; j++) {
      long long tp;
      cin >> tp;
      v[i].push_back(tp);
    }
    ban.insert(v[i]);
  }
  vector<long long> tp;
  for (long long i = 1; i <= n; i++) tp.push_back(c[i].size());
  if (ban.find(tp) == ban.end()) {
    for (long long i : tp) cout << i << ' ';
    cout << '\n';
    return 0;
  }
  long long mx = 0;
  vector<long long> ans;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j < n; j++) {
      v[i][j]--;
      if (v[i][j]) {
        long long sum = 0;
        for (long long k = 0; k < n; k++) sum += c[k + 1][v[i][k] - 1];
        if (sum > mx) {
          mx = sum;
          ans = v[i];
        }
      }
      v[i][j]++;
    }
  }
  for (long long i : ans) cout << i << ' ';
  cout << '\n';
}
