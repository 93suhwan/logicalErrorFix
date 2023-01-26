#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 3e5 + 10, M = 2e6 + 10, E = 1e3 + 10, md = 1e9 + 7;
const double PI = acos(-1), eps = 1e-8;
int T, n, m;
int f[N], pre[N];
int main() {
  cin >> T;
  cin.tie(0);
  cout.tie(0);
  while (T--) {
    string p;
    cin >> n >> m;
    cin >> p;
    int j;
    for (int i = (0); i < (n); i++) {
      j = i + 1;
      if (i & 1) {
        f[j] = p[i] == '+' ? -1 : 1;
      } else {
        f[j] = p[i] == '+' ? 1 : -1;
      }
      pre[j] = pre[j - 1] + f[j];
    }
    int l, r, ans;
    for (int i = (1); i <= (m); i++) {
      cin >> l >> r;
      ans = pre[r] - pre[l - 1];
      if (ans < 0) ans = -ans;
      if (ans) {
        if (ans % 2 == 0) {
          cout << 2;
        } else {
          cout << 1;
        }
      } else {
        cout << 0;
      }
      putchar('\n');
    }
  }
}
