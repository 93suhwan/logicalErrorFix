#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, ans;
  cin >> t;
  long long n, a;
  while (t--) {
    cin >> n;
    string a;
    cin >> a;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (i == n - 1 and a[i] != '0') {
        ans = ans + (long long)(a[i] - '0');
      } else if (a[i] != '0') {
        ans = ans + 1 + (long long)(a[i] - '0');
      }
    }
    cout << ans << endl;
  }
}
