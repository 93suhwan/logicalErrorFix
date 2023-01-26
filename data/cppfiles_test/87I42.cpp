#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
long long a[maxn];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    long long maxn = -0x3f3f3f3f, pos = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] >= maxn) {
        maxn = a[i];
        pos = i;
      }
    }
    long long ans = maxn - pos - 1;
    if (maxn - pos - 1 < 0) ans = 0;
    cout << ans << endl;
  }
}
