#include <bits/stdc++.h>
using namespace std;
ifstream f("pirati.in");
ofstream g("pirati.out");
int v[200005];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int x1 = 0, x2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      if (v[i] % 2 == 0) {
        x1++;
      } else
        x2++;
    }
    if (abs(x1 - x2) > 1) {
      cout << -1 << '\n';
      continue;
    }
    if (n % 2 == 0) {
      int cnt = 2;
      long long rez = 0, rez2 = 0;
      for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == 0) {
          rez += (abs(i - cnt));
          cnt += 2;
        }
      }
      cnt = 1;
      for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == 0) {
          rez2 += (abs(i - cnt));
          cnt += 2;
        }
      }
      cout << min(rez, rez2) << '\n';
    } else {
      if (x1 > x2) {
        int cnt = 1;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
          if (v[i] % 2 == 0) {
            ans += abs(i - cnt);
            cnt += 2;
          }
        }
        cout << ans << '\n';
      } else {
        int cnt = 1;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
          if (v[i] % 2 == 1) {
            ans += abs(i - cnt);
            cnt += 2;
          }
        }
        cout << ans << '\n';
      }
    }
  }
}
