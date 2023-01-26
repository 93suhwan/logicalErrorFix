#include <bits/stdc++.h>
const long long int mrx = 1e6 + 5, M = 1e9 + 7, dm = 1e3 + 5;
long long int mx = -1e18, mn = 1e18;
int T = 1;
using namespace std;
void solve() {
  long long int x0, n;
  cin >> x0 >> n;
  if (n == 0) {
    cout << x0;
    return;
  } else if (x0 % 2 == 0 && n % 2 == 0) {
    if (n % 4 == 0) {
      cout << x0;
      return;
    } else {
      x0 += 1;
      cout << x0;
      return;
    }
  } else if (x0 % 2 == 0 && n % 2 != 0) {
    if ((n - 1) % 4 == 0) {
      x0 -= n;
      cout << x0;
      return;
    } else {
      x0 += n + 1;
      cout << x0;
      return;
    }
  } else if (x0 % 2 != 0 && n % 2 == 0) {
    if (n % 4 == 0) {
      cout << x0;
      return;
    } else {
      x0 -= 1;
      cout << x0;
      return;
    }
  } else if (x0 % 2 != 0 && n % 2 != 0) {
    if ((n - 1) % 4 == 0) {
      x0 += n;
      cout << x0;
      return;
    } else {
      x0 -= n;
      x0--;
      cout << x0;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL), cout.tie(NULL);
  cin >> T;
  while (T--) {
    solve();
    if (T != 0) {
      cout << "\n";
    }
  }
  return 0;
}
