#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int t, n, q, l, r, f[N];
vector<int> p[N << 1];
string s;
int solve(int res) {
  int sum = f[l - 1] + (res - 1) / 2;
  int u = 0, v = p[sum + n].size() - 1, pos = -1;
  while (u <= v) {
    int mid = u + v >> 1;
    if (p[sum + n][mid] < r) {
      pos = p[sum + n][mid];
      u = mid + 1;
    } else
      v = mid - 1;
  }
  if (pos != -1) return pos + 1;
  sum = f[l - 1] + (res + 1) / 2;
  u = 0, v = p[sum + n].size() - 1, pos = -1;
  while (u <= v) {
    int mid = u + v >> 1;
    if (p[sum + n][mid] < r) {
      pos = p[sum + n][mid];
      u = mid + 1;
    } else
      v = mid - 1;
  }
  if (pos != -1) return pos + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    f[0] = 0;
    for (int i = 0; i <= 2 * n; ++i) p[i].clear();
    for (int i = 1; i <= n; ++i) {
      f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * (i & 1 ? 1 : -1);
      p[f[i] + n].push_back(i);
    }
    while (q--) {
      cin >> l >> r;
      int res = f[r] - f[l - 1];
      if (res == 0)
        cout << 0 << '\n';
      else {
        if (res & 1)
          cout << 1 << '\n';
        else
          cout << 2 << '\n';
        if (abs(res) % 2 == 0) {
          cout << l << ' ';
          l++;
        }
        res = f[r] - f[l - 1];
        cout << solve(res) << '\n';
      }
    }
  }
}
