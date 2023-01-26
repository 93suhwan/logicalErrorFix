#include <bits/stdc++.h>
using namespace std;
void input() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (n % 2) {
    long long int rem = (n * m) / 2 - k;
    if (rem % 2) {
      cout << "NO\n";
      return;
    }
    if (((n - 1) * m / 2) < rem) {
      cout << "NO\n";
      return;
    }
  } else {
    if (m % 2) {
      m -= 1;
    }
    if ((k) % 2 != 0 || (2 * k) > (n * m)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    input();
  }
  return 0;
}
