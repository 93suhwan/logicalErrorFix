#include <bits/stdc++.h>
const int N = 1e7 + 64;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
using namespace std;
char prime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int to_int(string x) {
  int res = 0;
  for (auto it : x) res *= 10, res += it - '0';
  return res;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  pair<pair<int, int>, pair<int, int>> ans;
  if (s.find('0') == string::npos)
    ans = {{1, n - 1}, {2, n}};
  else {
    string t = s;
    reverse(t.begin(), t.end());
    int pos = s.size() - t.find('0');
    if (pos >= n / 2) {
      ans = {{1, pos}, {1, pos - 1}};
    } else {
      ans = {{pos + 1, n - 1}, {pos + 2, n}};
    }
  }
  cout << ans.first.first << ' ' << ans.first.second << ' ' << ans.second.first
       << ' ' << ans.second.second << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int qq;
  cin >> qq;
  while (qq--) solve();
  return 0;
}
