#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count_1 = 0, count_0 = 0, sum = 0;
    while (n--) {
      int x;
      cin >> x;
      sum += x;
      if (x == 0)
        count_0++;
      else if (x == 1)
        count_1++;
    }
    long long ans = count_1 * (1ll << count_0);
    cout << ans << "\n";
  }
}
