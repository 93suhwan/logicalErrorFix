#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 1, mod = 1e9 + 7;
void solve() {
  long long q;
  cin >> q;
  vector<long long> tmp;
  vector<vector<long long>> vv;
  for (long long i = 0; i < q; i++) {
    long long tt;
    cin >> tt;
    long long x, y;
    if (tt == 1) {
      cin >> x;
      tmp = {tt, x};
      vv.push_back(tmp);
    } else {
      cin >> x >> y;
      tmp = {tt, x, y};
      vv.push_back(tmp);
    }
  }
  vector<long long> ar(N);
  for (long long i = 0; i < N; i++) {
    ar[i] = i;
  }
  vector<long long> ans;
  for (long long i = q - 1; i >= 0; i--) {
    if (vv[i].size() == 2) {
      ans.push_back(ar[vv[i][1]]);
    } else {
      ar[vv[i][1]] = ar[vv[i][2]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
