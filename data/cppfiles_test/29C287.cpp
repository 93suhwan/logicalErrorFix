#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x == 0) cnt0++;
      if (x == 1) cnt1++;
    }
    cout << ((1ll) << cnt0) * (long long)cnt1 << endl;
  }
}
