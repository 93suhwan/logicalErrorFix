#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    string ans;
    cin >> n >> m >> k;
    int flag = (n * (n - 1)) / 2;
    if (m < n - 1)
      ans = "NO";
    else if (m == flag) {
      if (1 < (k - 1))
        ans = "YES";
      else
        ans = "NO";
    } else {
      if (2 < (k - 1))
        ans = "YES";
      else
        ans = "NO";
    }
    cout << ans << endl;
  }
  return 0;
}
