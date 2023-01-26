#include <bits/stdc++.h>
using namespace std;
const long long INFll = (long long)1e18 + 10;
const int INFii = (int)1e9 + 10;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += s[i] - '0';
    if (s[i] != '0' && i != n - 1) ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
}
