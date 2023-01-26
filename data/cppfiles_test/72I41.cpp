#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const int N = 1e9;
int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int o;
  cin >> o;
  return o;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long p = query(1, 1);
  int l = 2, r = N;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (query(1, m) == p - m + 1) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  int fx = ans, fy = p - ans;
  int q = query(1, N);
  int sx = q - fy, ss = fy;
  int lp = query(N, N);
  int tx = sx, ty = lp - tx;
  cout << "! " << fx << " " << fy << " " << tx << " " << ty << endl;
  return 0;
}
