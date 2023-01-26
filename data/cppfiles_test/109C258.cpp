#include <bits/stdc++.h>
using namespace std;
const int maxn = 400505;
const int inf = 0x3f3f3f3f;
int n, m, k;
void YES() {
  cout << "YES"
       << "\n";
}
void NO() {
  cout << "NO"
       << "\n";
}
void solve() {
  string s;
  cin >> n;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
    if (s[i] != '0') ans += s[i] - '0' + 1;
  ans += s[n - 1] - '0';
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tn = 1;
  cin >> tn;
  for (int __ = 1; __ <= tn; __++) {
    solve();
  }
}
