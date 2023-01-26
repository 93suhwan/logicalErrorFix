#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9 + 9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (k == 0) {
      if (n % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (m == 1) {
      if (k == 0 && (n % 2) == 0) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    } else {
      if (n % 2 == 1) {
        if (m % 2 == 0) {
          k -= m / 2;
          n -= 1;
          long long actc[n + 2];
          for (long long i = 0; i < (n); ++i) {
            actc[i] = m;
          }
          long long act = 0;
          while (k > 0) {
            long long kantes = k;
            if (actc[act] >= 2) actc[act] -= 2;
            k--;
            act++;
            if (k == kantes) break;
            if (act == n) act = 0;
          }
          if (k == 0 && act % 2 == 0) {
            cout << "YES\n";
          } else {
            cout << "NO\n";
          }
        } else {
          cout << "NO\n";
        }
      } else {
        long long actc[n + 2];
        for (long long i = 0; i < (n); ++i) {
          actc[i] = m;
        }
        long long act = 0;
        while (k > 0) {
          long long kantes = k;
          if (actc[act] >= 2) actc[act] -= 2;
          k--;
          act++;
          if (k == kantes) break;
          if (act == n) act = 0;
        }
        if (k == 0 && act % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
  return 0;
}
