#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    if (abs(a - b) > 1)
      cout << "-1\n";
    else {
      if (a > b) {
        if (n % 2 == 0) {
          if (a + b > n - 3)
            cout << "-1\n";
          else {
            for (int i = n - 1; i > 0 && a > 0; i -= 2) {
              swap(v[i], v[i - 1]);
              a--;
            }
            for (auto x : v) cout << x << " ";
            cout << endl;
          }
        } else {
          if (a + b > n - 2)
            cout << "-1\n";
          else {
            for (int i = n - 1; i > 0 && a > 0; i -= 2) {
              swap(v[i], v[i - 1]);
              a--;
            }
            for (auto x : v) cout << x << " ";
            cout << endl;
          }
        }
      } else if (a < b) {
        if (n % 2 == 0) {
          if (a + b > n - 3)
            cout << "-1\n";
          else {
            for (int i = 0; (i < n - 1) && (b > 0); i += 2) {
              swap(v[i], v[i + 1]);
              b--;
            }
            for (auto x : v) cout << x << " ";
            cout << endl;
          }
        } else {
          if (a + b > n - 2)
            cout << "-1\n";
          else {
            for (int i = 0; (i < n - 1) && (b > 0); i += 2) {
              swap(v[i], v[i + 1]);
              b--;
            }
            for (auto x : v) cout << x << " ";
            cout << endl;
          }
        }
      } else {
        if (a + b <= n - 2) {
          if (n % 2 == 0) {
            for (int i = 1; (i <= n / 2) && a > 0; i += 2) {
              swap(v[i], v[n - 1 - i]);
              a -= 2;
            }
            if (a > 0 && n % 2 == 0) {
              swap(v[n / 2 - 1], v[n / 2]);
            }
            for (auto x : v) cout << x << " ";
            cout << endl;
          } else {
            for (int i = 0; (i <= n / 2) && a > 0; i += 2) {
              swap(v[i], v[n - 1 - i]);
              a -= 2;
            }
            if (a > 0) {
              swap(v[n / 2 - 1], v[n / 2]);
            }
            for (auto x : v) cout << x << " ";
            cout << endl;
          }
        } else
          cout << "-1\n";
      }
    }
  }
  return 0;
}
