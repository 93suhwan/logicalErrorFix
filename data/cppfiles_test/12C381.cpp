#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
int dh[] = {-1, 0, 1, 0};
int dw[] = {0, 1, 0, -1};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      if (m % 2 == 0 and k % 2 == 0) {
        cout << "YES" << endl;
        continue;
      }
      if (m % 2 == 1) {
        if (k % 2 == 0 and k <= n * (m / 2)) {
          cout << "YES" << endl;
          continue;
        }
      }
    } else {
      if (k >= m / 2) {
        k -= m / 2;
        if (k % 2 == 0) {
          cout << "YES" << endl;
          continue;
        }
      }
    }
    cout << "NO" << endl;
  }
}
