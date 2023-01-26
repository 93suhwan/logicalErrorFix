#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
const int bit = 31;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  int res = abs(a - b) * 2;
  if (a > res or b > res or c > res) {
    cout << -1 << endl;
    return;
  }
  long long ans = c + res / 2;
  if (ans > res) {
    ans = c - res / 2;
  }
  cout << ans << endl;
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
