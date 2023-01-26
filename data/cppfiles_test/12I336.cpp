#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int m, k, l;
    cin >> m >> k >> l;
    long long u = 1ll * k * m / 2;
    if (m % 2 == 0) {
      if (l % 2 == 1 || l > (1ll * (k / 2) * m) ||
          l < u - (1ll * (m / 2) * k)) {
        cout << "NO";
      } else {
        cout << "YES";
      }
    } else if (m % 2 == 1) {
      if (l > (1ll * (k / 2) * m) || l < u - (1ll * (m / 2) * k) ||
          l % 2 == 0) {
        cout << "NO";
      } else {
        cout << "YES";
      }
    }
    cout << endl;
  }
}
