#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1);
int solve(int x) {
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
int c[10], a[10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  a[0] = 1;
  for (int i = 1; i < 10; i++) a[i] = a[i - 1] * 10;
  while (t--) {
    int s, n;
    cin >> s >> n;
    int cnt = solve(s);
    memset(c, 0, sizeof(c));
    if (cnt >= n) {
      int p = 1;
      for (int i = 1; i < n; i++) {
        while (s % (p * 10) == 0) p *= 10;
        cout << p << ' ';
        s -= p;
      }
      cout << s << '\n';
    } else {
      int p = 0, lft = 0;
      while (s) {
        c[p] = s % 10;
        s /= 10;
        p++;
      }
      int sum = n - cnt;
      while (sum) {
        for (int i = 1; i < 10; i++) {
          if (c[i]) {
            if (sum > 9) {
              sum -= 9;
              c[i]--;
              c[i - 1] += 10;
            } else {
              c[i]--;
              c[i - 1] += sum;
              lft = (10 - sum) * a[i - 1];
              sum = 0;
            }
            break;
          }
        }
      }
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < c[i]; j++) cout << a[i] << ' ';
      }
      if (lft) cout << lft;
      cout << '\n';
    }
  }
}
