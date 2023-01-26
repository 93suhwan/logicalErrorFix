#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const int mod = 1e9 + 7;
const int moh = 1e9 + 3;
const int base = 311;
const int oi = 2e9;
const long long oo = 1e18;
const double eps = 1e-9;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
string s;
void solve() {
  cin >> n >> s;
  string t;
  s = " " + s;
  t = s;
  int ans = 0;
  sort(s.begin() + 1, s.end());
  for (int i = 1; i <= n; i++) {
    if (s[i] - t[i]) {
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
