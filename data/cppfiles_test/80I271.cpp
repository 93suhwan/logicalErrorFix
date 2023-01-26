#include <bits/stdc++.h>
using namespace std;
long long T, n, ok;
char a[200001];
signed main() {
  cin >> T;
  for (long long scy = 1; scy <= T; scy++) {
    cin >> n;
    getchar();
    gets(a);
    ok = 0;
    for (long long i = 0; i < n / 2; i++) {
      if (a[i] == '0') {
        ok = 1;
        cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
        break;
      }
    }
    if (ok == 0) {
      for (long long i = n - 1; i >= n / 2; i--) {
        if (a[i] == '0') {
          ok = 1;
          cout << 1 << " " << i + 1 << " " << 1 << " " << i + 2 << endl;
          break;
        }
      }
    }
  }
}
