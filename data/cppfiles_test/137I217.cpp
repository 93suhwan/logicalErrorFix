#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 0x3f3f3f3f;
const double eps = 1e-5;
const long long modn = 1e9 + 7;
const long long N = 1e6 + 5;
bool fl = 0;
long long tot = 0;
long long tot2 = 0;
string rev(string s) {
  while (s.back() == '0') s.pop_back();
  reverse(s.begin(), s.end());
  return s;
}
string toer(long long x) {
  string s = "";
  while (x) {
    s += x % 2 + '0';
    x /= 2;
  }
  string st = "";
  for (long long i = s.length() - 1; i >= 0; i--) st += s[i];
  return st;
}
void dfs(string now, long long y, long long sl) {
  if (sl > 10) {
    return;
  }
  if (now == toer(y)) {
    fl = 1;
    return;
  }
  string s = now;
  string s1 = s + '1';
  string s2 = s + '0';
  s1 = rev(s1);
  s2 = rev(s2);
  dfs(s1, y, sl + 1);
  dfs(s2, y, sl + 1);
}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES" << '\n';
    return;
  }
  dfs(toer(x), y, 0);
  if (fl) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long _ = 1;
  while (_--) {
    solve();
  }
  return 0;
}
