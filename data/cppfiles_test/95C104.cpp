#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 1e6 + 5;
long long int t, n, m, a[N] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, j, k, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    while (k > 1) {
      x = 1e10;
      while ((n - x) < (k - 1)) x /= 10;
      cout << x << " ";
      k--;
      n -= x;
    }
    cout << n << '\n';
  }
  return 0;
}
