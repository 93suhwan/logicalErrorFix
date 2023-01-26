#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int modI(long long int a, long long int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x % 1000000007;
}
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] != s[n - 1]) {
    s[n - 1] = s[0];
  }
  cout << s << endl;
}
int main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t--) solve();
}
