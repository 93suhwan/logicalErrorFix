#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template <class T>
void in(T& x) {
  cin >> x;
}
template <class H, class... T>
void in(H& h, T&... t) {
  in(h);
  in(t...);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int T = 1;
  in(T);
  while (T--) {
    long long int n;
    in(n);
    vector<long long int> v(n + 1);
    vector<char> color(n + 1);
    bool can = true;
    for (long long int i = 1; i <= n; ++i) {
      in(v[i]);
    }
    for (long long int i = 1; i <= n; ++i) {
      in(color[i]);
    }
    long long int b1 = 0;
    long long int rn = 0;
    for (long long int i = 1; i <= n; ++i) {
      if (v[i] == 1 && color[i] == 'B') {
        b1++;
      }
      if (v[i] == n && color[i] == 'R') {
        rn++;
      }
      if (v[i] < 1 && color[i] == 'B') {
        can = false;
      }
      if (v[i] > n && color[i] == 'R') {
        can = false;
      }
    }
    if (rn >= 2 || b1 >= 2) {
      can = false;
    }
    cout << (can ? "YES\n" : "NO\n");
  }
  return 0;
}
