#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;
char s[300005];
int main() {
  i32 t, n, q;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin >> s + 1;
    vector<i32> sum(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
      if (s[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
    for (int i = 1; i <= n; i++)
      if (i % 2 == 0) a[i] *= (-1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= q; i++) {
      i32 l, r;
      cin >> l >> r;
      l--;
      if ((sum[r] - sum[l]) % 2)
        cout << 1 << endl;
      else if (sum[r] == sum[l])
        cout << 0 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
