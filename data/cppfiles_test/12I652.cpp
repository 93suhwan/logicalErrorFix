#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long INF = LLONG_MAX;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m < 1) {
      cout << "NO"
           << "\n";
    } else {
      if (n % 2 == 0 && m % 2 == 0) {
        cout << "YES\n";
      } else if (n % 2 != 0 && m % 2 == 0) {
        int u = m / 2;
        if (k % u != 0) {
          cout << "NO\n";
        } else {
          if ((n - (k / u)) % 2 != 0) {
            cout << "NO\n";
          } else {
            cout << "YES\n";
          }
        }
      } else {
        int u = m / 2;
        if (k > u * n) {
          cout << "NO\n";
        } else if ((n - (k / u)) % 2 != 0) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
      }
    }
  }
}
