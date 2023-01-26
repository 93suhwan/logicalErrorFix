#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
clock_t begtime = clock();
using namespace std;
ull power(ull x, ull y, ull p) {
  ull res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  ll k;
  cin >> k;
  ll temp = sqrt(k);
  if (temp * temp == k) {
    cout << temp << " " << 1;
    return;
  }
  ll x, y;
  if (k - temp * temp <= temp + 1)
    cout << k - temp * temp << " " << temp + 1;
  else
    cout << temp + 1 << " " << 2 * temp - (k - temp * temp) + 2;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
