#include <bits/stdc++.h>
using namespace std;
unsigned long long fun(unsigned long long n) {
  if (n < 10) return n;
  return n % 10 + fun(n / 10);
}
void xal_qil(unsigned long long n, unsigned long long k) {
  if (k == 0) return;
  k--;
  while (k--) {
    int f = 1, q;
    while (n % f == 0) f *= 10;
    f /= 10;
    cout << f << " ";
    n -= f;
  }
  cout << n;
  return;
}
void solve() {
  int n, k;
  cin >> n >> k;
  if (fun(n) >= k) {
    xal_qil(n, k);
    return;
  }
  while (fun(n) < k) {
    unsigned long long f = 1;
    while (f < n) f *= 10;
    f /= 10;
    cout << f << " ";
    n -= f;
    k--;
  }
  xal_qil(n, k);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
