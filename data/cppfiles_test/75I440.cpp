#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<long long int, long long int> > ans;
  for (int i = 0; i <= n - 1; i++) {
    int k;
    cin >> k;
    vector<long long int> a(k);
    for (auto &i : a) cin >> i;
    ;
    long long int mx = INT_MIN;
    for (int j = 0; j <= k - 1; j++) {
      long long int req = a[j] + 1 - j;
      if (req > mx) {
        mx = req;
      }
    }
    ans.push_back({mx, -k});
  }
  sort(ans.begin(), ans.end());
  long long int diff = 0;
  long long int out = ans[0].first - ans[0].second;
  long long int s = ans.size();
  for (int i = 1; i <= s - 1; i++) {
    if (out >= ans[i].first) {
      out -= ans[i].second;
    } else {
      diff = max(diff, ans[i].first - out);
      out = ans[i].first - ans[i].second;
    }
  }
  cout << diff + ans[0].first << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
