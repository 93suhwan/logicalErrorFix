#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  double n, s, ans;
  while (t--) {
    cin >> n >> s;
    int location = ceil(n / 2);
    for (int i = 0; i <= s; i++) {
      if (i * (n - location + 1) > s)
        break;
      else if (n == 1) {
        ans = s;
        break;
      } else
        ans = i;
    }
    cout << ans << "\n";
  }
}
