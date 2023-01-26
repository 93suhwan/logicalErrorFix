#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[200005];
bool f[1000005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0;
    cin >> n;
    memset(f, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (f[a[i] % a[j]] == 0) {
          cout << a[i] << " " << a[j] << endl;
          s++;
        } else if (f[a[j] % a[i]] == 0) {
          cout << a[j] << " " << a[i] << endl;
          s++;
        }
        if (s == n / 2) {
          goto gt;
        }
      }
    }
  gt:;
  }
}
