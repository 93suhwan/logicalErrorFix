#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long t = 0, s = 1;
  while (n - s > 0 && s <= k) s <<= 1, t++;
  t += (n - s + k - 1) / k;
  cout << t << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
