#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long A[n];
    long long ans = 0;
    for (int i = 0; i <= n - 1; i++) {
      cin >> A[i];
      if (A[i] == 0 && A[i - 1] == 0) {
        ans = -1;
      }
    }
    if (ans == -1) {
      cout << ans << endl;
    } else {
      ans = 1;
      long long s = 0;
      for (int i = 0; i <= n - 1; i++) {
        if (A[i] == 1) {
          s += 1;
        } else {
          ans = ans + (s / 2) * 6 + s % 2;
          s = 0;
        }
      }
      ans = ans + (s / 2) * 6 + s % 2;
      cout << ans << endl;
    }
  }
  return 0;
}
