#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cin >> b[i];
      a[i] -= 1;
      b[i] -= 1;
    }
    vector<int> ca(n), cb(n);
    for (int i = 0; i < n; i++) {
      ca[a[i]] += 1;
      cb[b[i]] += 1;
    }
    long long ans = (long long)n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++) {
      ans -= 1LL * (ca[a[i]] - 1) * (cb[b[i]] - 1);
    }
    cout << ans << '\n';
  }
}
