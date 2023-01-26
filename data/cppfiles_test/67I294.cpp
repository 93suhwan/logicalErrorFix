#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e6;
int solve(int a, int b, int c) {
  if (abs(a - b) <= 1) return -1;
  if (b < a) swap(a, b);
  int statr = 1;
  int mid = b - a + 1;
  int all = (mid - 1) * 2;
  int res = 0;
  if (b > all) return -1;
  if (c >= mid) res = c - mid + 1;
  if (c < mid) res = c - 1 + mid;
  if (res > 0 && res <= all) return res;
  return -1;
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
