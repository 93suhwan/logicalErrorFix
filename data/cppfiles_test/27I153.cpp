#include <bits/stdc++.h>
using namespace std;
void want() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (m == 0) {
    if (m < k - 1) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  double ans = 2 * m - (2 * n) + 2.25;
  ans = sqrt(ans);
  ans += 0.5;
  long long res = int(ans);
  res = n - res;
  if (res < k - 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    want();
  }
}
