#include <bits/stdc++.h>
using namespace std;
long long int n, k, t, a[1000000], b[1000000], c, d, e, f, g;
vector<int> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
      cout << a[1] << "\n";
      continue;
    }
    sort(a + 1, a + n + 1);
    for (long long int i = 2; i <= n; i++) {
      b[i] = a[i] - a[i - 1];
    }
    b[1] = a[1];
    sort(b + 1, b + n + 1);
    cout << b[n] << "\n";
  }
}
