#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int x = (r / 2) + 1;
  if (x >= l)
    cout << r % x << "\n";
  else
    cout << r % l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
