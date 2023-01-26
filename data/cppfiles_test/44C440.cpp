#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x = f ? -x : x;
}
inline void solve() {
  int T;
  cin >> T;
  while (T--) {
    long long c, d;
    cin >> c >> d;
    long long dif = abs(c - d);
    if (dif & 1) {
      cout << -1 << endl;
    } else {
      if (c == 0 && d == 0) {
        cout << 0 << endl;
      } else if (c == d) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
}
