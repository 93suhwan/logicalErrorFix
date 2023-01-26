#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const long long int INF = 1e18;
void solve() {
  long long int n;
  cin >> n;
  char v[n + 1];
  vector<pair<char, long long int> > c(n + 1);
  for (long long int i = 1; i <= n; i++) {
    char r;
    cin >> r;
    v[i] = r;
    c[i].first = r;
    c[i].second = i;
  }
  sort(c.begin(), c.end());
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    if (i != c[i].second) ans++;
  }
  for (long long int i = 1; i <= n; i++) {
    if (v[i] == c[i].first && c[i].second != i) ans--;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC = 1, t = 0;
  cin >> TC;
  while (t++ < TC) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
