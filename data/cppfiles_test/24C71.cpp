#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, check;
  cin >> n;
  if (n < 9) {
    cout << 0 << endl;
  } else {
    n += 1;
    cout << n / 10 << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
