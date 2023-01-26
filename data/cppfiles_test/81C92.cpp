#include <bits/stdc++.h>
using namespace std;
char s[300005];
int sum[300005];
int n, q, l, r;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q >> s + 1;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1];
      sum[i] += (s[i] == '-' ? -1 : 1) * (i % 2 ? 1 : -1);
    }
    while (q--) {
      cin >> l >> r;
      if (sum[l - 1] == sum[r])
        cout << 0 << endl;
      else if (abs(sum[r] - sum[l - 1]) == 1)
        cout << 1 << endl;
      else if (abs(sum[r] - sum[l - 1]) % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
