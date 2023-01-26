#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
int A[MAXN], n, e, o;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    e = o = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
      if (A[i] & 1)
        o++;
      else
        e++;
    }
    long long ans0 = 0, ans1 = 0, bal = 0;
    for (int i = 1; i <= n; i++) {
      if (A[i] % 2 == 0)
        bal++;
      else
        bal--;
      if (i % 2 == 0) {
        ans0 += abs(bal);
        ans1 += abs(bal);
      } else {
        ans0 += abs(bal - 1);
        ans1 += abs(bal + 1);
      }
    }
    if (e == o)
      cout << min(ans0, ans1) / 2 << '\n';
    else if (e == o + 1)
      cout << ans0 / 2 << '\n';
    else if (o == e + 1)
      cout << ans1 / 2 << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
