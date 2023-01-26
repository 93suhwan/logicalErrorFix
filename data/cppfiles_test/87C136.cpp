#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[102];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    if (i - a[i] + res >= 0)
      continue;
    else
      res = a[i] - i;
  }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
