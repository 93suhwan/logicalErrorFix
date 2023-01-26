#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t, n, m, k;
  cin >> t;
  bool flag;
  while (t--) {
    cin >> n >> m >> k;
    k -= 2;
    flag = 1;
    if (m < n - 1) {
      cout << "NO" << endl;
      continue;
    } else if ((n == 1 && m == 0) || k >= 2) {
      cout << "YES" << endl;
      continue;
    }
    if (k == 1) {
      if (m < n * (n - 1) / 2)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
