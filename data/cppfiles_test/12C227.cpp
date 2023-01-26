#include <bits/stdc++.h>
using namespace std;
bool fun(int n, int m, int k) {
  if (m / 2 > k)
    return false;
  else {
    k -= m / 2;
    if (k % 2 == 0)
      return true;
    else
      return false;
  }
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    if (n % 2 != 0) {
      if (fun(n, m, k))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (fun(m, n, n * m / 2 - k))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
