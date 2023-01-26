#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
void solve() {
  long n, k;
  cin >> n >> k;
  if (n == 0) {
    cout << 0 << endl;
    return;
  }
  if (k == 1) {
    cout << n - 1 << endl;
    return;
  }
  long c = 0;
  n--;
  long s = 1;
  while (s <= n and s <= k) {
    n -= s;
    c++;
    s *= 2;
  }
  if (n != 0 and n > k) {
    c += ceil(n / (k * 1.0));
  } else if (n != 0)
    c++;
  cout << c << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
