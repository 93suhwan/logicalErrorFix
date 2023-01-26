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
        for (i = 2; i < n; i += 2) {
          if (ar[i - 1] > ar[i]) swap(ar[i - 1], ar[i]);
        }
      } else {
        for (i = 1; i < n; i += 2) {
          if (ar[i - 1] > ar[i]) swap(ar[i - 1], ar[i]);
        }
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
