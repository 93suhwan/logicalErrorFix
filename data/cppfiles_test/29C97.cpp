#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, one = 0, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == 1)
        one++;
      else if (x == 0)
        z++;
    }
    long long int ans = one * pow(2, z);
    cout << ans << "\n";
  }
  return 0;
}
