#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
long long a[maxn];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans = max(ans, a[i] - i - 1);
    }
    if (ans < 0) ans = 0;
    cout << ans << endl;
  }
}
