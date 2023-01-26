#include <bits/stdc++.h>
using namespace std;
char a[300050];
int sum[300050];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q = 0, l, r, k;
    cin >> n >> q;
    cin >> (a + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] == '+')
        k = 1;
      else
        k = -1;
      if (i & 1)
        sum[i] = sum[i - 1] + k;
      else
        sum[i] = sum[i - 1] - k;
    }
    for (int i = 1; i <= q; i++) {
      cin >> l >> r;
      int s = sum[r] - sum[l - 1];
      if (s == 0)
        cout << 0 << endl;
      else if (s & 1)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
