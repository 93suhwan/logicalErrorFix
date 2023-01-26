#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int x, y, z, w;
  if (n % 6 == 0) {
    cout << (n / 6) * 15 << "\n";
    return;
  }
  if (n % 8 == 0) {
    cout << (n / 8) * 20 << "\n";
    return;
  }
  if (n % 10 == 0) {
    cout << (n / 10) * 25 << "\n";
    return;
  }
  if (n % 14 == 0) {
    cout << (n / 14) * 35 << "\n";
  }
  x = n / 6;
  y = n / 8;
  z = n / 10;
  w = n / 14;
  long long int p, q, r, s;
  p = (x + 1) * 6 - n;
  q = (y + 1) * 8 - n;
  r = (z + 1) * 10 - n;
  s = (w + 1) * 14 - n;
  if (p <= q && p <= r && p <= s) {
    cout << (x + 1) * 15 << "\n";
    return;
  }
  if (q <= r && q <= p && q <= s) {
    cout << (y + 1) * 20 << "\n";
    return;
  }
  if (r <= q && r <= p && r <= s) {
    cout << (z + 1) * 25 << "\n";
    return;
  }
  if (s <= r && s <= q && s <= p) {
    cout << (w + 1) * 35 << "\n";
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
