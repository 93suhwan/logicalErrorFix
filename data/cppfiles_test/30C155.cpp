#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T &x, const T &y) {
  return (x < y) ? (x = y, true) : false;
};
template <typename T>
bool chmin(T &x, const T &y) {
  return (x > y) ? (x = y, true) : false;
};
constexpr long long int MOD = 998244353;
constexpr long long int INF = 2e18;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = n - 1;
    char a = '0', b;
    while (x < y) {
      if (s[x] != s[y]) {
        a = s[x], b = s[y];
        break;
      }
      x++, y--;
    }
    if (a == '0')
      cout << a << endl;
    else {
      long long int ans = INF;
      long long int cnt = 0;
      x = 0, y = n - 1;
      while (x < y) {
        if (s[x] != s[y]) {
          if (s[x] == a)
            x++;
          else if (s[y] == a)
            y--;
          else {
            cnt = INF;
            break;
          }
          cnt++;
        } else
          x++, y--;
      }
      chmin(ans, cnt);
      cnt = 0;
      x = 0, y = n - 1;
      while (x < y) {
        if (s[x] != s[y]) {
          if (s[x] == b)
            x++;
          else if (s[y] == b)
            y--;
          else {
            cnt = INF;
            break;
          }
          cnt++;
        } else
          x++, y--;
      }
      chmin(ans, cnt);
      if (ans == INF)
        cout << -1 << endl;
      else
        cout << ans << endl;
    }
  }
  return 0;
}
