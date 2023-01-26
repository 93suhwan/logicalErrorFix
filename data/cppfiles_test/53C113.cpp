#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9 + 7;
int a[maxn], b[maxn], c[maxn];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i], b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
      c[i] = lower_bound(b + 1, b + n + 1, a[i]) - (b + 1);
    int ans = 0;
    c[0] = -inf;
    for (int i = 1; i <= n; i++) {
      if (c[i] - c[i - 1] != 1) ans++;
    }
    if (ans <= k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
