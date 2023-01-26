#include <bits/stdc++.h>
const long long M = 1e9 + 7;
const long long N = 2e5 + 5;
const long long MIN = -1e18;
const long long MAX = 1e18;
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n <= 6) {
    cout << 15 << endl;
    return;
  }
  long long z = n / 6;
  long long w = n % 6;
  long long p = w / 2 + (w % 2 != 0);
  long long ans = 0;
  ans = (z - p) * 15 + p * 20;
  cout << ans << endl;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
