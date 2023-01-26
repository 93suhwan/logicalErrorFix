#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int a = 0, b = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        a++;
      } else {
        b++;
      }
    }
    if (a == 0 || b == 0) {
      cout << "-1 -1" << endl;
    } else if (a == b) {
      cout << 1 << " " << n << endl;
    } else if (a > b) {
      long long int l = 0, r = n - 1;
      if (s[0] == 'a') {
        cout << l + 1 << " " << r + 1 << endl;
      } else if (s[r] == 'a') {
        cout << l + 1 << " " << r << endl;
      } else {
        while (l < r) {
          if (s[l] == 'b') {
            l++;
          } else {
            cout << l + 1 << " " << r << endl;
            break;
          }
        }
      }
    } else {
      long long int l = 0, r = n - 1;
      if (s[0] == 'b') {
        cout << l + 1 << " " << r + 1 << endl;
      } else if (s[r] == 'b') {
        cout << l + 1 << " " << r << endl;
      } else {
        while (l < r) {
          if (s[l] == 'a') {
            l++;
          } else {
            cout << l + 1 << " " << r << endl;
            break;
          }
        }
      }
    }
  }
  return 0;
}
