#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e6;
int solve(int a, int b, int c) {
  if (b < a) swap(a, b);
  int dis = b - a;
  int statr = 1;
  int all = dis * 2;
  int res = 0;
  if (a - dis >= 1 || c > 2 * dis) return -1;
  if (c > dis) res = c - dis;
  if (c <= dis) res = c + dis;
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
  }
  return 0;
}
