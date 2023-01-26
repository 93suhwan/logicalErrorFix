#include <bits/stdc++.h>
using namespace std;
void solve(int tc) {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (n % 2 == 0) {
    int v = (n / 2) * (m - 1);
    if (k <= v && k % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (m % 2 == 0) {
    int h = (m / 2) * (n - 1);
    int rv = ((n * m) / 2) - k;
    if (rv <= h && rv % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1, u = 1;
  cin >> t;
  while (t--) solve(u++);
  return (0);
}
