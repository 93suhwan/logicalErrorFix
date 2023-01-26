#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m == n - 1 && n == 1) {
      if (k > 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (m == n - 1 && n != 1) {
      if (k > 3)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (m < n - 1) {
      if (k > 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (m > n - 1) {
      if (m < 2 * (n - 1)) {
        if (k > 3)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
      long long int temp = n - 4;
      long long int val = 2 * (n - 1) + temp + (temp * (temp + 1)) / 2;
      if (n == 4 && m == 2 * (n - 1)) {
        if (k > 2)
          cout << "YES\n";
        else
          cout << "NO\n";
      } else {
        if (m < val && m >= 2 * (n - 1)) {
          if (k > 3)
            cout << "YES\n";
          else
            cout << "NO\n";
        }
        if (m >= val) {
          if (k > 2)
            cout << "YES\n";
          else
            cout << "NO\n";
        }
      }
    }
  }
}
