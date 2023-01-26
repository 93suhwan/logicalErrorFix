#include <bits/stdc++.h>
using namespace std;
long long pow1(long long a, long long b) {
  long ans = 1;
  while (b != 0) {
    if ((b & 1) != 0) {
      ans = (ans * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b = b >> 1;
  }
  return ans;
}
void solve() {
  int n, m, a, b, c, d, ma = INT_MAX, temp;
  cin >> n >> m >> a >> b >> c >> d;
  if (a == c || b == d)
    cout << "0\n";
  else {
    if (c > a)
      ma = c - a;
    else
      ma = (n - a) + (n - c);
    if (d > b)
      ma = min(ma, d - b);
    else
      ma = min(m - b + m - d, ma);
    cout << ma << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
