#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long p;
    if (n % 2 == 0) {
      p = n / 2;
    } else {
      p = n / 2 + 1;
    }
    p = n - p + 1;
    long long ans = s / p;
    cout << ans << endl;
  }
  return 0;
}
