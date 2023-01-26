#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const long long INF = 1e18;
using namespace std;
void solve() {
  long long n, cur = 0;
  cin >> n;
  vector<pair<long long, long long> > v(n), pos;
  vector<long long> ans;
  for (int i = (int)0; i < (int)n; ++i) {
    long long x;
    cin >> x;
    v[i] = make_pair(x, i);
  }
  sort(v.begin(), v.end());
  for (int i = (int)0; i < (int)n; ++i) {
    long long shift = v[i].second - i;
    for (int j = (int)i + 1; j < (int)n; ++j) {
      v[j].second -= shift;
      if (v[j].second < i) v[j].second += n - i;
    }
    if (shift != 0) {
      ans.push_back(shift);
      pos.push_back(make_pair(i + 1, n));
    }
  }
  cout << ans.size() << endl;
  for (int i = (int)0; i < (int)ans.size(); ++i) {
    cout << pos[i].first << " " << pos[i].second << " " << ans[i] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
