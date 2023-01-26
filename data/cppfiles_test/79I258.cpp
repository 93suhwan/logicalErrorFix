#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
using namespace std;
bool is_prime(int n) {
  if (n == 1) {
    return false;
  }
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  char a[n];
  cin >> a;
  int flag = 0;
  int i;
  int x;
  for (i = 0; i < n; i++) {
    x = (int)a[i] - 48;
    if ((x % 2 == 0 && x != 2) || (x == 9) | (x == 1)) {
      flag = -1;
      break;
    }
  }
  if (flag == -1) {
    cout << "1\n";
    cout << x;
  } else {
    char b[n];
    strcpy(b, a);
    sort(b, b + n);
    int i;
    for (i = 1; i < n; i++) {
      if (b[i] == b[i - 1]) {
        flag = -1;
        break;
      }
    }
    if (flag == -1) {
      cout << "2\n";
      cout << b[i] << b[i - 1];
    } else {
      int j;
      for (i = 0; i < n; i++) {
        if (a[i] == '2') {
          for (j = i + 1; j < n; j++) {
            if (a[j] == '5' || a[j] == '7') {
              cout << "2\n";
              cout << a[i] << a[j];
              flag = -1;
            }
          }
          if (flag == -1) break;
        } else if (a[i] == '3') {
          for (j = i + 1; j < n; j++) {
            if (a[j] == '5' || a[j] == '2') {
              cout << "2\n";
              cout << a[i] << a[j];
              flag = -1;
            }
          }
          if (flag == -1) break;
        } else if (a[i] == '5') {
          for (j = i + 1; j < n; j++) {
            if (a[j] == '2') {
              cout << "2\n";
              cout << a[i] << a[j];
              flag = -1;
            }
          }
          if (flag == -1) break;
        } else {
          for (j = i + 1; j < n; j++) {
            if (a[j] == '2' || a[j] == '5') {
              cout << "2\n";
              cout << a[i] << a[j];
              flag = -1;
            }
          }
          if (flag == -1) break;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
