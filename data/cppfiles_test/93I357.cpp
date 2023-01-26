#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  n--;
  long long temp = 1;
  long long cnt = 0;
  while (temp < k) {
    n -= temp;
    temp *= 2;
    cnt++;
    if (n <= 0) {
      cout << cnt << "\n";
      return;
    }
  }
  cout << cnt + ceil((long double)n / k) << "\n";
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
