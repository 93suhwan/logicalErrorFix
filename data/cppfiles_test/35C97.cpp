#include <bits/stdc++.h>
using namespace std;
bool check(long long n, long long m, long long low, long long mid) {
  long long o = (mid - 1 - low);
  long long z1 = ((low ^ n) / (o + 1)) * (o + 1);
  long long z2 = z1 + o;
  return (z2 <= m);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long low = 0;
    long long up = (1LL << 31);
    while (true) {
      if ((up - low) == 1) {
        cout << low << '\n';
        break;
      }
      long long mid = (low + up) / 2;
      if (check(n, m, low, mid))
        low = mid;
      else
        up = mid;
    }
  }
  return 0;
}
