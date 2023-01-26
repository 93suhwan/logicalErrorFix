#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, q;
int cnt[M];
string ss;
void solve() {
  cin >> n >> q;
  cin >> ss;
  for (int i = 1; i <= n; i++) {
    if (i % 2)
      cnt[i] = ss[i - 1] == '+' ? 1 : -1;
    else
      cnt[i] = ss[i - 1] == '-' ? 1 : -1;
    cnt[i] += cnt[i - 1];
  }
  int l, r;
  while (q--) {
    cin >> l >> r;
    int ans = cnt[r] - cnt[l - 1];
    if (ans == 0)
      cout << 0 << endl;
    else
      cout << 2 - ans % 2 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
