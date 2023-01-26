#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int *b = new int[n + 1];
    memset(b, 0, sizeof(int) * (n + 1));
    for (int i = 1; i + 1 <= n; i += 2) {
      b[i] = -a[i + 1];
      b[i + 1] = a[i];
    }
    if (n % 2 == 1) {
      if (b[n - 1] - a[n] == 0)
        b[n] += -a[n - 1], b[n - 1] += a[n];
      else
        b[n] += a[n - 1], b[n - 1] += -a[n];
    }
    delete[] a;
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
    delete[] b;
  }
  return 0;
}
