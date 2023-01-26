#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 1e9;
int ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int n;
  cin >> n;
  return n;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  bool left = false;
  int lo = 1;
  int hi = min(N, ask(1, 1)), mx = hi, last = mx;
  while (hi - lo > 1) {
    int dist;
    if (!left) {
      dist = ask(1, hi);
      if (dist == mx) {
        break;
      } else {
        lo = max(hi - dist, 1);
      }
    } else {
      dist = ask(1, lo);
      if (dist == mx) {
        break;
      } else {
        hi = min(N, lo + dist);
      }
    }
    left = !left;
    mx = dist;
  }
  int mid = (lo + hi) / 2;
  int low_x = ask(1, mid) + 1;
  int low_y = last - (low_x - 1) + 1;
  int high_y = N - (ask(1, N) - (low_x - 1));
  int high_x = N - ask(N, high_y);
  cout << "! " << low_x << " " << low_y << " " << high_x << " " << high_y
       << endl;
}
