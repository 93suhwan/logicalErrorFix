#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    bool ans;
    if (k < 3)
      ans = false;
    else if (k == 3) {
      if (m == (n * (n - 1) / 2))
        ans = true;
      else
        ans = false;
    } else {
      if ((m >= (n - 1)) && (m <= (n * (n - 1) / 2)))
        ans = true;
      else
        ans = false;
    }
    if (ans)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
