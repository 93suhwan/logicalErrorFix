#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 1) {
      n++;
    }
    long long keqing = 15;
    long long ans = max(keqing, n / 2 * 5);
    cout << ans << "\n";
  }
}
