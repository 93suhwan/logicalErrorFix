#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long n, m;
    n = sqrt(k);
    if (k != n * n) n++;
    m = n * n;
    long long i, j;
    if (abs(k - m) < n) {
      j = abs(k - m) + 1;
      i = n;
    } else {
      j = n;
      i = abs((m - (2 * n - 2)) - k) + 1;
    }
    cout << i << " " << j;
    cout << endl;
  }
  return 0;
}
