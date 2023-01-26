#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e3 + 5;
long long c[MAXN];
void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  if (n % 2 == 1) --n;
  bool flag = false;
  long long ans = 0;
  do {
    flag = false;
    int l = 0, r = 1;
    long long cnt = 0;
    while (l < n && r < n) {
      while (l < n && c[l] == 0) l += 2;
      while (r < n && c[r] == 0) r += 2;
      if (l >= n || r >= n) {
        flag = false;
        break;
      }
      if (c[l] > c[r]) {
        ans += (cnt + 1) * cnt / 2;
        cnt = 0;
        ++cnt;
        ans += c[r] - 1;
        c[l] -= c[r];
        c[r] = 0;
        flag = true;
      } else if (c[l] == c[r]) {
        ++cnt;
        ans += c[r] - 1;
        c[l] = c[r] = 0;
      } else {
        ++cnt;
        ans += c[l] - 1;
        ans += (cnt + 1) * cnt / 2;
        cnt = 0;
        c[r] -= c[l];
        c[l] = 0;
        flag = true;
      }
      l += 2;
      r += 2;
    }
    if (cnt > 0) {
      ans += (cnt + 1) * cnt / 2;
    }
  } while (flag);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    Solve();
  }
  return 0;
}
