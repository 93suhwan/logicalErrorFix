#include <bits/stdc++.h>
using namespace std;
void code() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a + b > n - 2 or abs(a - b) > 1)
    cout << -1 << endl;
  else {
    if (a < b) {
      long long tp = a + b + 1;
      long long i = 1;
      long long j = a + b + 1;
      bool flag = 1;
      while (tp--) {
        if (flag) {
          cout << j << " ";
          j--;
          flag = 0;
        } else {
          cout << i << " ";
          i++;
          flag = 1;
        }
      }
      for (long long k = a + b + 2; k <= n; k++) {
        cout << k << " ";
      }
      cout << endl;
    } else if (a >= b) {
      long long tp = a + b + 1;
      long long i = n - tp + 1;
      long long j = n;
      bool flag = 1;
      for (long long k = 1; k < i; k++) {
        cout << k << " ";
      }
      while (tp--) {
        if (flag) {
          cout << j << " ";
          j--;
          flag = 0;
        } else {
          cout << i << " ";
          i++;
          flag = 1;
        }
      }
      cout << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) code();
}
