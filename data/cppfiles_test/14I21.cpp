#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
int t;
int n;
int a[maxn];
int b[maxn];
int l[maxn], r[maxn], d[maxn];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int k = 0;
    int lt = 0, rt = 0, dt = 0;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != b[i]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << 0 << endl;
      puts(" ");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (a[j] == b[i] && i != j) {
          lt = i, rt = j, dt = rt - lt;
          ++k;
          l[k] = lt, r[k] = rt, d[k] = dt;
        } else if (a[j] == b[i] && i == j)
          break;
      }
    }
    cout << k << endl;
    for (int i = 1; i <= k; ++i) {
      cout << l[i] << " " << r[i] << " " << d[i] << endl;
    }
  }
  return 0;
}
