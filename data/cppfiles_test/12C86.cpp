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
    if (k == 0) {
      if (n % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (n % 2 == 0 && m % 2 == 0) {
        if (k % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else if (n % 2 != 0 && m % 2 == 0) {
        int u = m / 2;
        if (k > n * m) {
          cout << "NO\n";
        } else {
          int x = 0;
          for (int i = u; i > 0; --i) {
            int h = u - i;
            for (int j = 1; j * i <= k; ++j) {
              if (h != 0) {
                if ((k - (j * i)) % h == 0 && ((k - (j * i)) / h) % 2 != 0 &&
                    j % 2 != 0 && j <= n && ((k - (j * i)) / h) <= n) {
                  x = 1;
                  j = k;
                  i = -1;
                  break;
                }
              } else {
                if (j <= n && j * i == k && j % 2 != 0) {
                  x = 1;
                  j = k;
                  i = -1;
                  break;
                }
              }
            }
          }
          if (x == 1) {
            cout << "YES\n";
          } else {
            cout << "NO\n";
          }
        }
      } else if (n % 2 == 0 && m % 2 != 0) {
        int u = (m - 1) / 2;
        if (k > u * n) {
          cout << "NO\n";
        } else if (k == u * n) {
          cout << "YES\n";
        } else {
          int x = 0;
          for (int i = u; i > 0; --i) {
            int h = u - i;
            for (int j = 1; i * j <= k; ++j) {
              if (h != 0) {
                if ((k - (i * j)) % h == 0 && ((k - (i * j)) / h) % 2 == 0 &&
                    j % 2 == 0 && j <= n && (k - (i * j) / h && h != 0) <= n) {
                  x = 1;
                  i = -1;
                  j = k;
                  break;
                }
              } else {
                if (i * j == k && j % 2 == 0) {
                  x = 1;
                  j = k;
                  i = -1;
                  break;
                }
              }
            }
          }
          if (x == 1) {
            cout << "YES\n";
          } else {
            cout << "NO\n";
          }
        }
      } else {
        cout << "NO\n";
      }
    }
  }
}
