#include <bits/stdc++.h>
using namespace std;
int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
const int N = 1e5;
void solve() {
  long long int n, x;
  cin >> n;
  map<long long int, long long int> m;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    if (x <= 1) m[x]++;
  }
  cout << (1LL << m[0]) * m[1] << endl;
}
int32_t main() {
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
