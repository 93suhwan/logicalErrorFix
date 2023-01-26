#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
void solve() {
  long long n, k, i, ans = 0, l, r;
  string s;
  cin >> n >> k >> s;
  vector<long long> e(n + 1), o(n + 1);
  for (i = 1; i <= n; i++) {
    e[i] = e[i - 1];
    o[i] = o[i - 1];
    if (i % 2)
      o[i] += s[i - 1] == '+' ? 1 : -1;
    else
      e[i] += s[i - 1] == '+' ? 1 : -1;
  }
  for (i = 0; i < k; i++) {
    cin >> l >> r;
    long long x = r - l;
    if (x % 2 == 0) {
      cout << 1 << "\n";
    } else if (e[r] - e[l - 1] + o[l - 1] - o[r] == 0) {
      cout << 0 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
