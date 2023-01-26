#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
int a[N], b[N], c[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int s1, s2;
    s1 = s2 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) b[++s1] = i;
      if (a[i] > n) c[++s2] = a[i];
    }
    if (!s1)
      cout << 0 << "\n";
    else {
      bool ok = true;
      for (int i = 1; i <= s1; i++)
        if (c[i] - b[i] <= b[i]) {
          ok = false;
          break;
        }
      if (ok)
        cout << s1 << "\n";
      else
        cout << "-1\n";
    }
  }
}
