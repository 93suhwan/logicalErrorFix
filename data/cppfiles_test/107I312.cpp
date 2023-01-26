#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int T, n, a[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    int x, y;
    cin >> n >> x >> y;
    a[1] = 1, a[2] = n;
    for (int i = 3; i <= n; i++)
      if (i & 1)
        a[i] = a[i - 2] + 1;
      else
        a[i] = a[i - 2] - 1;
    int s1 = 0, s2 = 0;
    for (int i = 2; i < n; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) s1++;
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) s2++;
    }
    if (s1 >= x && s2 >= y) {
      for (int i = 1; i <= n; i++) cout << a[i] << ' ';
      cout << '\n';
    } else
      cout << "-1\n";
  }
  return 0;
}
