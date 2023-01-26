#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  return (out << p.first << ' ' << p.second << endl);
}
const int INF = 1000000017;
const long long LLINF = 1000000000000000017LL;
const long double inf = 1.0 / 0.0;
const long double eps = 1e-10;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int c, d;
    cin >> c >> d;
    if (c == d) {
      if (c == 0) {
        cout << 0;
      } else {
        cout << 1;
      }
    } else if (abs(c - d) % 2 == 0) {
      cout << 2;
    } else {
      cout << -1;
    }
    cout << '\n';
  }
  return 0;
}
