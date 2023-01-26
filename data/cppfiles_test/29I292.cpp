#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      if (a == 1)
        one++;
      else if (a == 0)
        zero++;
    }
    long long ans = (zero * (zero + 1)) / 2;
    ans += (one * (one + 1)) / 2;
    cout << ans << endl;
  }
}
