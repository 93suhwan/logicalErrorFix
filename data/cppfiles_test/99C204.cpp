#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, n;
  cin >> x >> n;
  if (n % 4 == 0) {
    cout << x << endl;
    return;
  }
  long long int curr = x;
  for (long long int i = 1; i < n % 4 + 1; i++) {
    if (curr % 2 == 0)
      curr -= (n / 4) * 4 + i;
    else
      curr += (n / 4) * 4 + i;
  }
  cout << curr << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}
