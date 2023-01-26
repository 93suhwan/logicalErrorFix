#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long res = sqrt(n);
  res = res * res;
  long long ans = ceil((double)sqrt(n));
  if (n - res == 0) {
    cout << ans << " " << 1 << endl;
  } else if (n - res <= ans) {
    cout << n - res << " " << ans << endl;
  } else {
    cout << ans << " " << ans * ans - n + 1 << endl;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
