#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool cmp(int a, int b) { return a > b; }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int b = 0, c = 0;
  b = (a[2] / 2) * 3;
  c = (a[2] - a[2] / 2) * 3;
  if (b >= c) {
    b += (a[1] / 2) * 2;
    c += (a[1] - a[1] / 2) * 2;
  } else {
    c += (a[1] / 2) * 2;
    b += (a[1] - a[1] / 2) * 2;
  }
  if (b >= c) {
    b += a[0] / 2;
    c += (a[0] - a[0] / 2);
  } else {
    c += a[0] / 2;
    b += (a[0] - a[0] / 2);
  }
  cout << abs(b - c);
}
int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
