#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  if (n >= 9)
    cout << (n - 9) / 10 + 1 << '\n';
  else
    cout << 0 << '\n';
}
int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
