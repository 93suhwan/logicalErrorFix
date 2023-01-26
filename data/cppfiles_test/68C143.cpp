#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int mI = INT_MAX;
bool solve() {
  long long k;
  cin >> k;
  long long p = 0;
  for (long long i = 1; i < 100000; i++) {
    if (i * i >= k) {
      p = i;
      break;
    }
  }
  long long r, c;
  long long top = (p - 1) * (p - 1) + 1;
  long long dif = min(p * p - k + 1, p);
  c = dif;
  r = min(k - top + 1, p);
  cout << r << " " << c << "\n";
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
