#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  long long n, sum = 0, x;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 0)
      cout << "-1 1\n";
    else if (n > 0)
      cout << -n + 1 << " " << n << "\n";
    else
      cout << n << " " << -n - 1;
  }
}
