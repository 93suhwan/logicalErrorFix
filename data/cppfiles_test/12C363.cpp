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
    long long u = 1ll * m * k / 2;
    long long o = 1ll * (k / 2) * m;
    long long a = 1ll * (m / 2) * k;
    if (l > o || l < u - a) {
      cout << "NO";
    } else if (m % 2 == 0) {
      a = u - l;
      if (k % 2 == 0) {
        if (l % 2 == 0) {
          cout << "YES";
        } else {
          cout << "NO";
        }
      } else {
        if (l % 2 == 0) {
          cout << "YES";
        } else {
          if (a >= m / 2 && (a - (m / 2) % 2 == 0)) {
            cout << "YES";
          } else {
            cout << "NO";
          }
        }
      }
    } else {
      a = u - l;
      if (a % 2 == 0) {
        cout << "YES";
      } else {
        if (l >= k / 2 && (l - k / 2) % 2 == 0) {
          cout << "YES";
        } else {
          cout << "NO";
        }
      }
    }
    cout << "\n";
  }
}
