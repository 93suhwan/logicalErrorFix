#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long nextPowerOf2(long long n) {
  long long count = 0;
  if (n && !(n & (n - 1))) return n;
  while (n != 0) {
    n >>= 1;
    count += 1;
  }
  return 1 << count;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n - 1 << "\n";
    return;
  }
  long long a = nextPowerOf2(k);
  long long comp = log2(a);
  if (a >= n) {
    cout << comp << "\n";
    return;
  }
  long long pend;
  if (k == a) {
    pend = ((n - a) / k);
  } else {
    pend = ((n - a) / k) + 1;
  }
  if (a + k + k * (pend - 1) < n) {
    cout << comp + pend + 1 << "\n";
  } else
    cout << comp + pend << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
