#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, ans = 0;
    cin >> n;
    long long int ar[n + 1];
    for (i = 0; i < n; i++) {
      cin >> ar[i];
    }
    while (!is_sorted(ar, ar + n)) {
      if (ans & 1) {
        for (i = 1; i < n - 1; i += 2) {
          if (ar[i] > ar[i + 1]) swap(ar[i], ar[i + 1]);
        }
      } else {
        for (i = 0; i < n - 1; i += 2) {
          if (ar[i] > ar[i + 1]) swap(ar[i], ar[i + 1]);
        }
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
