#include <bits/stdc++.h>
using namespace std;
long long t;
void solve() {
  long long n, k;
  cin >> n >> k;
  k++;
  long long a[n + 1];
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n - 1; i++) {
    if (k < pow(10, a[i + 1] - a[i])) {
      res += k * pow(10, a[i]);
      cout << res << endl;
      return;
    }
    res += pow(10, a[i + 1]) - pow(10, a[i]);
    k -= pow(10, a[i + 1] - a[i]) - 1;
  }
  cout << res + (long long)pow(10, a[n]) * k << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
