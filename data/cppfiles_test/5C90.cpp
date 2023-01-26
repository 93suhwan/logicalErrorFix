#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  long long n, ans = 0;
  cin >> t;
  string b;
  string a;
  for (int i = 0; i < t; i++) {
    ans = 0;
    cin >> n;
    cin >> a;
    cin >> b;
    if (a[0] == '1') {
      if (b[1] == '1') {
        b[1] = '0';
        a[0] = '2';
        ans++;
      }
    } else if (a[0] == '0') {
      if (b[0] == '1') {
        b[0] = '0';
        a[0] = '2';
        ans++;
      }
    }
    for (long long j = 1; j < n - 1; j++) {
      if (a[j] == '1') {
        if (b[j - 1] == '1') {
          b[j - 1] = '0';
          a[j] = '2';
          ans++;
        } else if (b[j + 1] == '1') {
          b[j + 1] = '0';
          a[j] = '2';
          ans++;
        }
      } else if (a[j] == '0') {
        if (b[j] == '1') {
          b[j] = '0';
          a[j] = '2';
          ans++;
        }
      }
    }
    if (a[n - 1] == '1') {
      if (b[n - 2] == '1') {
        b[n - 2] = '0';
        a[n - 1] = '2';
        ans++;
      }
    } else if (a[n - 1] == '0') {
      if (b[n - 1] == '1') {
        b[n - 1] = '0';
        a[n - 1] = '2';
        ans++;
      }
    }
    cout << ans << endl;
  }
}
