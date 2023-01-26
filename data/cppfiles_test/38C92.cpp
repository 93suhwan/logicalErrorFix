#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const bool TEST = true;
void solve() {
  ll n;
  cin >> n;
  if (n <= 6) {
    cout << 15 << endl;
    return;
  }
  if (n <= 8) {
    cout << 20 << endl;
    return;
  }
  if (n <= 10) {
    cout << 25 << endl;
    return;
  }
  cout << 1LL * ((n + 1) / 2) * 5 << endl;
}
int main() {
  int t;
  if (TEST)
    cin >> t;
  else
    t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
