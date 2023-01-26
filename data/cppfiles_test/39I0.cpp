#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long a, b;
    cin >> a >> b;
    long long dis = w - x2;
    long long dist = h - y2;
    if (a <= x1 || b <= y1) {
      cout << 0 << endl;
      continue;
    }
    long long shift = 0;
    if (a > x1 && b > y1) {
      long long q = a - x1;
      long long p = b - y1;
      if (p < q) {
        if (dist >= p) {
          shift += p;
        } else if (dis >= q) {
          shift += q;
        } else {
          shift = -1;
        }
      } else if (q < p) {
        if (dis >= q) {
          shift += q;
        } else if (dist >= p) {
          shift += p;
        } else {
          shift = -1;
        }
      } else {
        if (dis >= q) {
          shift += q;
        } else if (dist >= p) {
          shift += p;
        } else
          shift = -1;
      }
      cout << shift << endl;
    }
  }
}
