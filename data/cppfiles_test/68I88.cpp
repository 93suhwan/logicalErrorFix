#include <bits/stdc++.h>
using namespace std;
short TESTS;
long long k;
inline void solve() {
  cin >> k;
  long long n = sqrt(k), mij = n * n + n + 1;
  if (k <= mij)
    cout << k - n * n << " " << n + 1 << "\n";
  else
    cout << n + 1 << " " << (n + 1) * (n + 1) - k + 1 << "\n";
}
int main() {
  cin >> TESTS;
  while (TESTS--) solve();
  return 0;
}
