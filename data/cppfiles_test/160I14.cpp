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
    if (b < d) {
      temp = d - b;
      ma = min(ma, temp);
    }
    if (a < c) {
      temp = c - a;
      ma = min(ma, temp);
    }
    if (a > c && b > d) {
      temp = (m - a) + (m - c);
      ma = min(ma, temp);
    }
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
