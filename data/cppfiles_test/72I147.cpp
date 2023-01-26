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
  int lo = 1;
  int hi = N;
  int left = ask(1, lo);
  int right = ask(1, hi);
  int mnx = 0;
  while (lo < hi) {
    int m = (lo + hi) / 2;
    int mid = ask(1, m);
    if (left == mid && right == mid) {
      mnx = m;
      break;
    } else if (left > right) {
      lo = m;
      left = mid;
    } else {
      hi = m;
      right = mid;
    }
  }
  if (!mnx) mnx = min(left, right);
  mnx++;
  int mny = ask(1, 1) - (mnx - 1) + 1;
  int mxy = N - (ask(1, N) - (mnx - 1));
  int mxx = N - ask(N, mxy);
  cout << "! " << mnx << " " << mny << " " << mxx << " " << mxy << endl;
}
