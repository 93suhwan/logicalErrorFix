#include <bits/stdc++.h>
using namespace std;
long long t;
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long res = 0;
  for (long long i = n; i >= 1; i--) {
    if (a[i] > i) {
      res += (a[i] - i);
      if ((n + res) >= a[i]) break;
    }
  }
  cout << res << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
