#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<vector<long long>> h(n, vector<long long>(26, 0));
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (auto x : s[i]) h[i][x - 'a']++;
  }
  int ans = 0;
  for (int let = 0; let < 26; ++let) {
    vector<long long> val(n);
    for (int i = 0; i < n; ++i) val[i] = h[i][let] - (s[i].size() - h[i][let]);
    sort((val).begin(), (val).end());
    reverse((val).begin(), (val).end());
    int cnt = 0, s = 0;
    for (int i = 0; i < n; ++i) {
      s += val[i];
      if (s > 0)
        ++cnt;
      else
        break;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
