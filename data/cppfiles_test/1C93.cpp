#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, k, even, odd, ans, c, c0, c1;
  cin >> n;
  vector<long long> x(n), y(n), ct(4, 0), sig(n);
  ans = 0;
  even = 0;
  odd = 0;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    if (x[i] % 4 == 0) sig[i]++;
    if (y[i] % 4 == 0) sig[i] += 2;
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (sig[i] == sig[j])
        ans += i;
      else
        ans += ct[sig[i]] + ct[sig[j]];
    }
    ct[sig[i]]++;
  }
  cout << ans << "\n";
  return 0;
}
