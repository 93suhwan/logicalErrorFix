#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n], b[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    int cnt = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == b[i])
        continue;
      else
        break;
    }
    if (i == n)
      cout << cnt << '\n';
    else {
      while (true) {
        for (i = cnt % 2 == 1 ? 1 : 0; i < n - 1;) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            i += 2;
          } else
            i++;
        }
        cnt++;
        for (i = 0; i < n; i++) {
          if (a[i] == b[i])
            continue;
          else
            break;
        }
        if (i == n) break;
      }
      cout << cnt << '\n';
    }
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << '\n';
  return 0;
}
