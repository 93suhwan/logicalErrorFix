#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int tot = a + b;
  vector<int> ans;
  for (int i = 0; i <= tot; i++) {
    int serve, br;
    if (i > tot - i) {
      br = min((tot + 1) / 2, i);
      serve = min(tot / 2, tot - i);
    } else {
      serve = min((tot + 1) / 2, (tot - i));
      br = min(tot / 2, i);
    }
    int diff1 = b - (serve + br);
    int diff2 = a - (serve + br);
    int mx = min(br, serve) * 2;
    if ((b && (diff1 % 2 == 0) && diff1 <= mx && b <= serve + br) ||
        (a && (diff2 % 2 == 0) && diff2 <= mx && a <= serve + br))
      ans.push_back(i);
  }
  cout << (int)ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
  if ((int)ans.size()) cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
