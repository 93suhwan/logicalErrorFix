#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int row, col, ans, k, temp, t;
  cin >> t;
  while (t--) {
    cin >> k;
    ans = sqrt(k);
    if (ans * ans == k)
      cout << ans << " " << 1 << endl;
    else {
      temp = ans + 1;
      if (ans * ans + temp >= k)
        cout << k - ans * ans << " " << temp << endl;
      else
        cout << temp << " " << (temp * temp) - k + 1 << endl;
    }
  }
  return 0;
}
