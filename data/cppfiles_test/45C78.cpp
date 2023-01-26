#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> v(n);
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] % 2) {
        o++;
      } else {
        e++;
      }
    }
    int parity, j = 0;
    long long ans = 0;
    if (n % 2) {
      if (abs(e - o) == 1) {
        parity = (e > o ? 0 : 1);
        for (int i = 0; i < n; i++) {
          if (v[i] % 2 == parity) {
            ans += abs(j - i);
            j += 2;
          }
        }
        cout << ans << '\n';
      } else {
        cout << -1 << '\n';
      }
    } else {
      if (abs(e - o) == 0) {
        long long ans2 = 0;
        int jj = 0;
        parity = 1;
        for (int i = 0; i < n; i++) {
          if (v[i] % 2 == parity) {
            ans += abs(j - i);
            j += 2;
          } else {
            ans2 += abs(jj - i);
            jj += 2;
          }
        }
        cout << min(ans, ans2) << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}
