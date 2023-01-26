#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    char a[2][n];
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    bool b = 0;
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < n; j++) {
        if (i == 0) {
          if (a[i + 1][j] == '1' && a[i][j + 1] == '1' &&
              a[i + 1][j + 1] == '1') {
            b = 1;
            break;
          }
        } else {
          if (a[i - 1][j] == '1' && a[i][j + 1] == '1' &&
              a[i - 1][j + 1] == '1') {
            b = 1;
            break;
          }
        }
      }
    }
    if (b) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
