#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long c = 0, t = 1;
  long long f = 0;
  while (!is_sorted(a, a + n)) {
    f = 1;
    if (t % 2) {
      for (long long i = 0; i <= n - 2; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          f = 0;
        }
      }
    } else {
      for (long long i = 1; i <= n - 2; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          f = 0;
        }
      }
    }
    t++;
    c++;
  }
  cout << c << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
