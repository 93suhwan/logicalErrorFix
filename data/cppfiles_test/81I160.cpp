#include <bits/stdc++.h>
using namespace std;
int a[3 * 100000 + 5];
int f[3 * 100000 + 5];
int T, n, q;
int l, r;
int sum;
void realmain() {
  cin >> l >> r;
  sum = 0;
  for (int i = l; i <= r; i++) {
    if ((i - l + 1) % 2 == 1) {
      sum += 1 * a[i];
    } else {
      sum += -1 * a[i];
    }
  }
  if (sum == 0) {
    cout << 0 << endl;
    return;
  }
  memset(f, 0, n + 1);
  for (int i = l; i <= r; i++) {
    if (i - l + 1 % 2 == 1) {
      f[i] = f[i - 1] + a[i] * 1;
    } else {
      f[i] = f[i - 1] + a[i] * (-1);
    }
  }
  for (int j = r; j >= l; j--) {
    if (sum + (-2) * (f[r] - f[j]) - a[j] == 0) {
      cout << 1 << endl;
      return;
    }
  }
  cout << 2 << endl;
  return;
}
void _method() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    char w;
    cin >> w;
    if (w == '+') {
      a[i] = 1;
    } else {
      a[i] = -1;
    }
  }
  for (int i = 1; i <= q; i++) {
    realmain();
  }
  return;
}
int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    _method();
  }
  return 0;
}
