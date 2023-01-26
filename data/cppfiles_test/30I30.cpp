#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int calc(string s, int n, char c) {
  set<int> cs;
  vector<pair<char, int>> v;
  int cntc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == c) {
      cs.insert(i);
      cntc++;
    } else
      v.push_back({s[i], i});
  }
  if ((int)(v.size()) == 0) return 0;
  n = (int)(v.size());
  int cnt = 0;
  int l, r;
  l = n / 2 - 1;
  r = n - n / 2;
  for (int i = 0; i < n / 2; i++) {
    if (v[l - i].first != v[r + i].first) return INT_MAX;
    int tmpl = v[l - i].second + 1, tmpr = v[r + i].second - 1;
    while (cs.count(tmpl) and cs.count(tmpr) and tmpl <= tmpr) {
      tmpl++;
      tmpr--;
      if (tmpl == tmpr)
        cnt++;
      else
        cnt += 2;
    }
  }
  return cntc - cnt;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = INT_MAX;
  for (int i = 0; i < 26; i++) ans = min(ans, calc(s, n, 'a' + i));
  if (ans == INT_MAX)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
