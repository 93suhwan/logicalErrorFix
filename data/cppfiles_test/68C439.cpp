#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k;
  cin >> k;
  if (sqrt(k) == int(sqrt(k))) {
    cout << (long long)sqrt(k) << " " << 1 << "\n";
    return;
  }
  long long sqr = sqrt(k);
  long long r, c;
  if (k <= sqr * sqr + sqr + 1) {
    c = sqr + 1;
    r = sqr + 1 - (sqr * sqr + sqr + 1 - k);
  } else {
    c = sqr + 1 - (k - (sqr * sqr + sqr + 1));
    r = sqr + 1;
  }
  cout << r << " " << c << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
