#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int x, long long int y) {
  long long int res = x * y;
  return (res >= 1000000007 ? res % 1000000007 : res);
}
long long int power(long long int x, long long int y) {
  if (y < 0) return 1;
  long long int res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  int c = count(s.begin(), s.end(), 'B');
  if (c * 2 == s.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
