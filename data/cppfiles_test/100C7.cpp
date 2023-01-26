#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    vector<long long> p;
    for (int i = 0; i <= n - 1; i += 1) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long k = 0, x = (-1) * 1000000007;
    for (int i = 0; i <= n - 1; i += 1) {
      a[i] -= k;
      x = max(x, a[i]);
      k += a[i];
    }
    cout << x << "\n";
  }
}
