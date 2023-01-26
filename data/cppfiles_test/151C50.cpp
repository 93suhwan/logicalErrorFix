#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  long long mx = 0;
  vector<long long> ty(t);
  vector<long long> a(t);
  vector<long long> b(t);
  for (long long i = 0; i < t; i++) {
    cin >> ty[i] >> a[i];
    mx = max(a[i], mx);
    if (ty[i] == 2) {
      cin >> b[i];
      mx = max(mx, b[i]);
    }
  }
  vector<long long> y(mx + 1);
  for (long long i = 0; i < mx + 1; i++) {
    y[i] = i;
  }
  vector<long long> ans;
  long long z = -1, k = -1;
  for (long long i = t - 1; i >= 0; i--) {
    if (ty[i] == 1) {
      ans.push_back(y[a[i]]);
    } else {
      y[a[i]] = y[b[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
