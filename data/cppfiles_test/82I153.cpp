#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 1e5 + 10;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1);
inline int lowbit(int x) { return x & (-x); }
inline void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = '#' + s;
  vector<int> pre(n + 1, 0);
  map<int, vector<int>> f;
  for (int i = 1; i <= n; i++) {
    int now = ((s[i] == '+') ^ (i & 1) ? 1 : -1);
    pre[i] = pre[i - 1] + now;
    f[pre[i] + pre[i - 1]].push_back(i);
  }
  while (m--) {
    int ll, rr;
    cin >> ll >> rr;
    int val = pre[rr] - pre[ll - 1];
    if (val == 0)
      cout << 0 << '\n';
    else {
      if (val & 1) {
        cout << 1 << '\n';
        int now = pre[rr] + pre[ll - 1];
        int l = 0, r = (int)f[now].size() - 1;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (f[now][mid] >= l && f[now][mid] <= r) {
            l = mid;
            break;
          } else {
            if (f[now][mid] < l)
              l = mid + 1;
            else
              r = mid - 1;
          }
        }
        cout << f[now][l] << '\n';
      } else {
        cout << 2 << '\n';
        if (rr - ll == 1)
          cout << ll << ' ' << rr << '\n';
        else {
          for (int i = ll; i < rr; i++) {
            int now = val + pre[i] + pre[i - 1];
            if (f[now].empty()) continue;
            int l = 0, r = (int)f[now].size() - 1;
            while (l < r) {
              int mid = (l + r) >> 1;
              if (f[now][mid] > i && f[now][mid] <= r) {
                l = mid;
                break;
              } else {
                if (f[now][mid] < l)
                  l = mid + 1;
                else
                  r = mid - 1;
              }
            }
            if (f[now][l] > i && f[now][l] <= rr) {
              cout << i << ' ' << f[now][l] << '\n';
              break;
            }
          }
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cout << fixed << setprecision(2);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
