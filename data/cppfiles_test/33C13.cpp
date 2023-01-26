#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n, last, mx = 0, val;
  cin >> n;
  cin >> last;
  while (--n) {
    cin >> val;
    mx = max(mx, last * val);
    last = val;
  }
  cout << mx << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
