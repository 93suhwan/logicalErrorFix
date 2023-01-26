#include <bits/stdc++.h>
using namespace std;
int t, n, a[102], d[20004];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i * i <= 20000; i++)
    if (d[i] == 0)
      for (int j = i * i; j <= 20000; j += i) d[j] = 1;
  d[0] = d[1] = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    int s = 0, pos = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2) pos = i;
      s += a[i];
    }
    if (d[s] == 1) {
      cout << n;
      cout << "\n";
      for (int i = 1; i <= n; ++i) cout << i << ' ';
      cout << "\n";
    } else {
      cout << n - 1;
      cout << "\n";
      for (int i = 1; i <= n; ++i)
        if (i != pos) cout << i << ' ';
      cout << "\n";
    }
  }
  return 0;
}
