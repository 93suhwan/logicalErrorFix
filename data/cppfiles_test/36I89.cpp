#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e18;
const char nl = '\n';
void CP() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
void solve() {
  int n;
  cin >> n;
  string res = "";
  n = n / 2;
  for (int i = 0; i < (n); ++i) res += 'a';
  res += 'b';
  n--;
  for (int i = 0; i < (n); ++i) res += 'a';
  if (n & 1) res += 'c';
  cout << res << nl;
}
int main() {
  CP();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
