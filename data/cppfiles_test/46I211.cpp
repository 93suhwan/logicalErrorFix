#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
int n;
int c[1001];
pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.second || b.first > a.second) return {1, 0};
  return {max(a.first, b.first), min(a.second, b.second)};
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];
  signed long long ans = 0;
  int open;
  int close = 0;
  for (int i = 1; i <= n; i += 2) {
    open = close = 0;
    int ok = 1;
    for (int j = i + 1; j <= n; j++) {
      if (j & 1)
        open += c[j];
      else {
        int d = open - close;
        pair<int, int> use = intersect({1, c[j]}, {d + ok, d + c[i]});
        if (use.second >= use.first) ans += use.second - use.first + 1;
        close += c[j];
        ok = max(ok, close - open);
        if (ok > c[i]) break;
      }
    }
  }
  cout << ans << "\n";
}
