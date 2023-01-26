#include <bits/stdc++.h>
using namespace std;
long long absk(long long k) {
  if (k < 0) {
    return -k;
  }
  return k;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1000000000) {
    cout << 32591;
    return;
  }
  long long k1 = (long long)pow(n, 1.0 / 2),
            k2 = (long long)pow((long long)n, 1.0 / 3),
            k3 = (long long)pow(n, 1.0 / 6);
  long long ans = k1 + k2 - k3;
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long w;
  cin >> w;
  while (w--) {
    solve();
    cout << "\n";
  }
}
