#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
inline void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> sum(n + 1, 0);
  for (int i = 1; i <= s.length(); i++) {
    if (i & 1) {
      sum[i] = sum[i - 1] + (s[i - 1] == '+' ? -1 : 1);
    } else {
      sum[i] = sum[i - 1] + (s[i - 1] == '+' ? 1 : -1);
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r, q;
    cin >> l >> r;
    q = sum[r] - sum[l - 1];
    if (q == 0) {
      cout << 0 << "\n";
    } else if ((r - l + 1) & 1) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
