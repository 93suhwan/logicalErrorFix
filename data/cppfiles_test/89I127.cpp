#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long M = 3e5 + 5;
const long double eps = 1e-6;
long long a[N];
void solve() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long fac = 2;
  for (int i = 1; i <= n; i++) {
    if (fac > 1e9) {
      cout << "YES"
           << "\n";
      return;
    }
    if (a[i] % fac == 0) {
      cout << "NO"
           << "\n";
      return;
    }
    fac *= i + 1;
  }
  cout << "YES"
       << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
