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
    for (int i = 2; i <= n; i++) {
      if (b[i - 1] - a[i] == 0)
        b[i - 1] += a[i], b[i] += -a[i - 1];
      else
        b[i - 1] += -a[i], b[i] += a[i - 1];
    }
    delete[] a;
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
    delete[] b;
  }
  return 0;
}
