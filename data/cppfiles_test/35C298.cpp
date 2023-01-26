#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
bool checkbit(int mask, int bit) { return (mask & (1 << bit)); }
int setbit(int mask, int bit) { return (mask | (1 << bit)); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = 2e9, now = 0;
    for (int bit = 29; bit >= 0; bit--) {
      if (!checkbit(m, bit)) {
        int cur = now;
        if (!checkbit(n, bit)) {
          cur = setbit(cur, bit);
          ans = min(ans, cur);
        } else {
          ans = min(ans, cur);
          now = setbit(now, bit);
        }
      } else {
        if (!checkbit(n, bit)) {
          now = setbit(now, bit);
        }
      }
    }
    cout << ans << endl;
  }
}
