#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, y = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * y;
}
int t;
long long k = 1;
int n;
int a[105];
int main() {
  cin >> t;
  while (t--) {
    k = 1;
    cin >> n >> a[1];
    if (a[1] == 1) {
      k++;
    } else
      k += 0;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      if (a[i - 1] == 0 && a[i] == 0) {
        k = -1;
        break;
      }
      if (a[i - 1] == 1 && a[i] == 1) {
        k += 5;
        continue;
      }
      if (a[i - 1] == 0 && a[i] == 1) {
        k += 1;
      }
    }
    cout << k << endl;
  }
  return 0;
}
