#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  string s;
  cin >> s;
  int aconfirm = 0, avar = 0, aleft = 5, bconfirm = 0, bvar = 0, bleft = 5;
  int ans = 0;
  while (ans < 10) {
    if (ans & 1) {
      if (s[ans] == '1') {
        bconfirm++;
      } else if (s[ans] == '?') {
        bvar++;
      }
      bleft--;
    } else {
      if (s[ans] == '1') {
        aconfirm++;
      } else if (s[ans] == '?') {
        avar++;
      }
      aleft--;
    }
    ans++;
    if (aconfirm + avar > bconfirm + bleft ||
        bconfirm + bvar > aconfirm + aleft) {
      break;
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = clock();
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  double used = (double)(clock() - start);
  used = (used * 1000) / CLOCKS_PER_SEC;
  cerr << fixed << setprecision(2) << used << " ms" << endl;
  return 0;
}
