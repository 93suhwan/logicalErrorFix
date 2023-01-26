#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = 1e9 + 1, mod = 1e9 + 7;
void solve() {
  int n, ans = 0, match = 0, unmatch = 0, signa = 0, signb = 0;
  string stra, strb;
  cin >> n >> stra >> strb;
  if (stra == strb) {
    cout << "0"
         << "\n";
    return;
  }
  auto check = [&](string a, string b) {
    int count01 = 0, count10 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '0') count10++;
      if (a[i] == '0' && b[i] == '1') count01++;
    }
    if (count01 != count10) return inf;
    return count01 + count10;
  };
  auto change = [&](string a, string b, char ch) {
    int index = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == ch) {
        index = i;
        break;
      }
    }
    if (index == -1) return inf;
    for (int i = 0; i < n; i++) {
      if (i == index) continue;
      a[i] = (a[i] == '1') ? '0' : '1';
    }
    return check(a, b);
  };
  ans = check(stra, strb);
  ans = min(ans, 1 + change(stra, strb, '1'));
  ans = min(ans, 1 + change(stra, strb, '0'));
  ans = (ans == inf) ? -1 : ans;
  cout << ans << "\n";
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int32_t main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
