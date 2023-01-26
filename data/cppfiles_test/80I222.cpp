#include <bits/stdc++.h>
using namespace std;
long long T, n, ok, st, num;
char a[200001];
void tp() {
  num = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '0')
      num++;
    else {
      if (num >= n / 2) {
        cout << st + 1 << " " << i << " " << 1 << " " << n << endl;
        ok = 1;
        return;
      }
      st = i + 1;
      num = 0;
    }
  }
  if (num >= n / 2) {
    cout << st + 1 << " " << n << " " << 1 << " " << n << endl;
    ok = 1;
    return;
  }
}
signed main() {
  cin >> T;
  for (long long scy = 1; scy <= T; scy++) {
    cin >> n;
    getchar();
    gets(a);
    ok = 0;
    tp();
    if (ok == 0)
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
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
          break;
        }
      }
    }
    if (ok == 0) {
      cout << 1 << " " << (n / 2) * 2 << " " << 1 << " " << n / 2 << endl;
    }
  }
}
