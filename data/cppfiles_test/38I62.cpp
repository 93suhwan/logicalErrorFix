#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, ans = 0, mn = INT_MAX, sum;
    cin >> n;
    ans += (n / 120) * 300;
    n %= 120;
    for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 16; j++) {
        for (int k = 0; k < 21; k++) {
          long long int val = 10 * i + 8 * j + 6 * k;
          if (val >= n && val - n < mn) {
            sum = val;
            mn = val - n;
          }
        }
      }
    }
    ans += (sum * 5) / 2;
    cout << ans << endl;
  }
  return 0;
}
