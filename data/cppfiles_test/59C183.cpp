#include <bits/stdc++.h>
using namespace std;
void func() {
  long long n;
  cin >> n;
  long long arr[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  long long a = 0, b = 0, c = 0;
  for (long long i = 0; i < 5; i++) {
    for (long long j = i + 1; j < 5; j++) {
      a = 0;
      b = 0;
      c = 0;
      for (long long k = 0; k < n; k++) {
        if (arr[k][i] == 1) a++;
        if (arr[k][j] == 1) b++;
        if (arr[k][j] == 1 && arr[k][i] == 1) c++;
      }
      a -= c;
      b -= c;
      if (b <= n / 2 && a <= n / 2 && a + b + c == n) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
signed main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    func();
  }
  return 0;
}
