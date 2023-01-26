#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &a, const vector<long long> &b) {
  for (auto k : b) cout << k << " ";
  cout << endl;
  return a;
}
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
char nl = '\n';
long long mod = 1e9 + 7;
long long inf = 2e9;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  reverse((s).begin(), (s).end());
  for (long long i = 0; i < ((long long)(s).size()); i++) {
    bool good = 1;
    for (long long u = i; u < ((long long)(s).size()); u++) {
      if (s[i] < s[u]) {
        good = 0;
      }
    }
    if (!good) {
      ans++;
    }
  }
  if (ans > 0) ans++;
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
